#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;
 
int Isvalid(int x,int y,int rows,int cols)
{
	if (x<0||y<0||x>=rows||y>=cols)
	{
		return 0;
	}
	return 1;
}

int fill(int x,int y,int var, Mat img)
{
	// Mat img=imread("samps/veg.jpg",0);
	int sum=0, val=0;
	for (int i = -var; i < var+1; i++)
	{
		for (int j = -var; j < var+1; j++)
		{
			if (Isvalid(x-i,y-j,img.rows,img.cols))
			{
				sum+=img.at<uchar>(x-i,y-j);
				val++;
			}
			
		}
	}
	return (sum/val);
}


int main()
{
 	Mat img=imread("samps/veg.jpg",0);
 	Mat img1 = img.clone();
	namedWindow("image",WINDOW_NORMAL);
	int var=0;
	createTrackbar("Kernel Size","image",&var,33);
	while (1)
	{
		int ks=2*var+1;
		for (int i = 0; i < img.rows; i++)
		{	
			for (int j = 0; j < img.cols; j++)
			{
				img1.at<uchar>(i,j)=fill(i,j,var, img);
			}
		}
	imshow("image",img1);
	waitKey(1);
	}

}