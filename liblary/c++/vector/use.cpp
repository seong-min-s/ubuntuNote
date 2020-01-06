#include<iostream>
#include<vector>
using namespace std;
class Point{
public : 
	int x,y;
};

int main()
{
	vector<int> pt;
	
	pt.push_back(0);

	cout<<"size : "<<pt.size()<<endl;
	cout<<"pt[0] : "<<pt[0]<<endl;
	cout<<"pt.at(0) : "<<pt.at(0)<<endl;

	vector<Point> ptv(3);
	Point temp;
	temp.x=1, temp.y=2;
	ptv[0]=temp;
	pt.push_back(1);

	for(int i=0; i<pt.size(); i++)
	{
		cout<<pt[i]<<endl;
	}
	return 0;
}
