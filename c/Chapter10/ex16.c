#include <stdio.h>
#define ARR_SIZE 4
typedef struct GraphType{
	int n;
	int adj_mat[ARR_SIZE][ARR_SIZE];
}GraphType;
void read_graph_mat(GraphType *g, char *name){
	int size;
	int i, j;
	char ch;
	char lf;
	FILE *fp = fopen(name, "r");
	
	size = fgetc(fp)-48;
	g->n = size;
	lf=fgetc(fp);
	for(i = 0; i < size; i++){
		for(j = 0; j < size+1; j++){
			if((ch=fgetc(fp)) == '\n')
				break;
			g->adj_mat[i][j] = ch-48;
		}
	}
	fclose(fp);
}
void write_graph_mat(GraphType *g, char *name)
{
	int i, j;
	FILE *fp = fopen(name, "w");
	fprintf(fp,"%d\n",g->n);
	
	for(i=0; i<g->n; i++){
		for(j=0; j<g->n; j++){
			fprintf(fp,"%d",g->adj_mat[i][j]);
		}
		fprintf(fp,"\n");
	}
	
	fclose(fp);
}
int main()
{
	GraphType graph;
	read_graph_mat(&graph, "graph.txt");
	int i, j;
	/*
	for(i = 0; i < graph.n; i++){
		for(j = 0; j < graph.n; j++){
			printf("%d ",graph.adj_mat[i][j]);
		}
		printf("\n");
	}
	*/	
	write_graph_mat(&graph, "write_graph.txt");
	return 0;
}

