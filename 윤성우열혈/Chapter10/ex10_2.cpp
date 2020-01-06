#include <iostream>
using namespace std;
class Point{
private:
	int xpos, ypos;
public:
	Point(int x =0, int y=0):xpos(x),ypos(y)
	{}
	void ShowResult()
	{
		cout<<"("<<xpos<<","<<ypos<<")"<<endl;


	}
	Point operator-()
	{
		Point pos(-xpos, -ypos);
		return pos;	
	}
	friend Point operator~(const Point &pos);
};
Point operator~(const Point &pos){

		Point p(pos.ypos, pos.xpos);
		return p;
}

int main()
{
	Point pos1(3,5);
	Point pos2 = -pos1;
       	pos2.ShowResult();

	pos2 = ~pos1;
	pos2.ShowResult();

	return 0;
}
