#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;

int main()
{
	namedWindow("win",WINDOW_NORMAL);
	namedWindow("win2",WINDOW_NORMAL);
	Mat a=imread("rubik.jpg",1);
	Mat b;
	Mat c;

	int ker=1,lt=50,ht=100,ker2=1;
	createTrackbar("ker_gauss","win2",&ker,25);
	createTrackbar("low_th","win2",&lt,255);
	createTrackbar("high_th","win2",&ht,255);
	createTrackbar("ker2_canny","win2",&ker2,2);
	while(1)
	{
		GaussianBlur(a,b,Size(2*ker+1,2*ker+1),0);
		
		Canny(b,c,lt,ht,2*ker2+3);
		imshow("win",c);
		waitKey(1);
	}
}