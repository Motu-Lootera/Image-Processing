#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include<stack>
#include<vector>
using namespace cv;
using namespace std;
struct node
{
int x,y;
bool val=true;
};
	
int main()
{	
	int i,j;
	stack <node> abc;
	Mat a= imread("lena.png",0);
	Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
	node arr[a.rows][a.cols];
	namedWindow("window1",WINDOW_NORMAL);
	
	for(i=0;i<a.rows;i++)
	{
		for(j=0;j<a.cols;j++)
		{
			arr[i][j].x=i;
			arr[i][j].y=j;
		}
	}
	i=0;
	j=0;
	do
	{		
			
			
			
			if(arr[i][j+1].val&&(j<a.rows-1))
			{
				abc.push(arr[i][j]);
				b.at<uchar>(arr[i][j].x,arr[i][j].y)=255;
				arr[i][j++].val=false;
				
			}
			else if (arr[i+1][j].val&&(i<a.cols-1))
			{
				abc.push(arr[i][j]);
				b.at<uchar>(arr[i][j].x,arr[i][j].y)=255;
				arr[i++][j].val=false;
			
			}
			else if (arr[i-1][j].val&&(i>0))
			{
				abc.push(arr[i][j]);
				b.at<uchar>(arr[i][j].x,arr[i][j].y)=255;
				arr[i--][j].val=false;
			
			}
			else if (arr[i][j-1].val&&(j>0))
			{
				abc.push(arr[i][j]);
				b.at<uchar>(arr[i][j].x,arr[i][j].y)=255;
				arr[i][j--].val=false;
			
			}
			else 
			{	
				abc.pop();
				node temp=abc.top();
				i=temp.x;
				j=temp.y;
			}
			
			imshow("window1",b);
			waitKey(1);
			
	  }while(!abc.empty());
	  	  				
}	
			
