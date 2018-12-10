#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
	Mat a(320,320,CV_8UC3,Scalar(255,255,255));
	for (int i = 0; i < 320; i++)
	{
		for (int j = 0; j < 320; j++)
		{
			if (((i/40)+(j/40))%2==0) //Even better to use (((i/40)+(j/40))%2==0)
			{
				a.at<Vec3b>(i,j)={0,0,0};
			}
		}
	}
	namedWindow("window1",WINDOW_NORMAL);
	imshow("window1",a);
	waitKey(2000);
	return 0;
}