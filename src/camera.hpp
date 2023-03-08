#ifndef CAMERA_HPP

#include <opencv2/opencv.hpp>
#define ESCAPE_BUTTON 27
#define WAIT_MILLISECONDS 25
#define WINDOW_NAME "FaceTrainer"
#define RUNNING true

using namespace cv;

class Camera {
  private:
    int check_on_keypress() {
      char c = (char)waitKey(WAIT_MILLISECONDS);
      if (c == ESCAPE_BUTTON)
        return 1;
      return 0;
    }
  public:
    int camera_view() {
      Mat frame;
      namedWindow(WINDOW_NAME);
      VideoCapture cap(0);

      if (!cap.isOpened())
        return -1;
      
      while (RUNNING) {
        cap >> frame;
        if (frame.empty())
          break;

        imshow(WINDOW_NAME, frame);
        if (check_on_keypress() == 1)
          break;
      }
      cap.release();
      return 0;
    }
};

#endif
