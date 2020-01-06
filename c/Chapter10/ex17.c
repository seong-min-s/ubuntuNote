/*2019.03.19
 *작성자 : 최성민
 *프로그램 명 : 인접 행렬로 표현된 그래프를 입력받아서 인접리스트로 변환하는 c함수를 작성하는 프로그램
 */
#include<stdio.h>
#include<stdlib.h>
#define ARR_SIZE 4
typedef struct GraphNode{
	int data;
	struct GraphNode* link;
}GraphNode;
typedef struct GraphType_Link{
	int n;
	GraphNode *adj_mat[ARR_SIZE];
}GraphType_Link;
typedef struct GraphType_Arr{
	int n;
	int adj_mat[ARR_SIZE][ARR_SIZE];
}GraphType_Arr;

GraphType_Link* getLinkGraph(GraphType_Arr *graph);

int main(){
	FILE *fp = fopen("graph.txt" ,"r");
	GraphType_Arr gta;
	GraphType_Link *gtl;
	int i, j;
	char c;
	gta.n = fgetc(fp)-48;
	fgetc(fp);
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if((c=fgetc(fp) )=='\n')
				break;
			gta.adj_mat[i][j] = c-48;
		}
	}	
	fclose(fp);
	
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			printf("%d ",gta.adj_mat[i][j]);
		}
		printf("\n");
	}
	gtl = getLinkGraph(&gta);

	printf("인접리스트 그래프 %d\n",gtl->n);
	for(i = 0; i < 4; i++)
	{
		GraphNode *t=gtl->adj_mat[i];
		while(t != NULL){
			printf("%d ", t->data);
			t = t->link;
		}
		printf("\n");
	}
	return 0;
}
GraphType_Link* getLinkGraph(GraphType_Arr *graph){
	GraphType_Link *temp;
	temp = (GraphType_Link*)malloc(sizeof(GraphType_Link));
	temp->adj_mat[0] = NULL;
	temp->adj_mat[1] = NULL;
	temp->adj_mat[2] = NULL;
	temp->adj_mat[3] = NULL;
	int i, j;
	temp->n= graph->n;

	for(i=0; i<temp->n; i++)
	{
		for(j=0; j<temp->n; j++)
		{
				GraphNode *gn = (GraphNode*)malloc(sizeof(GraphNode));
				gn->data = graph->adj_mat[i][j];
				gn->link = NULL;

				if(temp->adj_mat[i] == NULL){
					temp->adj_mat[i] = gn;
				}else{
					//연결을 해줘야 한다.
					GraphNode *mv;
					mv = temp->adj_mat[i];
					while(mv->link != NULL)
					{
						printf("%d ",j);
						mv = mv->link;
					}
					mv->link = gn;
				}
		}
	}
	return temp;
}
