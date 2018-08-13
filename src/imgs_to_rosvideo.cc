#include "imgs_to_rosvideo/imgs_to_rosvideo.h"


namespace video {


ImgToVideo::ImgToVideo(ros::NodeHandle nh) : nh_(nh),
    image_transport_(nh){

    ReadRosParameters();
    InitRos();
    ConvertImgsToVideo();
}

//-------------------------------------------------------------

void ImgToVideo::ReadRosParameters() {

    // Image parameters
    nh_.param("img_type", img_type_,std::string("jpg"));
    nh_.param("img_path", img_path_,std::string("/home/user_name/Pictures/"));
    nh_.param("begin_img", begin_img_,0);
    nh_.param("end_img", end_img_,100);
    nh_.param("name_width", name_width_, 12);

    // Video parameters
    nh_.param("fps", fps_,15);
    nh_.param("repeate", repeate_,false);
    nh_.param("resize", resize_,false);
    nh_.param("rows", rows_,480);
    nh_.param("cols", cols_,640);
}

//-------------------------------------------------------------

void ImgToVideo::InitRos() {

    image_publisher_ = image_transport_.advertise("image_raw",1);
}

//-------------------------------------------------------------

void ImgToVideo::ConvertImgsToVideo() {

    cv::Mat img;
    bool first = true;

    ros::Rate r(fps_);

    while (first || repeate_) {

        for (int count = begin_img_; count < end_img_+1; count++) {

            // construct file name
            std::stringstream ss;
            ss << std::setw(name_width_) << std::setfill('0') << count;
            std::string file_name = img_path_+ss.str()+'.'+img_type_;

            img = cv::imread(file_name.c_str(), cv::IMREAD_COLOR);

            if (!img.empty()) {

                if (resize_) {
                    cv::resize(img,img, cv::Size(cols_,rows_));
                }   

                PublishImg(img);
                r.sleep();
            }
        }
        first = false;
    }
}

//-------------------------------------------------------------

void ImgToVideo::PublishImg(const cv::Mat& img) {

    // Publish the image if there is a subscriber
    if (image_publisher_.getNumSubscribers() > 0) {

        ros::Time t = ros::Time::now();

        // Publish the image using ROS
        cv_bridge::CvImage image_msg;
        image_msg.encoding = sensor_msgs::image_encodings::BGR8;
        image_msg.image = img;
        image_msg.header.stamp.sec = t.sec;
        image_msg.header.stamp.nsec = t.nsec;
        image_msg.header.frame_id = '0';
        image_publisher_.publish(image_msg.toImageMsg());

    } else {
        ROS_DEBUG("ImgToVideo: There are no subscribers.");
    }
}

}