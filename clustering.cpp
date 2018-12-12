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
	if(a.at<uchar>(i,j)!=255)
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
{	int counter=0;
	int color=50;
	for(int i=0;i<a.rows;i++)
	{
		for(int j=0;j<a.cols;j++)
		{
			if(a.at<uchar>(i,j)==255)
			{
				node curr={i,j};
				qu.push(curr);
				ad[i][j]=1;
				color=(color+68)%150;
				//vis[50][50]=1;

				namedWindow("window1",WINDOW_NORMAL);
				while(!qu.empty())	
				{
					curr=qu.front();
					qu.pop();
					add_qu(curr);

					a.at<uchar>(curr.i,curr.j)=color;
					imshow("window1",a);
					waitKey(1);	
				}
				counter++;
			}
		}
	}
	
	cout<<counter<<endl;
	imshow("window1",a);
	waitKey(0);
}