#!/usr/bin/env python
import rospy
from math import pi, fmod, sin, cos, sqrt
from geometry_msgs.msg import Twist
# hint: some imports are missing

cur_pos = Pose()

def cb_pose(data): # get the current position from subscribing the turtle position
    global cur_pos
    cur_pos = data

def cb_walk(req):
    if (req.distance < 0):
        return False

    # hint: calculate the projected (x, y) after walking the distance,
    # and return false if it is outside the boundary

    rate = rospy.Rate(100) # 100Hz control loop

    while ('''goal not reached'''): # control loop
        
        # in each iteration of the control loop, publish a velocity

        # hint: you need to use the formula for distance between two points
        
        rate.sleep()
    
    vel = Twist() # publish a velocity 0 at the end, to ensure the turtle really stops
    pub.publish(vel)

    return True

def cb_orientation(req):

    rate = rospy.Rate(100) # 100Hz control loop
    
    while ('''goal not reached'''): # control loop
        
        # in each iteration of the control loop, publish a velocity

        # hint: signed smallest distance between two angles: 
        # see https://stackoverflow.com/questions/1878907/the-smallest-difference-between-2-angles
        #     dist = fmod(req.orientation - cur_pos.theta + pi + 2 * pi, 2 * pi) - pi
        
        rate.sleep()
    
    vel = Twist() # publish a velocity 0 at the end, to ensure the turtle really stops
    pub.publish(vel)

    return True

if __name__ == '__main__':
    rospy.init_node('path_manager')
    
    pub = # publisher of the turtle velocity
    sub = # subscriber of the turtle position, callback to cb_pose
    
    ## init each service server here:
    # rospy.Service( ... )		# callback to cb_orientation
    # rospy.Service( ... )		# callback to cb_walk
    
    rospy.spin()
