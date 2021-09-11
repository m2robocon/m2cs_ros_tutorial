#!/usr/bin/env python

import rospy
from lab5.srv import *

def callback(req):
    ans = req.first + req.second

    rospy.loginfo("Received [%s, %s], returning %s"%(req.first, req.second, ans))

    resp = AddTwoIntsResponse()
    resp.sum = ans
    return resp

    # return ans

    # return AddTwoIntsResponse(sum = ans)

if __name__ == "__main__":
    rospy.init_node('adder')
    rospy.Service('calc', AddTwoInts, callback)

    rospy.loginfo("Ready to add two ints.")
    rospy.spin()
