#include <iostream>
#include <cmath>

using namespace std;

const double delta = 1e-8;

double f(double y, double n)    //x为初值
{
	for(int i=0;i<100;i++)//迭代100次 
	{
	 y = 0.5*(y+n/y);  //更新的xn 
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
