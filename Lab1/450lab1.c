#include <stdio.h>
#include <sys/time.h>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int main()
{
	struct timeval timeBeforeInit, timeAfterInit, timeBeforeBlock, timeAfterBlock, timeBeforeSimple, timeAfterSimple, timeStart, timeEnd, t1, t2, t3, t4;
	gettimeofday(&timeStart, NULL);
	int n;
	printf("Size of array : " );
	scanf("%d", &n);
	printf("\n");
    int matrix [n][n];
	int i, j, k, temp, l, m, blockSize;
	blockSize = 4;
	double elapsedTime;
	srand(time(NULL));
	
	gettimeofday(&timeStart, NULL);
	gettimeofday(&timeBeforeInit, NULL);
	for(i=0; i < n; i++){
		for(j =0; j < n; j++){
			matrix[i][j] = rand();
		}
	}	
	gettimeofday(&timeAfterInit, NULL);
	elapsedTime = ((timeAfterInit.tv_sec - timeBeforeInit.tv_sec) +
					(timeAfterInit.tv_usec - timeBeforeInit.tv_usec)/1000000.0);
		
	int result[n][n];
	
    gettimeofday(&timeBeforeBlock, NULL);
	
	int x, y;
	for (i = 0; i < n; i += blockSize)
	{		
		for (j = 0; j < n; j += blockSize) 
		{
			for (x = i; x < MIN(i + blockSize, n); x++) 
			{
				for (y = j; y < MIN(j + blockSize, n); y++) 
				{
					result[x][y] = 0;
					for(k = 0; k < blockSize; k++)
					{
						result[x][y] = matrix[x][k] * matrix[k][y];
					}
				}	
			}
		}

    }
	
	gettimeofday(&timeAfterBlock, NULL);
	elapsedTime = ((timeAfterBlock.tv_sec - timeBeforeBlock.tv_sec) +
					(timeAfterBlock.tv_usec - timeBeforeBlock.tv_usec)/1000000.0);
	printf("Time for block based ij multiplication : %f Seconds \n", elapsedTime);
	
	gettimeofday(&t3, NULL);	
	for (j = 0; j < n; j += blockSize)
	{		
		for (i = 0; i < n; i += blockSize) 
		{
			for (x = i; x < MIN(i + blockSize, n); x++) 
			{
				for (y = j; y < MIN(j + blockSize, n); y++) 
				{
					result[x][y] = 0;
					for(k = 0; k < blockSize; k++)
					{
						result[x][y] = matrix[x][k] * matrix[k][y];
					}
				}	
			}
		}

    }
	
	gettimeofday(&t4, NULL);
	elapsedTime = ((t4.tv_sec - t3.tv_sec) +
					(t4.tv_usec - t3.tv_usec)/1000000.0);
	printf("Time for block based ji multiplication : %f Seconds \n", elapsedTime);
	
	/*for(i = 0; i < n; i++)
	{
		printf("\n");
		for(j = 0; j < n; j++)
		{
			printf(" ");
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
	
	
	printf("Matrix after block \n");
	for(i = 0; i < n; i++)
	{
		printf("\n");
		for(j = 0; j < n; j++)
		{
			printf(" ");
			printf("%d", result[i][j]);
		}
		printf("\n");
	}
	*/	
	
	
	
    gettimeofday(&timeBeforeSimple, NULL);
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			result[i][j] = 0;
			for(k = 0; k < n; k++)
			{
				result[i][j] = matrix[i][k] * matrix[k][j];
			}
		}
	}
	
	gettimeofday(&timeAfterSimple, NULL);
	elapsedTime = ((timeAfterSimple.tv_sec - timeBeforeSimple.tv_sec) +
					(timeAfterSimple.tv_usec - timeBeforeSimple.tv_usec)/1000000.0);
	printf("Time for simple ij multiplication : %f Seconds \n", elapsedTime);
	
	
	gettimeofday(&t1, NULL);
	for(j = 0; j < n; j++)
	{
		for(i = 0; i < n; i++)
		{
			result[i][j] = 0;
			for(k = 0; k < n; k++)
			{
				result[i][j] = matrix[i][k] * matrix[k][j];
			}
		}
	}
	
	gettimeofday(&t2, NULL);
	elapsedTime = ((t2.tv_sec - t1.tv_sec) +
					(t2.tv_usec - t1.tv_usec)/1000000.0);
	printf("Time for simple ji multiplication : %f Seconds \n", elapsedTime);
	
	
	/*printf("Matrix after simple \n");
	for(i = 0; i < n; i++)
	{
		printf("\n");
		for(j = 0; j < n; j++)
		{
			printf(" ");
			printf("%d", result[i][j]);
		}
		printf("\n");
	}
	*/
	
	
	
	
	
	gettimeofday(&timeEnd, NULL);
	elapsedTime = ((timeEnd.tv_sec - timeStart.tv_sec) +
					(timeEnd.tv_usec - timeStart.tv_usec)/1000000.0);
	printf("Total execution time : %f Seconds \n", elapsedTime);
	
    return 0;
}