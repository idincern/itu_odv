#! /usr/bin/env python
#IDN
#This node converts twist messages created by forward kinematics node and publishes the odometry of the robot
import rospy, numpy as np
from math import cos, sin
from std_msgs.msg import Float32MultiArray, Float32
from geometry_msgs.msg import Twist, Pose, Quaternion
from nav_msgs.msg import Odometry
from tf.broadcaster import TransformBroadcaster
import tf
import tf_conversions
import tf2_ros

rospy.init_node('forward_kinematics')
calculated_odom = Odometry()

odomBroadcaster = TransformBroadcaster()
vx=0
vy=0
wz=0
current_time = rospy.Time.now()
last_time = rospy.Time.now()

def callback(msg):
	global vx, vy, wz
	vx=msg.data[0]
	vy=msg.data[1]
	wz=msg.data[2]
	
def odomcreator():
	global vx, vy, wz, current_time, last_time, odomBroadcaster, calculated_odom	
	current_time = rospy.Time.now()
	dt = (current_time - last_time).to_sec()
	
        delta_x  = (vx * cos(wz) - vy * sin(wz)) * dt
        delta_y  = (vx * sin(wz) + vy * cos(wz)) * dt
        delta_wz =  wz * dt
        
	calculated_odom.header.frame_id="/odom"
	calculated_odom.child_frame_id="/base_link"
	
	# create quaternion from yaw
        odom_quat = tf_conversions.transformations.quaternion_from_euler(0,0,delta_wz)
        
	# prepare odometry
        calculated_odom.header.stamp = current_time
        calculated_odom.pose.pose.position.x += delta_x
        calculated_odom.pose.pose.position.y += delta_y
        calculated_odom.pose.pose.position.z += 0.0
        # calculated_odom.pose.pose.orientation = Quaternion(*odom_quat) # readjust 
	calculated_odom.pose.pose.orientation.x = odom_quat[0]
	calculated_odom.pose.pose.orientation.y = odom_quat[1]
	calculated_odom.pose.pose.orientation.z = odom_quat[2]
	calculated_odom.pose.pose.orientation.w = odom_quat[3]
        # set the velocity
        calculated_odom.twist.twist.linear.x = vx
        calculated_odom.twist.twist.linear.y = vy
        calculated_odom.twist.twist.angular.z = wz
        # publish 
        odomBroadcaster.sendTransform( (vx, vy, 0),
                                                odom_quat,
                                                current_time,
                                                "/base_link",
                                                "/odom" )
        pub.publish(calculated_odom)
        last_time = current_time
print "Odom Ready"          
	
#### definition of publisher/subscriber and services ###
pub = rospy.Publisher('/odom', Odometry, queue_size=10)
rospy.Subscriber('/twist_speeds', Float32MultiArray, callback)

while not rospy.is_shutdown():
    odomcreator()
    rospy.sleep(0.1)








	
	
	
	
	
