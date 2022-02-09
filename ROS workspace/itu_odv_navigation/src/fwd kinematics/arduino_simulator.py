#! /usr/bin/env python
#IDN
# This script is used when Arduino is not connected-it is doing similar pub-sub operation for adjusting the RPM limits of the motor controller offline
# NOTE: parameters are adjusted in the ESCON Studio
import rospy, numpy as np
from std_msgs.msg import Int16
from geometry_msgs.msg import Twist
from itu_odv_navigation.msg import motorPWMs

rospy.init_node('arduino_simulator', anonymous=True)
u = np.zeros(4)

def callback(msg):
	global u
       	#Turning into velocity value
       	for i in range(0, len(u)):
       		u[i] = (msg.data[i]-127.0)/101*1000
       	
       	pub.publish(u)
        
        
print "Arduino Ready"       
	
#### definition of publisher/subscriber and services ###
pub = rospy.Publisher('/motor_vel_fb', motorPWMs, queue_size=10)#change the sub type in in fwd_kinematics as motorPWMs
rospy.Subscriber('/pwm_values', motorPWMs, callback)
rospy.spin()
