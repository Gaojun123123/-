#include<iostream>
#include<string>
using namespace std;

string str;

int num[4];//4��λ�õ�ip 
// 8λ��Ӧһ������ ��8λ����ת�� 
void change(string str)
{
	int res=0;//�洢��Ӧ��ʮ����
	for(int i=0;i<4;i++)
	{//ȥ��һ��
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
	cin>>str;//����ip��ַ

	//ת�����ַ���
	change(str);
	
	for(int i=0;i<4;i++)
	{
		if(i==3)cout<<num[i]; 
		else
		cout<<num[i]<<'.'; 
	}
		
}
