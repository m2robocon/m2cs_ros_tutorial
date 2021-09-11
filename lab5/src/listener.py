#!/usr/bin/env python

import rospy
from lab5.msg import Chat

def callback(data):
    rospy.loginfo('I heard %d %s', data.id, data.text)

if __name__ == '__main__':
    rospy.init_node('listener')
    rospy.Subscriber('chatter', Chat, callback)

    rospy.spin()

    print("node terminated")
