#include"Trapzint.h"
#include<cmath>
//被积函数
double MyFunction::operator () (double x) const
{
	return log(1.0+x)/(1.0+x*x);
}
//积分运算过程，重载为运算符()
double Trapz::operator () (double a,double b,double eps) const
{
	bool done = false; //是Trapz类的虚函数成员
	int n = 1;
	double h = b-a;
	double tn = h * (f(a)+f(b))/2; //计算n=1时的积分值
	double t2n;
	do
	{
		double sum = 0;
		for (int k = 0; k < n; ++k)
		{
			double x = a + (k + 0.5) * h;
			sum+=f(x);
		}
		t2n = (tn + h*sum)/2.0;
		if (fabs(t2n-tn) < eps)
			done = true;
		else 
		{
			tn = t2n;
			n * = 2;
			h / = 2;
		}
	} while(!done);
	return t2n;
}
