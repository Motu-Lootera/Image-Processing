#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <queue>
using namespace std;
using namespace cv;

Mat a=imread("binary1_shrink.png",0);
//bool vis[a.rows][a.cols]={};
//bool add[a.rows][a.cols]={};

//bool vis[100][100]={};
const int row=a.rows,col=a.cols;
bool ad[209][400]={};

struct node
{
	int i;
	int j;
};
queue<node> qu;

bool isValid(int i,int j)
{
	if(i<0||j<0||i>=a.rows||j>=a.cols)
		return 0;
	if(ad[i][j])
		return 0;
	if(a.at<uchar>(i,j)!=0)
		return 0;
	return 1;
}

void add_qu(node x)
{
	if(isValid(x.i,x.j+1))
	{
		node tmp={x.i,x.j+1};
		qu.push(tmp);
		ad[x.i][x.j+1]=1;
	}
	if(isValid(x.i+1,x.j))
	{
		node tmp={x.i+1,x.j};
		qu.push(tmp);
		ad[x.i+1][x.j]=1;
	}
	if(isValid(x.i-1,x.j))
	{
		node tmp={x.i-1,x.j};
		qu.push(tmp);
		ad[x.i-1][x.j]=1;
	}
	if(isValid(x.i,x.j-1))
	{
		node tmp={x.i,x.j-1};
		qu.push(tmp);
		ad[x.i][x.j-1]=1;
	}
}

int main()
{	
	namedWindow("window1",WINDOW_NORMAL);
	node c={0,0};
	qu.push(c);
	ad[0][0]=1;

	while(!qu.empty())
	{
		c=qu.front();
		qu.pop();
		add_qu(c);

		a.at<uchar>(c.i,c.j)=100;
		imshow("window1",a);
		//waitKey(1);
	}
	
	//cout<<counter<<endl;
	imshow("window1",a);
	waitKey(0);
}