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
	int k=0;//��ʾ��ǰ�ķ��� 
   for(int i=1,x=0,y=0;i<=n*n;i++)
   {
   	    q[y][x]=i;
   	    st[y][x]=true;
   	    //a���У�b���� 
   		int a=x+dx[k],b=y+dy[k];
   		//���û��������ΪԽ�� 
   		if(!st[b][a]&&0<=a&&a<n&&b>=0&&b<n) //��Խ��ʱ���л�����
		{	
   		  x=a,y=b;	
         }else{
		 //����һ������
		 k=(k+1)%4; 
		 a=x+dx[k],b=y+dy[k];
		   x=a,y=b;
		 }
         } 
} 
int main()
{
cin>>n;
	//��ӡ��������
	luoxuan();
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		{
			printf("%3d",q[i][j]);
		}
		printf("\n");
	}
	
	
	 
}
