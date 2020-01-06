#include<iostream>
using namespace std;
bool select(int x, int y, int number);
int find(int empty);
void init();
int arr[20][20];

int main()
{
  int n = 0;
  int w, h;
  int empty = 0;;
  char ch;
  init();
  
  scanf(" %d",&n);
  while(n!=0){
	scanf(" %d %d",&w,&h);
	for(int i=0; i<w; i++)
	{
	  for(int j=0; j<h; j++)
	  {
		scanf(" %c",&ch);
		if(ch == '#'){
		  arr[i][j] = 1;
		}else if(ch == '.'){
		  arr[i][j] = 0;
		  empty++;
		}
	  }
	}

	cout<<find(empty)<<endl;	  
	empty=0;
	n--;
	init();
  }
  return 0;
}
void init()
{
  for(int i=0; i<20; i++)
  {
	  for(int j=0; j<20; j++)
	  {
		arr[i][j] = -1;
	  }
  }
}
int find(int empty)
{
	int num; 
  	int moved[] = {-1,-1,-1,-1};
  	int count = 0;
  	
  	if((empty%3)!=0){
	  return 0;
	}
  	if(empty==0){
	  return 1;
	}
  	for(int i=0; i<20; i++)
	{
	  	for(int j=0; j<20; j++)
		{
			for(num=0; num<4; num++)
			{
			  	bool b = select(i,j,num);
				if(b==true){
					empty -= 3;
					count += find(empty);
				}
			}
		}
	}
	return count;
}
bool select(int x, int y, int number)
{

  switch(number){
	  case 0 : //ㄱ
		if(x-1<0 && y-1<0)
			return false;
		if(arr[x-1][y] != 1 && arr[x][y-1] != 1)
		{
		  arr[x-1][y] = 1;
		  arr[x][y-1] = 1;
		  arr[x][y] = 1;
		  return true;
		}
		else{
		  return false;
		}
	  case 1 : //ㄱ반대
		if(x+1>19 && y-1<0)
			return false;
		if(arr[x+1][y] != 1 && arr[x][y-1] != 1)
		{
		  arr[x+1][y] = 1;
		  arr[x][y-1] = 1;
		  arr[x][y] = 1;
		  return true;
		}
		else{
		  return false;
		}
	  case 2 : //ㄴ
		if(x+1>19 && y+1>19)
			return false;
		if(arr[x][y+1] != 1 && arr[x+1][y] != 1)
		{
		  arr[x][y+1] = 1;
		  arr[x+1][y] = 1;
		  arr[x][y] = 1;
		  return true;
		}
		else{
		  return false;
		}
	  case 3 : //ㄴ반대
		if(x-1<0 && y+1>20)
			return false;
		if(arr[x-1][y] != 1 && arr[x][y+1] != 1)
		{
		  arr[x-1][y] = 1;
		  arr[x][y+1] = 1;
		  arr[x][y] = 1;
		  return true;
		}
		else{
		  return false;
		}  
	} 
}
