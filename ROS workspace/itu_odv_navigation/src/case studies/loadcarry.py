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
        goal.target_pose.pose.position.x = 0.0
        goal.target_pose.pose.position.y = 0.0
        goal.target_pose.pose.orientation.z = 0
        goal.target_pose.pose.orientation.w = 1.0
        print goal
    
    elif (msg == 1.0 ):
        goal.target_pose.pose.position.x = 0.4
        goal.target_pose.pose.position.y = -4
        goal.target_pose.pose.orientation.z = 0.9999999999991198
        goal.target_pose.pose.orientation.w = 0
        print goal    
        
    elif (msg == 2.0 ):
        goal.target_pose.pose.position.x = -6.2
        goal.target_pose.pose.position.y = -1.2
        goal.target_pose.pose.orientation.z = 0.7071067811848163
        goal.target_pose.pose.orientation.w = 0.7071067811882787
        print goal
    
    elif (msg == 3.0 ):
        goal.target_pose.pose.position.x = -6.2
        goal.target_pose.pose.position.y = 0.4
        goal.target_pose.pose.orientation.z = 0.7071067811848163  
        goal.target_pose.pose.orientation.w = 0.7071067811882787  
    	print goal
    	
    elif (msg == 4.0 ):
        goal.target_pose.pose.position.x = 0.4
        goal.target_pose.pose.position.y = -4
        goal.target_pose.pose.orientation.z = 0.7071067811848163
        goal.target_pose.pose.orientation.w = 0.7071067811882787
        print goal
        
    else:
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
          
#autopath
msg=0
while not rospy.is_shutdown():
    global flag
    if abs(msg)<=5:
        movebase_client(msg)
        msg+=1
        
    rospy.sleep(0)
    
#manualpath
#while not rospy.is_shutdown():
#    msg=raw_input("Select point . . . 0(base)/1/2/3/4/5")
#    msg=int(msg)
#    movebase_client(msg)
#    rospy.sleep(0)
    

                     




        
