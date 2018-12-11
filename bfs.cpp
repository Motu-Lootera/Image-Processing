#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <queue>
using namespace std;
using namespace cv;

//for move validity
int isvalid(int x,int y,int rows,int cols)
{
	if (x<0||y<0||x>=rows||y>=cols)
	{
		return 0;
	}
	return 1;
}

int main()
{
	Mat img=imread("samps/",0);
	//mat for verifying if in queue[0] or has been visited[1]
	Mat ver(img.rows,img.cols,CV_8UC1,Scalar(0));
	queue <Point> curr;
	curr.push({0,0});  //pushing initial point
	ver.at<uchar>(0,0)=255;  //putting (0,0) in queue
	namedWindow("image",WINDOW_NORMAL);
	while (!curr.empty())  //runs while queue isn't empty
	{
		Point ptr=curr.front();
		if (ver.at<uchar>(ptr.x,ptr.y)==255)
		{
			curr.pop();
		}
		for (int k = -1; k < 1; k++)
		{
			for (int l = -1; l < 1; l++)
			{
				if (isvalid(ptr.x-k,ptr.y-l,img.rows,img.cols) && ver.at<uchar>(ptr.x-k,ptr.y-l)==0)
				{
					curr.push({ptr.x-k,ptr.y-l});

				}
			}
		}
		ver.at<uchar>(ptr.x,ptr.y)=255;
		curr.pop();
		imshow("image",ver);
		waitKey(1);
	}	
}