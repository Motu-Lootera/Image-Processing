#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
	Mat img= imread("/home/arnesh/IP/samps/fruits.png",1);
	int rows=img.rows;
	int cols=img.cols;
	Mat a (rows,cols,CV_8UC3,Scalar(255,255,255));
	int rm=0,rM=255,bm=0,bM=255,gm=0,gM=255;
	namedWindow("Image",WINDOW_NORMAL);
	createTrackbar("rMin","Image",&rm,255);
	createTrackbar("rMax","Image",&rM,255);
	createTrackbar("gMin","Image",&gm,255);
	createTrackbar("gMax","Image",&gM,255);
	createTrackbar("bMin","Image",&bm,255);
	createTrackbar("bMax","Image",&bM,255);

	while (1)
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					int ib= img.at<Vec3b>(i,j)[0];
					int ig= img.at<Vec3b>(i,j)[1];
					int ir= img.at<Vec3b>(i,j)[2];
					if ((bm<ib) && (bM>ib) && (gm<ig) && (gM>ig) && (rm<ir) && (rM>ir))
					{
						a.at<Vec3b>(i,j)=img.at<Vec3b>(i,j);
					}
					else
					{
						a.at<Vec3b>(i,j)=255;
					}

										
				}
			}
		imshow("Image",a);
		waitKey(1);
		
		}
}