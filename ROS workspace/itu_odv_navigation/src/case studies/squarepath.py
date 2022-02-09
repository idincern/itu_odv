#!/usr/bin/env python
# license removed for brevity

import rospy
import actionlib
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal
from std_msgs.msg import Int32
from std_msgs.msg import Float32

rospy.init_node("move_base_goal_sender")


def movebase_client(msg):
    client = actionlib.SimpleActionClient('move_base',MoveBaseAction)
    client.wait_for_server()
    goal = MoveBaseGoal()
    print msg
    goal.target_pose.header.frame_id = "map"
    goal.target_pose.header.stamp = rospy.Time.now()
    goal.target_pose.header.seq+=1
    if(msg == 0.0 ) :
        #goal=(2, 0, 0, 0, 0, 0, 1)
        goal.target_pose.pose.position.x = 0.0
        goal.target_pose.pose.position.y = 0.0
        goal.target_pose.pose.orientation.z = 0
        goal.target_pose.pose.orientation.w = 1.0
        print goal
    
    elif (msg == 1.0 ):
        #goal=(2, 2, 0, 0, 0, 0.7, 0.7)
        goal.target_pose.pose.position.x = 2.0
        goal.target_pose.pose.position.y = 0.0
        goal.target_pose.pose.orientation.z = 0.0
        goal.target_pose.pose.orientation.w = 1.0
        print goal
    
    elif (msg == 2.0 ):
        #goal=(0.0, 2, 0.0, 0.0, 0.0, 1.0, 0.0)
        goal.target_pose.pose.position.x = 2.0
        goal.target_pose.pose.position.y = 2.0
        goal.target_pose.pose.orientation.z = 0.7  
        goal.target_pose.pose.orientation.w = 0.7  
    	print goal
    	
    elif (msg == 3.0 ):
        #goal=(0.0, 0.0, 0.0, 0.0, 0.0, -0.7, 0.7)
        goal.target_pose.pose.position.x = 0.0
        goal.target_pose.pose.position.y = 2.0
        goal.target_pose.pose.orientation.z = 1.0
        goal.target_pose.pose.orientation.w = 0.0
        print goal
        
    else:
        #goal=(2, 0, 0, 0, 0, 0, 1)
        goal.target_pose.pose.position.x = 0.0
        goal.target_pose.pose.position.y = 0.0
        goal.target_pose.pose.orientation.z = 0
        goal.target_pose.pose.orientation.w = 1.0
        print goal
 
    client.send_goal(goal)
    wait = client.wait_for_result()
    if not wait:
        rospy.logerr("Action server not available!")
        rospy.signal_shutdown("Action server not available!")
    else:
        return client.get_result()
        
def shutdown_msg():
  print "Node has shut down!"
rospy.on_shutdown(shutdown_msg)
          
while not rospy.is_shutdown():
    msg=raw_input("Select point . . . 0(base)/1/2/3")
    msg=int(msg)
    movebase_client(msg)
    rospy.sleep(0)
    
    

                     




        
