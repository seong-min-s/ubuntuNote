#include<stdio.h>
#define ARR_SIZE 7
#define INF 3000
int weight[ARR_SIZE][ARR_SIZE] =
{
	{0, 7, INF, INF, 3, 10, INF},
	{7, 0, 4, 10, 2, 6, INF},
	{INF,4,0,2,INF,INF,INF},
	{INF,10,2,0,11,9,4},
	{3,2,INF,11,0,INF,5},
	{10,6,INF,9,INF,0,INF},
	{INF,INF,INF,4,5,INF,0}
};
int main(){
	int i,j;
	int k;

	for(k=0; k<ARR_SIZE; k++)
	{
		for(i=0; i<ARR_SIZE; i++){
			for(j=0; j<ARR_SIZE; j++){
				if(weight[i][k]+weight[k][j] < weight[i][j])
					weight[i][j] = weight[i][k]+weight[k][j];
			}
		}
		printf("%d\n",k);
		for(i=0; i<ARR_SIZE; i++){
			for(j=0; j<ARR_SIZE; j++){
					printf("%d ",weight[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		printf("\n");
	}
	return 0;
}
