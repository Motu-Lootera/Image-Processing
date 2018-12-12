#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;
int hist(Mat img)
{
	int rows=img.rows;
	int cols=img.cols;
	int arr[256]={};
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[img.at<uchar>(i,j)]++;
		}
	}
	//max in array
	int max=arr[0];
	for (int i = 0; i < 256; i++)
	{
		if (arr[i]>max)
		{
			max=arr[i];
		}
	}
	//scaling
	for (int i = 0; i < 256; i++)
	{
		arr[i]=arr[i]*250.0/max;
	}
	//making histogram
	Mat hist(256,256,CV_8UC1,Scalar(255));
	for (int j = 0; j < 256; j++)
	 {
	 	for (int i = 250-arr[j]; i < 250; i++)
	 	{
	 		hist.at<uchar>(i,j)=0;
	 	}
	 }
	 namedWindow("histogram",WINDOW_NORMAL);
	 imshow("histogram",hist);
	 waitKey(2000); 
}

int main()
{
	Mat img=imread("samps/lowcontrast.PNG",0);
	Mat a(img.rows,img.cols,CV_8UC1,Scalar(0));
	float dat[256]={};
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			dat[img.at<uchar>(i,j)]++;
		}
	}
	dat[0]=dat[0]/(img.rows*img.cols);
	for (int i = 1; i < 256; i++)
	{
		//percent from no. of pixels
		dat[i]=dat[i]/(img.rows*img.cols);
		//cummulative percent
		dat[i]=dat[i]+dat[i-1];
	}
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			a.at<uchar>(i,j)=(dat[img.at<uchar>(i,j)]*255)/1;
		}
	}
	namedWindow("Original Image",WINDOW_NORMAL);
	imshow("Original Image",img);
	namedWindow("Equalized Image",WINDOW_NORMAL);
	imshow("Equalised Image",a);
	waitKey(2000);
	hist(img);
	hist(a);
	waitKey(2000);
}
