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
        goal.target_pose.pose.position.x = 1.0
        goal.target_pose.pose.position.y = 0.0
        goal.target_pose.pose.orientation.z = 0.5000000000014733
        goal.target_pose.pose.orientation.w = 0.866025403783588
        print goal
    
    elif (msg == 2.0 ):
        goal.target_pose.pose.position.x = 1.5
        goal.target_pose.pose.position.y = 0.86602540378
        goal.target_pose.pose.orientation.z = 0.8660254037836398  
        goal.target_pose.pose.orientation.w = 0.5000000000013837  
    	print goal
    	
    elif (msg == 3.0 ):
        goal.target_pose.pose.position.x = 1.0
        goal.target_pose.pose.position.y = 1.73205080757
        goal.target_pose.pose.orientation.z = 1.0
        goal.target_pose.pose.orientation.w = 0.0
        print goal

    elif (msg == 4.0 ):
        goal.target_pose.pose.position.x = 0.0
        goal.target_pose.pose.position.y = 1.73205080757
        goal.target_pose.pose.orientation.z = 0.8660254037835363
        goal.target_pose.pose.orientation.w = -0.5000000000015627
        print goal
        
    elif (msg == 5.0 ):
        goal.target_pose.pose.position.x = -0.5
        goal.target_pose.pose.position.y = 0.86602540378
        goal.target_pose.pose.orientation.z = 0.5000000000012941
        goal.target_pose.pose.orientation.w = -0.8660254037836915
        print goal  
    else:
        #goal=(2, 0, 0, 0, 0, 0, 1)
        goal.target_pose.pose.position.x = 0.0
        goal.target_pose.pose.position.y = 0.0
        goal.target_pose.pose.orientation.z = 0
        goal.target_pose.pose.orientation.w = 1.0
        print goal
 
    client.send_goal(goal)
    msg+=1
    
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
    if abs(msg)<=6:
        movebase_client(msg)
        msg+=1
    rospy.sleep(0)
    
#manualpath
#while not rospy.is_shutdown():
#    msg=raw_input("Select point . . . 0(base)/1/2/3/4/5")
#    msg=int(msg)
#    movebase_client(msg)
#    rospy.sleep(0)
    
    

                     




        
