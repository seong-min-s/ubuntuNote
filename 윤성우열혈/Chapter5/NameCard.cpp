#include<iostream>
#include<cstring>
namespace POSI_CONST{
	enum {CLERK, SENIOR, ASSIST, MANAGER};
}
using namespace POSI_CONST;
using namespace std;
class NameCard{
private:
	char *alias;
	char *nameOfCompany;
	char *phoneNumber;
	int position;
public:
	NameCard(char *name, char *company, char *phoneNumber, int posi):position(posi)
	{
		alias = new char[strlen(name)+1];
		nameOfCompany = new char[strlen(company)+1];
		this->phoneNumber = new char[strlen(phoneNumber)+1]; 
		strcpy(alias, name);
		strcpy(nameOfCompany, company);
		strcpy(this->phoneNumber, phoneNumber);
	}
	char* GetAlias(){
		return alias;
	}
	char* GetNameOfCompany(){
		return nameOfCompany;
	}
	char* GetPhoneNumber(){
		return phoneNumber;
	}
	void GetPosition(){
		switch(this->position){
		case CLERK :
			cout << "직급 : " << "사원"<<endl;
			break;
		case SENIOR :
			cout << "직급 : " << "주임"<<endl;
			break;
		case ASSIST :
			cout << "직급 : " << "대리"<<endl;
			break;
		case MANAGER :
			cout << "직급 : " << "부장"<<endl;
			break;
		default:
			break;
		}
	}
	void ShowNameCardInfo()
	{
		cout << "이름: " << GetAlias() << endl;
		cout << "회사: " << GetNameOfCompany() << endl;
		cout << "전화번호: "<< GetPhoneNumber() << endl;
		GetPosition();
		cout << endl;
	}
	~NameCard()
	{
		delete []alias;
		delete []nameOfCompany;
		delete []phoneNumber;
	}
};
int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", CLERK);
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", ASSIST);

	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();

	return 0;
}
