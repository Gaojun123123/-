#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int N=30;
int cnt;//记录单词个数 
string strs[N];//输入单词数组
string str;

int sizes[N];//长度的数字 

int main()
{
	cin>>str;
	while(str!="#")
	{
	sizes[cnt]=str.size();
	strs[cnt++]=str;

		cin>>str;
	}
	

	//冒泡排序，是保序的 

	for(int i=0;i<cnt;i++)
	{
		for(int j=i;j<cnt;j++)
		{
			//先选出最小的长度放前面 
			if(sizes[i]>sizes[j])//长度小的放前
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


