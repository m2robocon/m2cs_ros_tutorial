#!/usr/bin/env python

import rospy, random
from lab5.srv import *

if __name__ == "__main__":
    rospy.init_node('caller')

    calc_client = rospy.ServiceProxy('calc', AddTwoInts)

    r = rospy.Rate(1)

    while not rospy.is_shutdown():
        a = random.randint(1, 10)
        b = random.randint(1, 10)

        rospy.loginfo("Generated [%d, %d], sending addition request..." % (a, b))

        req = AddTwoIntsRequest()
        req.first = a
        req.second = b

        # rospy.wait_for_service('calc')

        resp = calc_client(req)

        # resp = calc_client(a, b)

        rospy.loginfo("Received response: %d" % resp.sum)

        r.sleep()
