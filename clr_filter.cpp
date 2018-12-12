#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap(0);
	if(!cap.isOpened())
		return -1;
	int bm=0,gm=0,rm=0;
	namedWindow("video",WINDOW_NORMAL);
	createTrackbar("Bmin","video",&bm,255);
	createTrackbar("Gmin","video",&gm,255);
	createTrackbar("Rmin","video",&rm,255);
	while(1)
	{
		Mat img;
		cap>>img;
		Mat a=img.clone();
		cvtColor(img,img,COLOR_RGB2GRAY);
		for (int i = 0; i < img.rows; i++)
		{
			for (int j = 0; j < img.cols; j++)
			{
				if(img.at<Vec3b>(i,j)[0]<bm||img.at<Vec3b>(i,j)[1]<gm||img.at<Vec3b>(i,j)[2]<rm)
				{
					a.at<Vec3b>(i,j)={img.at<uchar>(i,j),img.at<uchar>(i,j),img.at<uchar>(i,j)};
				}
			}
		}
		imshow("video",a);
		waitKey(1);
	}
}