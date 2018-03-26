#include <iostream>
#include <cmath> 

using namespace std;

long double fib(int number)
{
	if (number == 1 || number == 2)
	{
		return 1;
	}
	return fib(number - 2) + fib(number - 1);
}

long double f(long double x)
{
	long double f = -(pow(x, 3) - pow(x, 2)) / 3 + 12;

	return f;
}

long double golden_search(long double a, long double b, long double e)
{
	
	long double h = (sqrt(5) - 1) / 2;
	long double x1 = a + (h / (h + 1)) * (b - a);
	long double x2 = a + b - x1;

	long double y1 = f(x1);
	long double y2 = f(x2);

	while ((b-a) > e)
	{
		y2 = f(x2);
		if (y2 > y1)
		{
			a = x1;
			x1 = x2;
			y1 = y2;
			x2 = a + b - x2;
		}
		else
		{
			b = x2;
			x2 = a + b - x1;
		}

		//cout << "a = " << a << "\tb = " << b << endl;
	}

	long double x_star = (a + b) / 2;
	return x_star;
}

long double g_search(long double a, long double b, long double e)
{
	long double phi = (1 + sqrt(5)) / 2;

	long double x1 = b - (b - a) / phi;
	long double x2 = a + (b - a) / phi;
	long double y1 = f(x1);
	long double y2 = f(x2);

	while (abs(b-a) >= e)
	{
		x1 = b - (b - a) / phi;
		x2 = a + (b - a) / phi;
		y1 = f(x1);
		y2 = f(x2);

		if (y1 <= y2)
		{
			a = x1;
		}
		else
		{
			b = x2;
		}
		//cout << "a = " << a << "\tb = " << b << endl;
	}

	
	long double result = (a + b) / 2;
	return result;
}

long double fib_search(long double a, long double b, int n)
{
	long double x1 = a + (b - a) * (fib(n - 2) / fib(n));
	long double x2 = a + (b - a) * (fib(n - 1) / fib(n));

	long double y1 = f(x1);
	long double y2 = f(x2);

	while (n != 1)
	{
		n = n - 1;
		if (y1 < y2)
		{
			a = x1;
			x1 = x2;
			x2 = b - (x1 - a);
			y1 = y2;
			y2 = f(x2);
		}
		else
		{
			b = x2;
			x2 = x1;
			x1 = a + (b - x2);
			y2 = y1;
			y1 = f(x1);
		}
	}
	long double result = (x1 + x2) / 2;
	return result;
}


long double univeral_search(long double a, long double b, long double h, int n)
{
	long double x1 = a + (b - a) * h;
	long double x2 = b - x1;
	long double y1 = f(x1);
	long double y2 = f(x2);

}

int main()
{
	//cout << fib(30) << endl;

	long double gold = golden_search(-1, 3, 0.000001);
	long double fib_res = fib_search(-1, 3, 30);

	
	cout << gold << endl;
	cout << fib_res << endl;
	cout << f(gold) << "\t" << f(fib_res);

	return 0;
}
