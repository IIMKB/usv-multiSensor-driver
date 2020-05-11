#!/usr/bin/python

#PKG = 'beginner_tutorials'

import time, sys, os
from ros import rosbag
import roslib, rospy
roslib.load_manifest('sensor_msgs')
from sensor_msgs.msg import Image

from cv_bridge import CvBridge
import cv2

TOPIC = 'camera/image_raw'

def CreateVideoBag(videopath, bagname):
    '''Creates a bag file with a video file'''
    print videopath
    print bagname
    bag = rosbag.Bag(bagname, 'w')
    cap = cv2.VideoCapture(videopath)
    cb = CvBridge()
    # prop_fps = cap.get(cv2.cv.CV_CAP_PROP_FPS)  # 源代码是这个,不能正常运行
    prop_fps = cap.get(cv2.CAP_PROP_FPS)  # 改成了这个
    if prop_fps != prop_fps or prop_fps <= 1e-2:
        print "Warning: can't get FPS. Assuming 24."
        prop_fps = 24
    prop_fps = 24 # 手机拍摄的是29.78，我还是转成24的。
    print prop_fps
    ret = True
    frame_id = 0
    while(ret):
        ret, frame = cap.read()
        if not ret:
            break
        stamp = rospy.rostime.Time.from_sec(float(frame_id) / prop_fps)
        frame_id += 1
        image = cb.cv2_to_imgmsg(frame, encoding='bgr8')
        image.header.stamp = stamp
        image.header.frame_id = "camera"
        bag.write(TOPIC, image, stamp)
    cap.release()
    bag.close()

if __name__ == "__main__":
    if len( sys.argv ) == 3:
        CreateVideoBag(*sys.argv[1:])
    else:
        print( "Usage: video2bag videofilename bagfilename")
# import roslib
# import rosbag
# import rospy
# import cv2
# from sensor_msgs.msg import Image
# from cv_bridge import CvBridge
# from cv_bridge import CvBridgeError
#
# class ImageCreator():
#
#     def __init__(self):
#         self.bridge = CvBridge()
#         with rosbag.Bag('Asus.bag','r') as bag:
#             for topic,msg,t in bag.read_messages():
#                 if topic == "mindcamera/image1":
#                     try:
#                         cv_image = self.bridge.imgmsg_to_cv2(msg,"bgr8")
#                     except CvBridgeError as e:
#                         print e
#                     timestr = "%.6f" % msg.header.stamp.to_sec()
#                     image_name = timestr + ".jpg"
#                     cv2.imwrite(image_name,cv_image)
#
# if __name__ == '__main__':
#     try:
#         image_creator = ImageCreator()
#     except rospy.ROSInterruptException:
#         pass