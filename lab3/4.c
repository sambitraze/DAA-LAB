/*
4.	Consider an n × n matrix A = (aij), each of whose elements aij 
is a nonnegative real number, and suppose that each row and column 
of A sums to an integer value. We wish to replace each element aij 
with either ˥ aij ˥ or ˩ aij ˩ without disturbing the row and 
column sums.

Write a program by defining an user defined function that is used 
to produce the rounded matrix as described in the above example. 
Find out the time complexity of your algorithm/function.
*/

#include <stdio.h>
#include <time.h>

void modifyMatrix(float matrix[][100], int size)
{
    float dec[size][size];
    float rowSum[size];
    float colSum[size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            dec[i][j] = matrix[i][j] - (int)matrix[i][j];
        }
    }
    for (int i = 0; i < size; i++)
    {
        float sum = 0.0;
        for (int j = 0; j < size; j++)
        {
            sum+=dec[i][j];
        }
        rowSum[i] = sum;
    }
    for (int i = 0; i < size; i++)
    {
        float sum = 0.0;
        for (int j = 0; j < size; j++)
        {
            sum += (matrix[i][j] - (int)(matrix[i][j]));
        }        
        colSum[i] = sum;
    }
    for (int i = 0; i < size; i++) {
		for (int j = 0; j < rowSum[i]; j++) {
			if (colSum[j] == 0) {
				dec[i][j] = 0;
				continue;
			}
			dec[i][j] = 1;
			colSum[j]--;
		}
	}


	for (int i = 0; i < size; i++) {
		for (int j = 0; j < colSum[i]; j++) {
			if (rowSum[j] == 0) {
				dec[j][i] = 1;
				continue;
			}
			dec[j][i] = 0;
			rowSum[j]--;
		}
	}
    printf("\nThe modified matrix is:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d\t", (int)(matrix[i][j]) + (int)(dec[i][j]));
        }
        printf("\n");
    }
}

int main()
{
    clock_t start, end;
    double timeTaken;

    start = clock();

    float matrix[100][100];
    int size;
    int result[100][100];

    printf("\nEnter the size of matrix: ");
    scanf("%d", &size);

    printf("\nEnter the elements of the matrix:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("Element[%d,%d]: ", i, j);
            scanf("%f", &matrix[i][j]);
        }
    }

    printf("\nThe original matrix is:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    }

    modifyMatrix(matrix, size);    

    end = clock();

    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime Taken: %f\n\n", timeTaken);

    return 0;
}
