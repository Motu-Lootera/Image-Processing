#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;
//Arnesh Kumar Issar
int main(int argc, char const *argv[])
{
	Mat img= imread("/home/arnesh/IP/samps/joker.jpg",1);
	int cols=img.cols;
	int rows=img.rows;

	//Unequal Width (.11,.58,.299)
	Mat a (rows,cols,CV_8UC1,Scalar(0));
	for (int j = 0; j < cols; j++)
	{
		for (int i = 0; i < rows; i++)
		{
			int ib= img.at<Vec3b>(i,j)[0];
			int ig= img.at<Vec3b>(i,j)[1];
			int ir= img.at<Vec3b>(i,j)[2];
			int igr= ((.11*ib)+(.58*ig)+(.299*ir));
			a.at<uchar>(i,j)=igr;
		}
	}
	Mat b (rows,cols,CV_8UC1,Scalar(0));
	int th=1; //Threshold Valu
	namedWindow("B&W",WINDOW_NORMAL);
	createTrackbar("Threshold","B&W",&th,255);
	while (1)
		{	
		for (int j = 0; j < cols; j++)
		{
			for (int i = 0; i < rows; i++)
			{
				if (a.at<uchar>(i,j)<=th)
				{
					b.at<uchar>(i,j)=0;	
				}
				else if (a.at<uchar>(i,j)>=th)
				{
	
					b.at<uchar>(i,j)=255;
				}
			}
		}
		imshow("B&W",b);
		waitKey(1);
		}
}