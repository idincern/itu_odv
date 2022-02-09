#! /usr/bin/env python

def twist2wheels(vx, vy, wz):
#    l = 0.28
#    r = 0.0762
#    w = 0.25
    
    l = 1
    r = 1
    w = 1
    '''H = np.array([[-1,   -1,  -l-w],
                  [1,  -1,  -l-w],
                  [-1,   1,  -l-w],
                  [1,  1, -l-w]]) / r '''
    #Kinematic Model of a Four Mecanum Wheeled Mobile Robot,Hamid Taheri,Bing Qiao,Nurallah Ghaeminezhad'a gore duzenlenip olusturulan ters kinematik matrisi:
    H = np.array([[1,   1,  l+w],
                  [1,  -1, -l-w],
                  [1,  -1,  l+w],
                  [1,   1, -l-w]]) / r
       
                  
    twist = np.array([vx, vy, wz])
    twist.shape = (3,1)
    u = np.dot(H, twist)
    return u.flatten().tolist()

import rospy, numpy as np
from std_msgs.msg import Float32MultiArray, Float32
from geometry_msgs.msg import Twist

rospy.init_node('cmd2wheel_vel', anonymous=True)

def callback(msg):
	
	vx=msg.linear.x
	vy=msg.linear.y
	wz=msg.angular.z
	
	print "vx",vx
	print "vy",vy
	print "wz",wz
	
	u = twist2wheels(vx, vy, wz)
	vels = Float32MultiArray(data=u)
	print "u=",u
	pub.publish(vels)
	pub1.publish(-u[0])#Montaja gore motor acisal donme yonunu saglamak icin negatif
	pub2.publish(u[1])
	pub3.publish(-u[2])#Montaja gore motor acisal donme yonunu saglamak icin negatif
	pub4.publish(u[3])
	
	#maxvala gore arduino kodunda map() fonksiyonunun limitlerini duzenle
	max_val = u[0]
	#Loop through the array    
	for i in range(0, len(u)):    
    		#Compare elements of array with max    
   		if(abs(u[i]) > abs(max_val)):   
       			max_val = u[i]    
       	print("Maxval:" + str(max_val))
       	print("-------")
           
	
#### definition of publisher/subscriber and services ###
pub = rospy.Publisher('wheel_vel', Float32MultiArray, queue_size=10)
pub1 = rospy.Publisher('/motor1', Float32, queue_size=10)
pub2 = rospy.Publisher('/motor2', Float32, queue_size=10)
pub3 = rospy.Publisher('/motor3', Float32, queue_size=10)
pub4 = rospy.Publisher('/motor4', Float32, queue_size=10)

rospy.Subscriber('/cmd_vel', Twist, callback)
rospy.spin()
