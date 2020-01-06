#include<iostream>
#include<vector>
using namespace std;
class Point{
  public:
  	int x, y;
  	Point(int x=0, int y=0):x(x),y(y){};
};
int main()
{
	Point temp;
  	vector<Point> pt(3);
  	int newx, newy;
  	int tc;
  	int index=0, next=0;
  	bool completed;
  	
  	cin >> tc;
  	
  	while(tc--)
	{
	  	for(int i=0; i<3; i++){
			cin>>temp.x>>temp.y;
			pt[i]=temp;
		}
	  	completed = false;
		for(index=0; index<pt.size(); index++)
		{
		 	int xp=pt[index].x;
		  
		  	for(next=index+1; next<pt.size(); next++)
			{
			  if(xp==pt[next].x)
			  {
				newx=pt[3-next-index].x;
				if(pt[3-next-index].y==pt[index].y){
				  newy=pt[next].y;
				}
				else{
				  newy=pt[index].y;
				}
				cout<<newx<<" "<<newy<<endl;
				
				completed=true;
				break;
			  }
			}
		 	if(completed)
			  break;	  	
		}  	
	}
 	 return 0;
}
  
  
