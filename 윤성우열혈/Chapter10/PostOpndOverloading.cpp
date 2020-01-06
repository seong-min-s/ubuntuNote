#include <iostream>
using namespace std;

class Point{
private:
	int xpos, ypos;
public:
	Point(int x, int y):xpos(x),ypos(y)
	{}
	void ShowResult(){
		cout <<"("<<xpos<<","<<ypos<<")"<<endl;
	}
	const Point operator++(int){
		const Point retobj(xpos, ypos);
		xpos +=1;
		ypos +=1;
		return retobj;
	}
	friend const Point operator--(Point &ref, int);
};
const Point operator--(Point &ref, int)
{
	const Point pos(ref);
	ref.xpos-=1;
	ref.ypos-=1;
	return pos;
}
int main()
{

	Point pos1(3,5);
	Point pos2(2,4);

	Point pos3=pos1++;
	Point pos4=pos2--;
	pos4.ShowResult();
	pos2.ShowResult();
	return 0;
}
