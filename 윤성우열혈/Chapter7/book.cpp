#include<iostream>
#include<cstring>

using namespace std;

class Book{
private:
	char *title;
	char *isbn;//국제 표준 도서 번호
	int price;
public:
	Book(char *name, char *number, int price):price(price){
		title = new char[strlen(name)+1];
		strcpy(title, name);
		isbn = new char[strlen(number)+1];
		strcpy(isbn, number);
	}
	void ShowBookInfo(){
		cout << "제목 : "<< title << endl;
		cout << "ISBN : "<< isbn << endl;
		cout << "가격 : "<< price << endl;
	}
	~Book()
	{
		delete []title;
		delete []isbn;
	}
};
class EBook : public Book
{
private:
	char *DRMKey; //보안 관련 키
public:
	EBook(char *name, char *number, int price, char *pass) : Book(name, number, price){
		DRMKey = new char[strlen(pass)+1];
		strcpy(DRMKey, pass);
	}
	void ShowEBookInfo(){
		/*
		cout << "제목 : "<< title << endl;
		cout << "ISBN : "<< isbn << endl;
		cout << "가격 : "<< price << endl;
		*/
		ShowBookInfo();
		cout << "인증키:"<< DRMKey << endl;
	}
	~EBook(){
		delete []DRMKey;
	}
};
int main(void)
{
	Book book("좋은 c++", "555-12334-890-0",20000);
	book.ShowBookInfo();
	cout<<endl;
	EBook ebook("좋은 c++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}
