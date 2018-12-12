#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;

int main()
{
	namedWindow("window1",WINDOW_NORMAL);
	Mat a=imread("samps/erosion.png",0);
	int f=1;
	createTrackbar("threshold","window1",&f,10);
	int f2=f-1;
	Mat b=a.clone(),c;
	while(1)
	{
		if(f2==f+234)
		{/*
			imshow("window1",c);
			waitKey(1);
			continue;*/
		}
		else
		{
			b=a.clone();
			f2=f;
			Mat img=a.clone();
			c=img.clone();
			while(f2--)
			{
				//erosion
				img=c.clone();
				for(int i=1;i<a.rows-1;i++)
				{
					for(int j=1;j<a.cols-1;j++)
					{
						if(a.at<uchar>(i,j)==255)
						{
							for(int k=-1;k<2;k++)
							{
								for(int l=-1;l<2;l++)
								{
									if(img.at<uchar>(i+k,j+l)==0)
									{
										b.at<uchar>(i,j)=0;
									}
								}
							}
						}
					}
				}

				//dilation
				c=b.clone();
				for(int i=1;i<a.rows-1;i++)
				{
					for(int j=1;j<a.cols-1;j++)
					{
						if(b.at<uchar>(i,j)==0)
						{
							for(int k=-1;k<2;k++)
							{
								for(int l=-1;l<2;l++)
								{
									if(b.at<uchar>(i+k,j+l)==255)
									{
										c.at<uchar>(i,j)=255;
									}
								}
							}
						}
					}
				}
			}
			f2=f;
			imshow("window1",b);
			waitKey(1);
		}
	}
	
}