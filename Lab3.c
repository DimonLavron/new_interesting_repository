//empty comment
#include <stdio.h>
#include <math.h>

int a[7][7];

void sort()
{
	extern int a[7][7];
	int x;
	for (int k = 0; k < 5; k++)
	{
		for (int i = 1; i < 5; i++)
		{
			x = a[k][i];
			int j;
			for (j = i - 1; j >= 0; j--)
			{
				if (x > a[k][j])
					a[k][j + 1] = a[k][j];
				else
					break;
			}
			a[k][j + 1] = x;
		}
	}
}

int f(int k)
{
	int res = 0;
	for (int i = k + 1; i < 5; i++)
		res += a[i][k];
	return res;
}

int main()
{
	extern int a[7][7];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf_s("%d", &a[i][j]);

	sort();

	printf("\n\n");
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("%4d ", a[i][j]);
		printf("\n");
	}

	printf("\n\n");
	
	int F = 1;

	for (int i = 0; i < 4; i++)
	{
		int x = f(i);
		F = F * x;
		printf("%d ", x);
	}

	printf("\n%lf\n", pow(abs(F), 1.0/4.0));
}