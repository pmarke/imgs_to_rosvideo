cmake_minimum_required(VERSION 2.8.3)
project(imgs_to_rosvideo)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  cv_bridge
  image_transport
  
)

find_package(OpenCV)


catkin_package(
    CATKIN_DEPENDS

)


include_directories(
include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_DIR}
)


add_executable(${PROJECT_NAME}_node src/imgs_to_rosvideo_node.cc src/imgs_to_rosvideo.cc)


target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES} ${OpenCV_LIBS}
)


