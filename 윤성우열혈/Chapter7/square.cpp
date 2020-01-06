#include<iostream>
#include<cstring>
using namespace std;
class Rectangle{
private:
	int  x, y;
public:
	Rectangle(int x, int y) : x(x),y(y){}
	void ShowAreaInfo(){
		cout << x*y << endl;
	}
};
class Square : public Rectangle{
public:
	Square(int x) : Rectangle(x,x){
	}
};

int main(){
	Rectangle rec(4,3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}
