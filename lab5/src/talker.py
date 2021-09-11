#!/usr/bin/env python

import rospy
from lab5.msg import Chat

if __name__ == '__main__':
    rospy.init_node('talker')
    pub = rospy.Publisher('chatter', Chat, queue_size = 1)
    
    rate = rospy.Rate(10)
    cur = 1

    while not rospy.is_shutdown():
        c = Chat()
        c.id = cur; c.text = "abc"
        rospy.loginfo(cur)

        pub.publish(cur, "abc")
        # pub.publish(c)

        rate.sleep()
        cur += 1
