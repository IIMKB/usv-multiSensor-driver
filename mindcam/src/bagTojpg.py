#!/usr/bin/python

#PKG = 'beginner_tutorials'

import roslib
import rosbag
import rospy
import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from cv_bridge import CvBridgeError

class ImageCreator():

    def __init__(self):
        self.bridge = CvBridge()
        with rosbag.Bag('Asus.bag','r') as bag:
            for topic,msg,t in bag.read_messages():
                if topic == "mindcamera/image1":
                    try:
                        cv_image = self.bridge.imgmsg_to_cv2(msg,"bgr8")
                    except CvBridgeError as e:
                        print e
                    timestr = "%.6f" % msg.header.stamp.to_sec()
                    image_name = timestr + ".jpg"
                    cv2.imwrite(image_name,cv_image)

if __name__ == '__main__':
    try:
        image_creator = ImageCreator()
    except rospy.ROSInterruptException:
        pass