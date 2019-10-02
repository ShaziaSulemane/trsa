#include <ros/ros.h>
#include <ros/package.h>

#include <sensor_msgs/Image.h>
#include <sensor_msgs/fill_image.h>
#include <image_transport/image_transport.h>

#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

#include <image_geometry/pinhole_camera_model.h>
#include <camera_info_manager/camera_info_manager.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "camera_driver");
  ros::NodeHandle nh ("~");
  ros::Rate rate(30.0);

  image_transport::ImageTransport it(nh);
  image_transport::Publisher pubRaw = it.advertise("/camera/image_raw", 1);

  cv::VideoCapture cap(0); // open the camera with <device_index>
  if ( !cap.isOpened() ) // check if we succeeded
  return -1;

  cv::Mat frame;// create just an empty image without any information regarding its type and dimensions
  sensor_msgs::Image ros_image;
  while(ros::ok())
  {
    cap >> frame; // get a new frame from camera
    if ( !frame.data ) // check if a new frame was successfully retrieve
      break;
    // this can fail if the camera is not available anymore
    // or, in the case of a video file, we have reached the end of file.

    cv_bridge::CvImage out_msg;
    out_msg.header.stamp = ros::Time::now() ; // timestamp from the system clock
    out_msg.header.frame_id = "/camera_link"; // camera position in the world
    out_msg.encoding = sensor_msgs::image_encodings::BGR8; // or other types
    out_msg.image = frame; // your cv::Mat
    out_msg.toImageMsg( ros_image );

    cv::imshow( "camera", frame ); // opens a named window to display the image
    pubRaw.publish (ros_image);
    cv::waitKey(1);
    // waits 1 millisecond – useful to allow the display
    // refresh from cv::imshow. It can also capture pressed keys.
  }
}
