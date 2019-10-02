#include <ros/ros.h>
#include <ros/package.h>

#include <sensor_msgs/Image.h>
#include <sensor_msgs/fill_image.h>
#include <image_transport/image_transport.h>

#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

#include <image_geometry/pinhole_camera_model.h>
#include <camera_info_manager/camera_info_manager.h>

class ImageConvert
{
  public:
    ros::NodeHandle nh;
    image_transport::ImageTransport it;
    image_transport::Subscriber subIt;
    image_transport::Publisher pubIt;

    ImageConvert ();
    void imgCallback (const sensor_msgs::ImageConstPtr& rosImage);
    void run ();
};

ImageConvert::ImageConvert ()
  : it (nh)
{
  pubIt = it.advertise("camera/image_processed", 1);
  subIt = it.subscribe("camera/image_raw", 1, &ImageConvert::imgCallback, this);
}

void ImageConvert::run ()
{
  while (ros::ok())
    ros::spin();
}

void ImageConvert::imgCallback (const sensor_msgs::ImageConstPtr& rosImage)
{
  try
  {
    cv::Size ksize (21,21);
    cv_bridge::CvImagePtr cv_image = cv_bridge::toCvCopy(rosImage, "bgr8");
    cv_bridge::CvImagePtr cv_gray = cv_bridge::cvtColor (cv_image, "mono8");
    cv::GaussianBlur (cv_gray->image, cv_image->image, ksize, 0);
    
    cv_image->encoding = "mono8";

    pubIt.publish(cv_image->toImageMsg());

    cv::imshow("view", cv_image->image);
    cv::waitKey(30);
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("Could not convert from '%s' to 'mono8'.", rosImage->encoding.c_str());
    return;
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "image_converter");
  ImageConvert ic;
  ic.run();
  return 0;
}
