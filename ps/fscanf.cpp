#include<cstdio>

int main(void)
{
	int data,tc=10;
	FILE *fp=fopen("input.txt","r");

	while(tc--){
		fscanf(fp,"%d",&data);
		printf("%d\n",data);
		for(int i=0; i<16; i++)
		{
			for(int j=0; j<16; j++)
			{
				fscanf(fp,"%1d",&data);
				printf("%d ",data);
			}
			printf("\n");
		}
	}
	fclose(fp);
	return 0;
}
