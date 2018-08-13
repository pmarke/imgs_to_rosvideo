#pragma once

#include <string>


// ROS
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>



namespace video {

class ImgToVideo {

public: 

    ImgToVideo(ros::NodeHandle nh);

private:

    // Loads the ROS parameters
    void ReadRosParameters();

    // Setup the image publisher
    void InitRos();

    // Convert the images into video
    void ConvertImgsToVideo();

    // PUblish the image
    void PublishImg(const cv::Mat& img);

    // ROS
    ros::NodeHandle nh_;
    image_transport::ImageTransport image_transport_;
    image_transport::Publisher image_publisher_;


    // Image parameters
    std::string img_type_;
    std::string img_path_;
    int begin_img_;
    int end_img_;
    int name_width_;

    // Video parameters
    int fps_;
    bool repeate_;
    bool resize_;
    int rows_;
    int cols_;

};



}