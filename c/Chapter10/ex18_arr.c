/*
 * 프로그램명: ex18_arr.c
 * 프로그램내용 : 인접행렬에서 간선을 삭제하는 함수를 구현한다.
 * 작성자 : 최성민
 */
#include<stdio.h>
typedef struct GraphType{
	int n;
	int adj_mat[4][4];
}GraphType;
void delete_edge(GraphType *graph,int from, int to);

int main()
{
	int i, j;
	GraphType graph = {4,{{0, 0, 1, 1},{1, 1, 1, 1},{0, 0, 0, 0},{1, 0, 1, 0}}};

	
	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%d",graph.adj_mat[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------------\n");
	delete_edge(&graph,2,1);

	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%d",graph.adj_mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}


void delete_edge(GraphType *graph,int from, int to)
{
	graph->adj_mat[from][to] = 0;
	graph->adj_mat[to][from] = 0;
}
