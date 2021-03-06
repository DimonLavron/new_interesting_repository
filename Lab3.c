//empty comment
#include <stdio.h>
#include <math.h>

int matrix[7][7];

void insertionSortOfRowsByDescending()
{
	extern int matrix[7][7];
	int temporaryValue;
	for (int k = 0; k < 5; k++)
	{
		for (int i = 1; i < 5; i++)
		{
			temporaryValue = matrix[k][i];
			for (int j = i - 1; j >= 0; j--)
			{
				if (temporaryValue > matrix[k][j])
					matrix[k][j + 1] = matrix[k][j];
				else
					break;
			}
			matrix[k][j + 1] = temporaryValue;
		}
	}
}

int sumOfElementsUnderMainDiag(int columnNumber)
{
	int sumOfColumn = 0;
	for (int i = columnNumber + 1; i < 5; i++)
		sumOfColumn += matrix[i][columnNumber];
	return sumOfColumn;
}

int main()
{
	extern int matrix[7][7];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf_s("%d", &matrix[i][j]);

	insertionSortOfRowsByDescending();

	printf("\n\n");
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("%4d ", matrix[i][j]);
		printf("\n");
	}

	printf("\n\n");
	
	int geometricMean = 1;

	for (int i = 0; i < 4; i++)
	{
		int sumOfElements = int sumOfElementsUnderMainDiag(i);
		geometricMean *= sumOfElements;
		printf("%d ", sumOfElements);
	}

	printf("\n%lf\n", pow(abs(geometricMean), 1.0/4.0));
}