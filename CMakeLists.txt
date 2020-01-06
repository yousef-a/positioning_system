cmake_minimum_required(VERSION 2.8.3)
project(positioning_system)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  darknet_ros
  geometry_msgs
  nav_msgs
  roscpp
  std_msgs
  message_generation
  genmsg
  
)

add_message_files(
  FILES
  Controller_param.msg
  Waypoint.msg
)

add_service_files(
   FILES
   twoPointLine.srv
   Arm.srv
   Update_Controller.srv
   Reset_Controller.srv
   Update_Pose_Reference.srv
   Update_X_Reference.srv
   Update_Y_Reference.srv
   Update_Z_Reference.srv
   Update_Yaw_Reference.srv
   SwitchBlock.srv
) 

generate_messages(
   DEPENDENCIES
   geometry_msgs
   std_msgs
)

catkin_package(
  INCLUDE_DIRS 
    include
  LIBRARIES
    uav_controller
  CATKIN_DEPENDS
    darknet_ros
    geometry_msgs
    nav_msgs
    roscpp
    std_msgs
  DEPENDS
    system_lib
)


include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${catkin_INCLUDE_DIRS}
  src/matrix_op
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Navio2
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Navio2/Common
)


FILE(GLOB SOURCE_FILES *.hpp *.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Navio2_cpp/*.cpp
        )


add_executable(fire_localizer ${SOURCE_FILES})
target_link_libraries(fire_localizer ${catkin_LIBRARIES})

#add_executable(fire_localization src/main.cpp ${SOURCE_FILES})
#target_link_libraries(fire_localization ${catkin_LIBRARIES})
#add_dependencies(fire_localization positioning_system_generate_messages_cpp)
