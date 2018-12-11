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


int main ()
{
	Mat img=imread("samps/erosion.png",0);
	Mat a=img.clone();
	int ctrw=0,ctrb=0,bg=0,obj=255;
	
	//for finding obj color
	for (int i = 0; i < img.rows; i++)
			{
				for (int j = 0; j < img.cols; j++)
				{
					if (img.at<uchar>(i,j)==0)
							{
								ctrb++;
							}
					else
					{ 
						ctrw++;
					}		
				}
			}
	if (ctrw>ctrb)
	{
		bg=255;
		obj=0;
	}
	//


	int n=1; //no. of cycles
	//createTrackbar("no. of cycles","image",&n,7);
	
	for (int i = 0; i < n; i++)
		{
			//Erosion
			for (int i = 0; i < img.rows; i++)
			{
				for (int j = 0; j < img.cols; j++)
				{
					if (a.at<uchar>(i,j)==obj)
					{
						for (int k = -1; k < 1; i++)
						{
							for (int l = -1; l < 1; j++)
							{
								if (Isvalid(i-k,j-l,img.rows,img.cols))
								{
									if (img.at<uchar>(i-k,j-l)==bg)
									{
										a.at<uchar>(i,j)==bg;
									}
								}
							}
						}
					}
				}
			}
			/*Dilation
			for (int i = 0; i < img.rows; i++)
			{
				for (int j = 0; j < img.cols; j++)
				{
					if (a.at<uchar>(i,j)==bg)
					{
						for (int k = -1; k < 1; i++)
						{
							for (int l = -1; l < 1; j++)
							{
								if (Isvalid(i-k,j-l,img.rows,img.cols))
								{
									if (img.at<uchar>(i-k,j-l)==obj)
									{
										a.at<uchar>(i,j)==obj;
									}
								}
							}
						}
					}
				}
			}*/
	}
	namedWindow("image",WINDOW_NORMAL);
	imshow("image",a);
	waitKey(0);
}