#include<iostream>

using namespace std;
class Point{

private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0):xpos(x),ypos(y) {}
	friend ostream& operator<<(ostream&, const Point&); 
	friend istream& operator>>(istream &os, Point& pos); 
};
int main(){

	Point pos;
	cin>>pos;
	cout<<pos;
	return 0;
}
ostream& operator<<(ostream &os, const Point& pos)
{
	os <<'['<<pos.xpos<<","<<pos.ypos<<']'<<endl;
	return os;
}

istream& operator>>(istream &os, Point &pos)
{	
	int x, y;
	os>>x>>y;
	pos.xpos=x; pos.ypos=y;
	return os;
}

