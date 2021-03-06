#include<iostream>
#include<stdio.h>

using namespace std;

const int N=20;
 
int q[N][N];
bool st[N][N];
int n;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void luoxuan()
{
	int k=0;//表示当前的方向 
   for(int i=1,x=0,y=0;i<=n*n;i++)
   {
   	    q[y][x]=i;
   	    st[y][x]=true;
   	    //a是行，b是列 
   		int a=x+dx[k],b=y+dy[k];
   		//如果没被访问且为越界 
   		if(!st[b][a]&&0<=a&&a<n&&b>=0&&b<n) //当越界时，切换方向
		{	
   		  x=a,y=b;	
         }else{
		 //否则换一个方向
		 k=(k+1)%4; 
		 a=x+dx[k],b=y+dy[k];
		   x=a,y=b;
		 }
         } 
} 
int main()
{
cin>>n;
	//打印螺旋数组
	luoxuan();
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		{
			printf("%3d",q[i][j]);
		}
		printf("\n");
	}
	
	
	 
}
