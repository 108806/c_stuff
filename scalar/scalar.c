#include <stdio.h>

void scalarMult(int nRows, int nCols,
		int matrix[nRows][nCols], int scalar)
{
	int row, column;
	for (row = 0 ; row < nRows ; ++row)
	{
		for (column = 0 ; column < nCols ; column++)
		{
			matrix[row][column] *= scalar;
		}
	}
}

void displayMatrix(int nRows, int nCols, int matrix[nRows][nCols])
{
	int row, column;
	for (row = 0 ; row < nRows ; ++row)
	{
		for (column = 0 ; column < nCols ; ++column)
			printf("%5i", matrix[row][column]);
			
		printf("\n");
	}
}




int main(void)
{
	void scalarMult(int nRows, int nCols,
		int matrix[nRows][nCols], int scalar);

	void displayMatrix(int nRows, int nCols, int matrix[nRows][nCols]);

	int sampleMatrix[3][5] = 
	{
		{2, 8, 4, 10, 6},
		{7, 5, 3, 13, 15},
		{-2, -7, -11, -8, -6}
	};

	printf("Original Matrix:\n") ; displayMatrix(3,5, sampleMatrix);


	scalarMult(3,5, sampleMatrix, 2);
	printf("Matrix multiplied:\n");
	displayMatrix(3, 5, sampleMatrix);

	printf("Now multiplied by -1:\n") ; displayMatrix(3, 5, sampleMatrix);
	return 0;

}
