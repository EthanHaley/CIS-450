#include <stdio.h>
#include <sys/time.h>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int main()
{
	struct timeval timeBeforeInit, timeAfterInit, timeBeforeBlock, timeAfterBlock, timeBeforeSimple, timeAfterSimple, timeStart, timeEnd;
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
	printf("Starting initialization...\n");
	gettimeofday(&timeBeforeInit, NULL);
	for(i=0; i < n; i++){
		for(j =0; j < n; j++){
			matrix[i][j] = rand();
		}
	}	
	gettimeofday(&timeAfterInit, NULL);
	printf("Initialization has ended.\n");
	elapsedTime = ((timeAfterInit.tv_sec - timeBeforeInit.tv_sec) +
					(timeAfterInit.tv_usec - timeBeforeInit.tv_usec)/1000000.0);
	printf("  ");
	printf("Time for initialization : %f Seconds \n", elapsedTime);
		
	int result[n][n];
	
    printf("Starting block based multiplication...\n");
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
	gettimeofday(&timeAfterBlock, NULL);
	printf("Block based multiplication has ended.\n");
	elapsedTime = ((timeAfterBlock.tv_sec - timeBeforeBlock.tv_sec) +
					(timeAfterBlock.tv_usec - timeBeforeBlock.tv_usec)/1000000.0);
	printf("  ");
	printf("Time for block based multiplication : %f Seconds \n", elapsedTime);
	
	
	printf("Starting simple multiplication...\n");
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
	
	
	gettimeofday(&timeAfterSimple, NULL);
	printf("Simple multiplication has ended.\n");
	elapsedTime = ((timeAfterSimple.tv_sec - timeBeforeSimple.tv_sec) +
					(timeAfterSimple.tv_usec - timeBeforeSimple.tv_usec)/1000000.0);
	printf("  ");
	printf("Time for simple multiplication : %f Seconds \n", elapsedTime);
	
	
	gettimeofday(&timeEnd, NULL);
	elapsedTime = ((timeEnd.tv_sec - timeStart.tv_sec) +
					(timeEnd.tv_usec - timeStart.tv_usec)/1000000.0);
	printf("Total execution time : %f Seconds \n", elapsedTime);
	
    return 0;
}