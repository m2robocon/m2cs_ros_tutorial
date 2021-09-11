#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist
from turtlesim.srv import SetPen
# hint: some imports are missing

old_data = Ps4Data()

def callback(data):
    global old_data
    
    # you should publish the velocity here!
    
    # hint: to detect a button being pressed, you can use the following pseudocode:
    # 
    # if ((data.button is pressed) and (old_data.button not pressed)),
    # then do something...
    
    old_data = data

if __name__ == '__main__':
    rospy.init_node('ps4_controller')
    
    pub = # publisher object goes here... hint: the topic type is Twist
    sub = # subscriber object goes here
    
    # one service object is needed for each service called!
    srv_col = # service client object goes here... hint: the srv type is SetPen
    # fill in the other service client object...
    
    rospy.spin()
