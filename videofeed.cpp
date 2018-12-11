#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <math.h>
using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
	VideoCapture cap(0);
	if (!cap.isOpened())
	{
		return -1;
	}
	namedWindow("image",WINDOW_NORMAL);
	while (1)
	{
		Mat img;
		cap>>img;
		imshow("image",img);
		waitKey(1);
	}
}

