#include <cstdio>
#include <stdio.h>
#include <opencv2/opencv.hpp>

#define ESCAPE_BUTTON 27
#define WAIT_MILLISECONDS 25
#define WINDOW_NAME "Hello"

using namespace cv;

class Camera {

  public:
    int check_on_keypress() {
      char c = (char)waitKey(WAIT_MILLISECONDS);
      if (c == ESCAPE_BUTTON) {
        return 1;
      }
      return 0;
    } 
    int camera_view() {
      Mat myImage;
      namedWindow(WINDOW_NAME);
      VideoCapture cap(0);

      if (!cap.isOpened())
        return -1;
      
      while (true) {
        cap >> myImage;
        if (myImage.empty())
          break;
      
        imshow(WINDOW_NAME, myImage);
        if (check_on_keypress() == 1)
          break;
      }
      cap.release();
      return 0;

    }

};



int main(int argc, char* argv[]) {
  Camera camera;
  camera.camera_view();
}
