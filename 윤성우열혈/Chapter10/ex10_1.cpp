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

	Point operator+(const Point &ref){
		Point pos(xpos+ref.xpos, ypos+ref.ypos);
		return pos;
	}
	
	Point& operator+=(const Point &ref){
		xpos = xpos + ref.xpos;
		ypos = ypos + ref.ypos;
		return *this;
	}
	Point& operator-=(const Point &ref){
		xpos = xpos - ref.xpos;
		ypos = ypos - ref.ypos;
		return *this;
	}
	friend Point operator-(const Point &a, const Point &b);
	friend bool operator==(const Point &a, const Point &b);
	friend bool operator!=(const Point &a, const Point &b);
};

Point operator-(const Point &a, const Point &b){
	Point pos(a.xpos-b.xpos, a.ypos-b.ypos);
	
	return pos;	
}
bool operator==(const Point &a, const Point &b){

	if(a.xpos==b.xpos && a.ypos==b.ypos){
		return true;
	}else{
		return false;
	}
}
bool operator!=(const Point &a, const Point &b){

	if(a==b){
		return false;
	}else{
		return true;
	}
}



int main()
{
	Point pos1(0,4);

	Point pos2(3,2);

	Point temp = pos1-pos2;
	temp.ShowResult();

	Point xtemp = pos1+=pos2;
	xtemp.ShowResult();
	bool a = (pos1==pos2);
	cout<<a<<endl;
	cout<<(pos1==pos2)<<endl;

	return 0;
}
