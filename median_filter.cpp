#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <algorithm>
using namespace std;
using namespace cv;

Mat a=imread("samps/veg.jpg",0);
Mat b(a.rows+2,a.cols+2,CV_8UC1,Scalar(255));

int med_fil(int i,int j)
{
	int arr[9]={b.at<uchar>(i-1,j-1),b.at<uchar>(i,j-1),b.at<uchar>(i+1,j-1),b.at<uchar>(i-1,j),b.at<uchar>(i,j),b.at<uchar>(i+1,j),b.at<uchar>(i-1,j+1),b.at<uchar>(i,j+1),b.at<uchar>(i+1,j+1)};
	sort(arr,arr+9);
	return arr[4];
}	

int main()
{
	for(int i=0;i<a.rows;i++)
	{
		for(int j=0;j<a.cols;j++)
		{
			b.at<uchar>(i+1,j+1)=a.at<uchar>(i,j);
		}
	}

	namedWindow("win",WINDOW_NORMAL);
	int mint=10,maxt=250;
	createTrackbar("minT","win",&mint,120);
	createTrackbar("maxT","win",&maxt,255);


	while(1)
	{
		Mat c=b.clone();
		for(int i=1;i<=a.rows;i++)
		{
			for(int j=1;j<=a.cols;j++)
			{
				if(c.at<uchar>(i,j)<mint||c.at<uchar>(i,j)>maxt)
				{
					c.at<uchar>(i,j)=med_fil(i,j);
				}
			}
		}

		imshow("win",c);
		waitKey(1);
	}
}