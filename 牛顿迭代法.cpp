#include <iostream>
#include <cmath>

using namespace std;

const double delta = 1e-8;

double f(double y, double n)    //xΪ��ֵ
{
	for(int i=0;i<100;i++)//����100�� 
	{
	 y = 0.5*(y+n/y);  //���µ�xn 
	 printf("y=%lf\n",y); 
	}
   

  return y;
}

int main()
{
    double n;

    scanf("%lf", &n);

    printf("%.6lf\n", f(1, n));

    return 0;
}
