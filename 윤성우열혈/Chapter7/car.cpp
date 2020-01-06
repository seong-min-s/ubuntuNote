#include <iostream>
using namespace std;
class Car //기본 연료 자동차
{
private:
	int gasolineGauge;
public:
	Car(){
		gasolineGauge = 0;
		cout << "가솔린 연료 값이 입력되지 않았습니다." << endl;
	}
	Car(int amount):gasolineGauge(amount){
		cout << "초기 가솔린 양 :"<< gasolineGauge << endl;
	};
	int GetGasGauge()
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car //하이브리드 자동차
{
private:
	int electricGauge;
public:
	HybridCar(){
		electricGauge = 0;
		cout << "전기 연료 값이 입력되지 않았습니다." << endl;
	}
	HybridCar(int amount, int amount2) : electricGauge(amount), Car(amount2){
		cout << "초기 전기량 :"<< electricGauge << endl;
	}
	int GetElectGauge()
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar // 하이브리드 워터카
{
private:
	int waterGauge;
public:
	HybridWaterCar(){
		waterGauge = 0;
		cout << "물 연료 값이 입력되지 않았습니다." << endl;
	}
	HybridWaterCar(int amount) : waterGauge(amount){
		cout << "초기 물의양 :"<< waterGauge << endl;
	}
	HybridWaterCar(int amount, int amount2, int amount3) : waterGauge(amount), HybridCar(amount2, amount3){}

	void ShowCurrentGauge(){
		cout<<"잔여 전기량: "<<GetElectGauge()<<endl;
		cout<<"잔여 워터량: "<<waterGauge<<endl;
		cout<<"잔여 가솔린: "<<GetGasGauge()<<endl;
	}
};
int main()
{
	Car *myCar = new Car(50);

	HybridCar *myHybridCar = new HybridCar(50,50);

	HybridWaterCar *myHybridWaterCar = new HybridWaterCar(50,50,50);
	
	delete myHybridWaterCar;
	delete myHybridCar;
	delete myCar;

/*
	Car myCar(50);
	HybridCar myHybridCar(50,50);
	HybridWaterCar myHybridWaterCar(50,50,50);
	
	myHybridWaterCar.ShowCurrentGauge();
*/
	return 0;
}
