#include<stdio.h>
int main()
{
  	int N, L, i, j, k,r;
  	int a[1000];
  	int count;
  	int sum;
  	double min,avg;
  
  	scanf("%d",&count);
  
  	for(i=0; i<count; i++)
	{
	  scanf("%d %d", &N, &L);

	  //공연 일자마다 비용을 저장하는 배열 저장
	  for(r=0; r<N; r++)
	  {
		scanf("%d",&a[r]);
	  }
	  //L개를 연속으로 묶어서 최소 평균 값 구하기
	  min=100;
	  while(L<=N){
		for(j=0; j<N-L+1; j++)
		{
		  sum=0;
		  for(k=j; k<j+L; k++)
		  {
			sum = sum+a[k];
		  }
		  avg = sum/(float)L;
	  		printf("%.11lf\n",avg);
		  if(avg<min)
		  {
			min = avg;
		  }
		}
		L++;
	  }
	  printf(">>%.11lf\n",min);
	}
 	return 0; 
}
