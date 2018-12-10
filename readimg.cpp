#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
	Mat img= imread("/home/arnesh/IP/samps/fruits.png",1);
	namedWindow("window1",WINDOW_NORMAL);
	imshow("window1",img);
	waitKey(2000);
	return 0;
}