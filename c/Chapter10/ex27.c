/*
 *c언어로 쉽게 풀어 쓴 자료구조
 *Chapter10 연습문제 29번 문제
 *인접리스트로  Dijkstra 알고리즘 구현하기
 * */
#include<stdio.h>
#include<stdlib.h>
#define ARR_SIZE 7
typedef struct GraphNode{
	int vertex;
	int weight;
	struct GraphNode *link;
}GraphNode;

typedef struct GraphType{
	int n;
	GraphNode *adj_mat[ARR_SIZE];
}GraphType;

void initGraph(GraphType *g);
void insertVertex(GraphType *g, int vertex);
void insertEdge(GraphType *g, int u, int v, int length);
void initDistance(GraphType *graph, int distance[]);
void dijkstra(GraphType *graph, int *distance);

int main()
{
	GraphType graph;
	int distance[ARR_SIZE];

	initGraph(&graph);

	insertVertex(&graph, 0);
	insertVertex(&graph, 1);
	insertVertex(&graph, 2);
	insertVertex(&graph, 3);
	insertVertex(&graph, 4);
	insertVertex(&graph, 5);
	insertVertex(&graph, 6);

	insertEdge(&graph, 0, 1, 7);
	insertEdge(&graph, 0, 4, 3);
	insertEdge(&graph, 0, 5, 10);

	insertEdge(&graph, 1, 0, 7);
	insertEdge(&graph, 1, 2, 4);
	insertEdge(&graph, 1, 3, 10);
	insertEdge(&graph, 1, 4, 2);
	insertEdge(&graph, 1, 5, 6);

	insertEdge(&graph, 2, 1, 4);
	insertEdge(&graph, 2, 3, 2);

	insertEdge(&graph, 3, 1, 10);
	insertEdge(&graph, 3, 2, 2);
	insertEdge(&graph, 3, 4, 11);
	insertEdge(&graph, 3, 5, 9);
	insertEdge(&graph, 3, 6, 4);

	insertEdge(&graph, 4, 0, 3);
	insertEdge(&graph, 4, 1, 2);
	insertEdge(&graph, 4, 3, 11);
	insertEdge(&graph, 4, 6, 5);

	insertEdge(&graph, 5, 0, 10);
	insertEdge(&graph, 5, 1, 6);
	insertEdge(&graph, 5, 3, 9);

	insertEdge(&graph, 6, 4, 5);
	insertEdge(&graph, 6, 3, 4);
	
	int i;
	/*
	for(i=0; i<7; i++)
	{
		GraphNode *temp = graph.adj_mat[i];
		while(temp != NULL)
		{
			printf("%d ", temp->vertex);
			temp=temp->link;
		}
		printf("\n");
	}*/
	initDistance(&graph,distance);
	/*
	for(i=0; i<ARR_SIZE; i++)
	{
		printf("%d ",distance[i]);
	}
	printf("\n");
	*/
	dijkstra(&graph, distance);


	printf("최종 distance : ");
	for(i=0; i<ARR_SIZE; i++)
	{
		printf("%d ",distance[i]);
	}
	printf("\n");
	

	return 0;
}
void dijkstra(GraphType *graph, int *distance)
{
	int s[ARR_SIZE];
	int found[ARR_SIZE];
	int i, n, min, minPos,r;
	for(i=0; i<ARR_SIZE; i++)
	{
		found[i] = 1;
		s[i]=-1;
	}
	found[0] = 0;
	s[r++]=0;
	
	n=0;
	while(n<7){	
		min = 5000;
		for(i=0; i<ARR_SIZE; i++)
		{	
			if(distance[i] < min && found[i] == 1){
				min = distance[i];
				minPos = i;
				//printf("%d\n",minPos);
			}
		}
		s[r++]=minPos;//s에 추가
		found[minPos]=0;
		GraphNode *temp;
		temp=graph->adj_mat[minPos];
		while(temp!=NULL)
		{
			if(found[temp->vertex] == 1){
				if((temp->weight+distance[minPos])<distance[temp->vertex]){	
					distance[temp->vertex]=temp->weight+distance[minPos];
				}
			}
			temp=temp->link;
		}
		
				
		printf("distance 변화 :%d ",n);

		for(i=0; i<ARR_SIZE; i++)
		{		
			printf("%d ",distance[i]);
		}
		printf("\n");
		n++;
	}

				
	printf("경로 : ");

	for(i=0; i<ARR_SIZE; i++)
	{	
		printf("%d ",s[i]);
	}
	printf("\n");

}

void initDistance(GraphType *graph, int distance[])
{
	int i;
	distance[0]=0;
	for(i=1; i<ARR_SIZE; i++)
	{	
		distance[i]=3000;	
	}
	GraphNode *temp;
	temp = graph->adj_mat[0];
	while(temp!=NULL)
	{
		distance[temp->vertex]=temp->weight;
		temp=temp->link;
	}
}

void initGraph(GraphType *g){

	int i;
	g->n = 0;
	for(i=0; i<ARR_SIZE; i++)
	{
		g->adj_mat[i] = NULL;
	}
}

void insertVertex(GraphType *g, int vertex)
{
	if((g->n)+1 > ARR_SIZE){
		fprintf(stderr,"범위 초과\n");
		return;
	}
	g->n++;
}

void insertEdge(GraphType *g, int u, int v, int length)
{
	if(u>=g->n || v>=g->n){//이해안감
		fprintf(stderr,"벗어난 정점\n");
	}
	GraphNode *new_node = (GraphNode*)malloc(sizeof(GraphNode));
	new_node->vertex=v;
	new_node->weight=length;
	new_node->link = g->adj_mat[u];
	g->adj_mat[u]=new_node;
}
