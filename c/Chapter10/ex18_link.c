/*
 * 소스파일명 : ex18_link.c
 * 작성자 : 최성민
 * 날  짜 : 2019.03.20
 * 프로그램설명 : 인접리스트로 표현된 그래프에서 간선을 삭제하는 프로그램
 */
#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE 4
typedef struct GraphNode{
	int vertex;
	struct GraphNode *link;
}GraphNode;

typedef struct GraphType{
	int numberOfVertex;
	GraphNode *adj_mat[ARR_SIZE];
}GraphType;

void init(GraphType *graph)
{
	int i;
	graph->numberOfVertex = 0;
	for(i=0; i<ARR_SIZE; i++)
	{
		graph->adj_mat[i] = NULL;
	}

}

void insert_vertex(GraphType *graph, int vertex)
{
	if((graph->numberOfVertex+1) > ARR_SIZE){
		fprintf(stderr,"그래프 정점의 개수 초과");
		return ;
	}
	graph->numberOfVertex++;

	if(graph->adj_mat[vertex] == NULL){
		GraphNode *newNode = (GraphNode*)malloc(sizeof(GraphNode));
		newNode->vertex = vertex;
		newNode->link = NULL;
		graph->adj_mat[vertex] = newNode;
	}else{
		
		fprintf(stderr,"이미 존재하는 정점");
		return ;
	}
}
void insert_edge(GraphType *graph, int from, int to)
{
	int i = 0;
	if(graph->adj_mat[i] == NULL){
		fprintf(stderr,"간선의 시작 정점이 존재하지 않습니다.");
		return ;
	}

	GraphNode *temp = graph->adj_mat[from];
	while(temp->link != NULL){
		if(temp->vertex == to){
			fprintf(stderr,"이미 존재하는 간선입니다.");
			return;
		}
		temp = temp->link;
	}
	GraphNode *new = (GraphNode*)malloc(sizeof(GraphNode));
	new->vertex = to;
	new->link = NULL;
	temp->link = new;
}
void delete_edge(GraphType *graph, int from, int to)
{
	if(graph->adj_mat[from] == NULL)
	{
		fprintf(stderr, "존재 하지 않은 정점 입니다.");
		return;
	}
	GraphNode *prev, *curr;
	prev = NULL;
	curr = graph->adj_mat[from];
	while(curr->link != NULL)
	{
		prev= curr;
		curr = curr->link;
	}
	prev->link = curr->link;
	free(curr);

}


void display(GraphType* graph)
{
	int i, j;
	for(i=0; i<graph->numberOfVertex; i++)
	{
		GraphNode *temp = graph->adj_mat[i];
		while(temp != NULL)
		{
			printf("%d ",temp->vertex);
			temp=temp->link;
		}
		printf("\n");
	}
}
		

int main()
{
	GraphType graph;

	init(&graph);
	insert_vertex(&graph, 0);	
	insert_vertex(&graph, 1);	
	insert_vertex(&graph, 2);	
	insert_vertex(&graph, 3);

	insert_edge(&graph, 0,1);	
	insert_edge(&graph, 0,2);	
	insert_edge(&graph, 0,3);	
	insert_edge(&graph, 1,0);	
	insert_edge(&graph, 1,2);	
	
	insert_edge(&graph, 2,0);	
	insert_edge(&graph, 2,1);	
	insert_edge(&graph, 2,3);	

	insert_edge(&graph, 3,0);	
	insert_edge(&graph, 3,2);	
	
	display(&graph);

	delete_edge(&graph, 3,2);

	printf("========================\n");
	display(&graph);
	return 0;
}
