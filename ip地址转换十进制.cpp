#include<iostream>
#include<string>
using namespace std;

string str;

int num[4];//4个位置的ip 
// 8位对应一个数字 ，8位进行转化 
void change(string str)
{
	int res=0;//存储对应的十进制
	for(int i=0;i<4;i++)
	{//去除一个
	  for(int j=0;j<8;j++) 
		{
			if(str[i*8+j]=='1')
			num[i]=num[i]*2+1;
			else
			num[i]=num[i]*2; 
		}
	}
	 
} 

int main()
{
	cin>>str;//输入ip地址

	//转换成字符串
	change(str);
	
	for(int i=0;i<4;i++)
	{
		if(i==3)cout<<num[i]; 
		else
		cout<<num[i]<<'.'; 
	}
		
}
