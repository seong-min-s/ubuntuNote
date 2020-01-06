#include <iostream>       // std::cin, std::cout
#include <queue>          // std::queue
#include <vector>
#include <cstdio>
#define MAX_SIZE 16

using namespace std;

typedef struct Point{
    int y, x;
}POINT;

int dirX[4]={1,-1,0,0};
int dirY[4]={0,0,1,-1};

int main (void)
{    
	FILE *fp = fopen("input.txt","r");

	queue<POINT> q;
    	vector<int> vs(16,0);
    	vector<vector<int>> v(16,vs);
    
    	int tc=10,todo=0, data=0, find=0;
  	POINT startPoint = {1,1};
    
    	while(tc--)
    	{
        	find=0;
		fscanf(fp,"%d",&todo);
	        int x,y;
        	for(y=0; y<MAX_SIZE; y++)
	        {
        	    for(x=0; x<MAX_SIZE; x++)
	            {
        	        fscanf(fp,"%1d",&data);
	                vs.at(x)=data; 
        	    }
	            v.at(y)=vs;           
	        }
        
        	q.push(startPoint);
        
		while(!q.empty())
	        {
        	    POINT point;
	            point.x=q.front().x;
        	    point.y=q.front().y;
            
	            q.pop();
            
        	    if(v[point.y][point.x]==3)
	            {   
        	        find=1;
             		break;
	            }
            
        	    for(int i=0; i<4; i++)
	            {
        	        if(point.y + dirY[i]<0&&point.y + dirY[i]>15&&point.x + dirX[i]<0&&point.x + dirX[i]>15)
	                {    continue;}
        	     	if(v[point.y + dirY[i]][point.x + dirX[i]]==0)
	                {
        	            POINT temp;
                	    temp.y = point.y + dirY[i];
	                    temp.x = point.x + dirX[i];
        	         	q.push (temp);
                	}
	            }
	        }
        	cout<<"#"<<todo<<" "<<find<<endl;
	        while(!q.empty())
        	    q.pop();
	}
	fclose(fp);
 	
	return 0;
}
