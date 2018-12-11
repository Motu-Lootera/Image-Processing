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
	int th=0;
	createTrackbar("Threshold","image",&th,255);
	while (1)
	{
		Mat a;
		cap>>a;
		cvtColor(a,a,COLOR_RGB2GRAY);
		Mat img=a.clone();
		for (int i = 1; i < img.rows-1; i++)
		{
			for (int j = 1; j < img.cols-1; j++)
			{
				int sy=((a.at<uchar>(i-1,j-1)*(-1)) + (a.at<uchar>(i-1,j)*(-2)) + (a.at<uchar>(i-1,j+1)*(-1)) + (a.at<uchar>(i+1,j-1)*(1)) + (a.at<uchar>(i+1,j)*(2)) + (a.at<uchar>(i+1,j+1)*(1)));
				int sx=((a.at<uchar>(i-1,j-1)*(-1)) + (a.at<uchar>(i,j-1)*(-2)) + (a.at<uchar>(i+1,j-1)*(-1)) + (a.at<uchar>(i-1,j+1)*(1)) + (a.at<uchar>(i,j+1)*(2)) + (a.at<uchar>(i+1,j+1)*(1)));
				float val= pow((sx*sx)+(sy*sy),0.5);
				if (val>=th)
					img.at<uchar>(i,j)=0;
				
				else
					img.at<uchar>(i,j)=255;
			}
		}
		imshow("image",img);
		waitKey(1);
	}
}
