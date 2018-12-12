#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <math.h>
#define PI 3.1415
using namespace std;
using namespace cv;

int main()
{
	Mat img=imread("samps/A1.png",0);
	Mat a(100,100,CV_8UC1,Scalar(0));
	int ctr=0 th=255;
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{	
			if (img.at<uchar>(i,j)==255)
			{
				//cout << Point {i,j} << endl;
				ctr=0;
				for (float th = 0; th <= 2*PI; th+=((2*PI)/100))
				{
					//cout << ctr <<endl;
					float r=(i*sin(th)) + (j*cos(th));
					//cout << Point {r/10,ctr} << endl ;
					if (r>0)
					{
						a.at<uchar>(r/10,ctr)+=1;
					}
					ctr++;
				}
			}
		}
	}
	namedWindow("graph",WINDOW_NORMAL);
	imshow("graph",a);
	waitKey(2000);
}