#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
	Mat img= imread("samps/joker.jpg",1);
	int cols=img.cols;
	int rows=img.rows;

	//Equal Width (.33,.33,.33)
	Mat b (rows,cols,CV_8UC1,Scalar(0));
	for (int j = 0; j < cols; j++)
	{
		for (int i = 0; i < rows; i++)
		{
			int ib= img.at<Vec3b>(i,j)[0];
			int ig= img.at<Vec3b>(i,j)[1];
			int ir= img.at<Vec3b>(i,j)[2];
			int igr= ((ib)+(ig)+(ir))/3;
			b.at<uchar>(i,j)=igr;
		}
	}

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
	namedWindow("Original",WINDOW_NORMAL);
	imshow("Original",img);
	namedWindow("EqWdth",WINDOW_NORMAL);
	imshow("EqWdth",a);
	namedWindow("UneqWdth",WINDOW_NORMAL);
	imshow("UneqWdth",b);
	waitKey(5000);
	
	return 0;
}