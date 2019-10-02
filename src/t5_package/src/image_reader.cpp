#include <ros/ros.h>
#include <ros/package.h>

#include <sensor_msgs/Image.h>
#include <sensor_msgs/fill_image.h>
#include <image_transport/image_transport.h>

#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

#include <image_geometry/pinhole_camera_model.h>
#include <camera_info_manager/camera_info_manager.h>

void imgCallback (const sensor_msgs::ImageConstPtr& rosImage)
{
  try
  {
    cv::imshow("view_reader", cv_bridge::toCvShare(rosImage, "mono8")->image);
    cv::waitKey(30);
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", rosImage->encoding.c_str());
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "image_reader");
  ros::NodeHandle nh ("~");
  ros::Rate rate(30.0);

  image_transport::ImageTransport imgtp(nh);
  image_transport::Subscriber sub = imgtp.subscribe("/camera/image_processed", 1, imgCallback);
  image_transport::Publisher pub = imgtp.advertise("out_img", 1);
  ros::spin();

}
