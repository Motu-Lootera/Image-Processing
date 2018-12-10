#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
	Mat img= imread("/home/arnesh/IP/samps/joker.jpg",1);
	int cols=img.cols;
	int rows=img.rows;
	Mat a(rows,cols,CV_8UC3,Scalar(0,0,0));
	for (int j = 0; j < cols; j++)
		for (int i = 0; i < rows; i++)
		{
			int ib= img.at<Vec3b>(i,j)[0];
			int ig= img.at<Vec3b>(i,j)[1];
			int ir= img.at<Vec3b>(i,j)[2];
			a.at<Vec3b>(i,j)={255-ib,255-ig,255-ir};
		}
	/*namedWindow("Original",WINDOW_NORMAL);
	imshow("Original",img);*/
	namedWindow("Negative",WINDOW_NORMAL);
	imshow("Negative",a);
	waitKey(5000);
}
