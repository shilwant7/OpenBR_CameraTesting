#include <openbr/openbr_plugin.h>
#include "opencv2/opencv.hpp"
using namespace cv;
int main(int argc, char** argv)
{
    VideoCapture cap(0);
  //VideoCapture cap("rtsp://admin:password@ip_address/h264/ch1/main/av_stream?tcp");
    // open the default camera, use something different from 0 otherwise;
    // Check VideoCapture documentation.
    if(!cap.isOpened())
        return -1;
    for(;;)
    {
          Mat frame;
          cap >> frame;
          if( frame.empty() ) break; // end of video stream
          imshow("this is you, smile! :)", frame);
          if( waitKey(1) == 27 ) break; // stop capturing by pressing ESC
    }
    // the camera will be closed automatically upon exit
    // cap.close();
    return 0;
}
