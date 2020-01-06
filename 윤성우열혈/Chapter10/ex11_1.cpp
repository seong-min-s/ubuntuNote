#include<iostream>
#include<cstring>
using namespace std;

class Gun
{
private:
	int bullet; //장전된 총알의 수
public:
	Gun(int bnum) : bullet(bnum)
	{}
	void Shot()
	{
		cout<<"BBANG!"<<endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs; //소유한 수갑의 수
	Gun *pistol; //소유하고 있는 권총
public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff)
	{
		if(bnum>0)
			pistol=new Gun(bnum);
		else
			pistol=NULL;
	}
	Police(const Police& copy) : handcuffs(copy.handcuffs)
	{
		pistol=new Gun(*(copy.pistol));
		pistol=copy.pistol;

	}
	void PutHandcuff()
	{
		cout<<"SNAP!"<<endl;
		handcuffs--;
	}
	void Shot()
	{
		if(pistol==NULL)
			cout<<"Hut BBANG!"<<endl;
		else
			pistol->Shot();
	}
	Police& operator=(const Police& police)
	{
		if(pistol != NULL){
			delete pistol;
		}
		if(police.pistol!=NULL){
			pistol=new Gun(*(police.pistol));
		}else
			pistol=NULL;
		handcuffs = police.handcuffs;
		return *this;
	}
	~Police()
	{
		if(pistol!=NULL)
			delete pistol;
	}
};

int main(void)
{
	Police police1(3,6);

	Police police0(0,0);
	
	police0=police1;

	return 0;
}
