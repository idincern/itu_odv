#! /usr/bin/env python
#IDN
#This node creates the required motor PWM values for Arduino board and send the values to it to create the signals
def twist2wheels(vx, vy, wz):
    l_x = 0.5
    r = 1
    l_y = 0.5

    #Kinematic Model of the ITU_odv
    J = np.array([[1,  1,   l_x+l_y],
                  [1, -1,  -l_x-l_y],
                  [1, -1,   l_x+l_y],
                  [1,  1,  -l_x-l_y]])/r    
                   
    twist = np.array([vx, vy, wz])
    twist.shape = (3,1)
    
    u = np.dot(J, twist)
    return u.flatten().tolist()

import rospy, numpy as np
from std_msgs.msg import Int16, Int16MultiArray
from geometry_msgs.msg import Twist 
from itu_odv_navigation.msg import motorPWMs #int16[] custom message type is used for sending PWM values 

rospy.init_node('inverse_kinematics', anonymous=True)

vx=0
vy=0
wz=0

def callback(msg):
	global vx, vy, wz
	vx=msg.linear.x
	vy=msg.linear.y
	wz=msg.angular.z
	
def inv_kin_tf():
	global vx, vy, wz
	u = twist2wheels(vx, vy, wz)
	for i in range(0, len(u)):    
    		#Limit elements of u array with 1   
   		if((u[i]) > 1):   
       			u[i] = 1
       		if((u[i]) < -1):   
       			u[i] = -1
       			
       	u[0] = -u[0]#motor turning direction is reversed(mechanically)	
       	u[2] = -u[2]#motor turning direction is reversed(mechanically)		
       	
       	#Turning into PWM values
       	for i in range(0, len(u)):
       		u[i] = u[i]*101+127
       	
       	pub.publish(u)
        
        
print "Inv.Kin. Ready"       
	
#### definition of publisher/subscriber and services ###
pub = rospy.Publisher('/pwm_values', motorPWMs, queue_size=10)
rospy.Subscriber('/cmd_vel', Twist, callback)

while not rospy.is_shutdown():
    inv_kin_tf()
    rospy.sleep(0.1)


