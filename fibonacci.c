#include <stdio.h>

int fibo(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return (fibo(n - 1) + fibo(n - 2));
}

int main()
{
	int n;
	scanf_s("%d", &n);
	printf("%d\n",fibo(n));
	return 0;
}
