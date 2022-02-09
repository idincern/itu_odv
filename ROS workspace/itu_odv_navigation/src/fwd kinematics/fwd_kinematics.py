#! /usr/bin/env python
#IDN
#This node subscribes to the topics which include motor RPM speeds published by arduino analog outputs
def wheels2twist(w1,w2,w3,w4):
    l_x = 0.33
    r = 0.0762*2
    l_y = 0.33
    d=1/(l_x+l_y)
    I_J = np.array([[ 1,       1,     1,     1 ],
                    [ 1,      -1,    -1,     1 ],
                    [1*d,    -1*d,   1*d,  -1*d]])*r/4    
                   
    motor_vels = np.array([w1, w2, w3, w4])
    motor_vels.shape = (4,1)
    tw = np.dot(I_J, motor_vels)
    
    return tw.flatten().tolist()
    
import rospy, numpy as np
from std_msgs.msg import Float32MultiArray,Int16MultiArray, Float32
from geometry_msgs.msg import Twist

rospy.init_node('fwd_kinematics', anonymous=True)

w = [0,0,0,0]

wheel_rpm=94 #just change this value, if you have changed the ESCON Studio motor speed parameters

kinematic_constant=3.14159*wheel_rpm/2/30/1000

#(-2V,2V) voltage values are turning into RPM- then twist values
def callback(msg):
	global w, kinematic_constant
	w[0]=msg.data[0]*kinematic_constant*-1 #motor turning direction is reversed(mechanically)	
	w[1]=msg.data[1]*kinematic_constant
	w[2]=msg.data[2]*kinematic_constant*-1 #motor turning direction is reversed(mechanically)	
	w[3]=msg.data[3]*kinematic_constant
	tw=wheels2twist(w[0],w[1],w[2],w[3])
	twists = Float32MultiArray(data=tw)
	pub.publish(twists)
		
print "Fw.Kin. Ready"          
	
#### definition of publisher/subscriber and services ###
pub = rospy.Publisher('/twist_speeds', Float32MultiArray, queue_size=10)
rospy.Subscriber('/motor_vel_fb', Int16MultiArray, callback)

rospy.spin()
