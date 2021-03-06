#include<iostream>
#include<stdio.h>
using namespace std;//求素数

const int N =1000;
int s[N] ;//存放素数
int cnt;//记录素数的个数

int n,k;

//判断素数 

bool ispri(int x)
{
	if(x==1)return false;
 	for(int i=2;i<=x/i;i++ )
 	{
 		if(x%i==0)
 		{
 			return false;
		 } 
 	}
 
 	return true;
} 

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
	if(ispri(i))
	{
	  //是素数加入s
	  s[cnt++]=i;	
	}
	}
 
 int sum=0;
 //打印结果 
 for(int i=0;i<k&&cnt>0;i++)
 {
 	sum+=s[cnt-1];
 	if(cnt==1||i==k-1)printf("%d",s[--cnt]);
 	else
 	printf("%d+",s[--cnt]);
 } 
 
 printf("=%d",sum);
	
} 

