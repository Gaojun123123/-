#include<iostream>
#include<stdio.h>
using namespace std;//������

const int N =1000;
int s[N] ;//�������
int cnt;//��¼�����ĸ���

int n,k;

//�ж����� 

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
	  //����������s
	  s[cnt++]=i;	
	}
	}
 
 int sum=0;
 //��ӡ��� 
 for(int i=0;i<k&&cnt>0;i++)
 {
 	sum+=s[cnt-1];
 	if(cnt==1||i==k-1)printf("%d",s[--cnt]);
 	else
 	printf("%d+",s[--cnt]);
 } 
 
 printf("=%d",sum);
	
} 

