#!/usr/bin/env python
#################### import ##########################
import rospy
import random
from std_msgs.msg import Int32, String
from nav_msgs.msg import Odometry


rospy.init_node("odom_cloner")
last_odom = Odometry()

last_odom.header.frame_id="odom"
last_odom.child_frame_id="base_link"
###################
############# definitions of variables #################
############ definitions of functions ##################
def callback(msg):
	last_odom = msg
	last_odom.pose.pose.position.x = msg.pose.pose.position.x + random.randint(-1,1)/10000.0
	last_odom.pose.pose.position.y = msg.pose.pose.position.y + random.randint(-1,1)/10000.0
	
	last_odom.pose.pose.orientation.z = msg.pose.pose.orientation.z + random.randint(-1,1)/10000.0
	last_odom.pose.pose.orientation.w = msg.pose.pose.orientation.w + random.randint(-1,1)/10000.0
	last_odom.header.stamp = rospy.get_rostime()
	pub.publish(last_odom)

rospy.Subscriber('/odom', Odometry, callback)
pub = rospy.Publisher('/odom_clone', Odometry, queue_size=1)
rate = rospy.Rate(10) # hz	
#### definition of publisher/subscriber and services ###
while not rospy.is_shutdown():
	rate.sleep()
