#!/usr/bin/env python

import rospy

if __name__ == '__main__':
    rospy.init_node('node_basic')
    
    rate = rospy.Rate(2)

    while not rospy.is_shutdown():

        rospy.loginfo("hello, world!")

        rate.sleep()
