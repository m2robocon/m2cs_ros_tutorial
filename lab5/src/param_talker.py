#!/usr/bin/env python

import rospy

rospy.init_node('param_talker')

# fetch a /global parameter
global_example = rospy.get_param('/global_example')
rospy.loginfo("%s is %s", rospy.resolve_name('/global_example'), global_example)

# fetch the utterance parameter from our parent namespace
utterance = rospy.get_param('~utterance')
rospy.loginfo("%s is %s", rospy.resolve_name('~utterance'), utterance)

# fetch a parameter, using 'default_value' if it doesn't exist
default_param = rospy.get_param('default_param', "default_value")
rospy.loginfo("%s is %s", rospy.resolve_name('default_param'), default_param)

# fetch a group (dictionary) of parameters
gains = rospy.get_param('~gains')
p, i, d = gains['kP'], gains['kI'], gains['kD']
rospy.loginfo("gains are %s, %s, %s", p, i, d)

rospy.spin()
