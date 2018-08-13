#include "imgs_to_rosvideo/imgs_to_rosvideo.h"

int main(int argc, char** argv) {


    ros::init(argc,argv, "imgs_to_rosvideo_node");

    video::ImgToVideo node(ros::NodeHandle("~"));

    ros::spin();

}