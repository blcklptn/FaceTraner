cmake_minimum_required(VERSION 3.1)

project ( FaceTrainer )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( FaceTrainer main.cpp )
target_link_libraries( FaceTrainer ${OpenCV_LIBS} )
