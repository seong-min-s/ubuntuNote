#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
	char name[100];
public:
	Employee(char *name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout<<"name: "<<name<<endl;
	}
	virtual int GetPay() const
	{
	}
	virtual void ShowSalaryInfo() const
	{
	}
};

class PermanentWorker : public Employee
{
private:
	int salary; //월급여
public :
	PermanentWorker(char *name, int money)
		: Employee(name), salary(money)
	{};
	virtual int GetPay() const
	{
		return salary;
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout<<"salary: " <<GetPay()<<endl<<endl;
	}
};
class TemporaryWorker : public Employee
{
private:
	int workTime; //이 달에 일한 시간의 합계
	int payPerHour; //시간당 급여
public:
	TemporaryWorker(char* name, int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{ }
	void AddWorkTime(int time)
	{
		this->workTime += workTime;
	}
	virtual int GetPay() const
	{
		return this->workTime * payPerHour;
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout<<"salary: "<<GetPay()<<endl<<endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult; //월 판매 실적
	double bonusRatio; // 상여금 비율
public :
	SalesWorker(char *name, int money, double ratio)
		:PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{ }
	void AddSalesResult(int value)
	{
		salesResult+=value;
	}
	virtual int GetPay() const
	{
		return PermanentWorker::GetPay()+ (int)(this->salesResult*bonusRatio);
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout<<"salary: "<<GetPay()<<endl<<endl; //SalesWorker의 GetPay함수가 호출됨
	}
};




class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{  }
	void AddEmployee(Employee* emp)
	{
		empList[empNum++]=emp;
	}
	void ShowAllSalaryInfo() const
	{
		int sum=0;
	
		for(int i = 0; i<empNum; i++)
			empList[i]->ShowSalaryInfo();
		
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		
		for(int i = 0; i<empNum; i++)
			sum+=empList[i]->GetPay();
		 
		cout <<"salary sum : " <<sum<<endl;
	}
	~EmployeeHandler()
	{
		for(int i=0; i<empNum; i++)
			delete empList[i];
	}
};

int main(void)
{
	//직원 관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
	EmployeeHandler handler;
	//직원 등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	// 이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();

	SalesWorker seller("Hong", 1000, 0.1);
	cout<<seller.GetPay()<<endl;
	cout<<seller.PermanentWorker::GetPay()<<endl;
	seller.PermanentWorker::ShowSalaryInfo();
	seller.ShowSalaryInfo();
	return 0;
}
	
