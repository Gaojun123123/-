### 在计算机中的硬件并没有实现根号的运算，那么计算机是怎么进行解决的呢



有许多算法，但牛顿迭代法绝对是一个效率高的算法

应用领域很广。

下面推到y=根号x

即求 y^2=x，给一个x,求出y，迭代法适合求凹型的，这个是凸性的，要转化一下坐标系，以y轴为来看，是一个凹形的

因为 x-x0=x0'(y-y0)        --切线方程（1阶泰勒）

![image-20210329135130565](../AppData/Roaming/Typora/typora-user-images/image-20210329135130565.png)





实现代码：

```c++
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

```

