#!/usr/bin/env python

import rospy

rospy.init_node('arg_talker')

port_param = rospy.get_param('~port')

rospy.sleep(1)
rospy.loginfo('%s is %s', rospy.resolve_name('~port'), port_param)

rospy.spin()
