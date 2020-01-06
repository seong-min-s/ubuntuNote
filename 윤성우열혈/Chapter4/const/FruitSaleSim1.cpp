#include <iostream>
using namespace std;

class FruitSeller
{
private :
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public :
	void InitMembers(int price, int num, int money)
	{
		APPLE_PRICE=price;
		if(APPLE_PRICE < 0)
			cout << "사과의 값 오류 (현재 입력된 값 < 0)" << endl;
		numOfApples=num;
		if(numOfApples < 0)
			cout << "사과의 개수 오류 (현재 입력된 값 < 0)" << endl;
		myMoney=money;
	}
	int SaleApples(int money)
	{
		int num=money/APPLE_PRICE;
		numOfApples-=num;
		myMoney+=money;
		return num;
	}
	void ShowSalesResult() const
	{
		cout<<"남은 사과: "<<numOfApples<<endl;
		cout<<"판매 수익: "<<myMoney<<endl<<endl;
	}
};

class FruitBuyer
{
	int myMoney; //private
	int numOfApples; //private
public:
	void InitMembers(int money)
	{
		myMoney=money;
		if(myMoney < 0)
			cout << "돈 입력 오류 (현재 입력된 값 < 0)" << endl;
		numOfApples=0;
	}
	void BuyApples(FruitSeller &seller, int money)
	{
		numOfApples+=seller.SaleApples(money);
		myMoney-=money;
	}
	void ShowBuyResult() const
	{
		cout<<"현재 잔액: "<<myMoney<<endl;
		cout<<"사과 개수: "<<numOfApples<<endl<<endl;
	}
};
int main(void)
{
	FruitSeller seller;//판매자
	seller.InitMembers(1000,20,0);
	FruitBuyer buyer;//구매자
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000); //과일의 구매!

	cout<<"과일 판매자의 현황"<<endl;
	seller.ShowSalesResult();
	cout<<"과일 구매자의 현황"<<endl;
	buyer.ShowBuyResult();
	return 0;
}
