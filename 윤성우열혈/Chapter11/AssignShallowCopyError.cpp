#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char *name;
	int age;
public:
	Person(char *myname, int myage)
	{
		int len=strlen(myname)+1;
		name=new char[len];
		strcpy(name, myname);
		age=myage;
	}
	void ShowPersonInfo() const
	{
		cout<<"이름: "<<name<<endl;
		cout<<"나이: "<<age<<endl;
	}
	~Person()
	{
		delete []name;
		cout<<"called destructor"<<endl;
	}
	Person& operator=(const Person& person)
	{
		int len = strlen(person.name)+1;
		delete []name;
		name = new char[len];
		strcpy(name, person.name);
		age=person.age;

		return *this;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2=man1;

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}
