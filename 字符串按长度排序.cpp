#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int N=30;
int cnt;//��¼���ʸ��� 
string strs[N];//���뵥������
string str;

int sizes[N];//���ȵ����� 

int main()
{
	cin>>str;
	while(str!="#")
	{
	sizes[cnt]=str.size();
	strs[cnt++]=str;

		cin>>str;
	}
	

	//ð�������Ǳ���� 

	for(int i=0;i<cnt;i++)
	{
		for(int j=i;j<cnt;j++)
		{
			//��ѡ����С�ĳ��ȷ�ǰ�� 
			if(sizes[i]>sizes[j])//����С�ķ�ǰ
			{
				swap(strs[i],strs[j]);
				swap(sizes[i],sizes[j]);
			} 
		}
	}

	//
for(int i=0;i<cnt;i++)
{
   cout<<strs[i]<<' ' ;
}
} 


