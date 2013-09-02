#include <stdio.h>
#include <sys/time.h>

int main()
{
	struct timeval t1, t2;
    int matrix [300][300];
	int i, j, k, temp;
	srand(time(NULL));
	for(i=0; i < 300; i++){
		for(j =0; j < 300; j++){
			matrix[i][j] = rand();
		}
	}	
	
	/*for(i = 0; i < 300; i++)
	{
		printf("\n");
		for(j = 0; j < 300; j++)
		{
			printf(" ");
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}*/
	
	int result[300][300];
	

    double elapsedTime;
    gettimeofday(&t1, NULL);
	for(i = 0; i < 300; i++)
	{
		for(j = 0; j < 300; j++)
		{
			temp = 0;
			for(k = 0; k < 300; k++)
			{
				temp += matrix[i][k] * matrix[k][j];
			}
            result[i][j] = temp;
		}
	}
	gettimeofday(&t2, NULL);
	
	elapsedTime = (t2.tv_sec - t1.tv_sec);
	printf("  ");
	printf("%f", elapsedTime);
	
	getchar();
	
    return 0;
}