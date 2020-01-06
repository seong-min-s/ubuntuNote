#include <iostream>
using namespace std;

class Point
{
private :	
	int xpos, ypos;
public :
	Point(int x, int y):xpos(x), ypos(y){
		
	}
	void ShowPointInfo() const
	{
		cout<<"["<<xpos<<","<<ypos<<"]"<<endl;
	}
};

class Circle
{
private :
	Point centerPos;
	int radi;
public :
	Circle(double x, double y, double r) : centerPos(x,y),radi(r)
	{}
	void ShowCircleInfo() const
	{	
		cout<<"radius : "<<radi<<", center of Cirlce is : "<<endl;
		centerPos.ShowPointInfo();
	}
};
class Ring
{
private :
	Circle inC, outC;
public :
	Ring(double x, double y, double r, double p, double q, double m) : inC(x,y,r),outC(p,q,m)
	{}
	void ShowRingInfo() const
	{
		/*if(inC.centerPos.xpos == outC.centerPos.xpos && inC.centerPos.ypos == outC.centerPos.ypos)
		{
			cout << "두께가 일정한 링 입니다."<<endl;
		}else{
			cout << "두께가 일정하지 않은  링 입니다."<<endl;
		}*/
		cout << "Inner Circle Info .." << endl;
		inC.ShowCircleInfo();

		cout << "Outter Circle Info .." << endl;
		outC.ShowCircleInfo();
	}
};
int main(void)
{
	Ring *ring = new Ring(1, 1, 4, 2, 2, 9);
	ring->ShowRingInfo();
	delete ring;
	return 0;
}
