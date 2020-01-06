#include<iostream>
#include<cstring>
using namespace std;

class Book{
private:
	char *title;
	char *isbn;
	int price;
public:
	Book(char* title, char* isbn, int price) : price(price)
	{	
		this->title = new char[strlen(title)+1];
		this->isbn = new char[strlen(isbn)+1];
		strcpy(this->title,title);
		strcpy(this->isbn,isbn);
	}	
	Book(const Book& copy) : price(copy.price)
	{	
		this->title = new char[strlen(copy.title)+1];
		this->isbn = new char[strlen(copy.isbn)+1];
		strcpy(this->title,copy.title);
		strcpy(this->isbn, copy.isbn);
	}	
		
	Book& operator=(const Book& copy)
	{
		if(title != NULL){
			delete []title;
		}
		if(isbn != NULL){
			delete []isbn;
		}
		this->title = new char[strlen(copy.title)+1];
		this->isbn = new char[strlen(copy.isbn)+1];
		strcpy(this->title,copy.title);
		strcpy(this->isbn,copy.isbn);
		this->price = copy.price;
		return *this;
	}
	void ShowBookInfo()
	{
		cout<<title<<","<<isbn<<","<<price<<endl;	
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
	char *DRMKey;
public:
	EBook(char* name, char* number, int cost, char* key):Book(name,number,cost)
	{
		int len = strlen(key) +1;
		DRMKey = new char[len];
		strcpy(DRMKey, key);
	}
	EBook(const EBook& copy):Book(copy)
	{
		int len = strlen(copy.DRMKey)+1;
		DRMKey = new char[len];
		strcpy(DRMKey, copy.DRMKey);	
	}
	void ShowBookInfo()
	{
		Book::ShowBookInfo();
		cout<<DRMKey<<endl;	
	}
	EBook& operator=(const EBook& copy)
	{
		if(DRMKey != NULL)
			delete []DRMKey;
		Book::operator=(copy);
		int len = strlen(copy.DRMKey)+1;
		DRMKey = new char[len];
		strcpy(DRMKey, copy.DRMKey);
		return *this;
	}
	~EBook()
	{
		delete []DRMKey;
	}
};

int main(void)
{
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();

	Book book2(book);
	book2.ShowBookInfo();

	Book book3("second", "555-12345-890-0", 20000);
	book3.ShowBookInfo();
	book3 = book2;
	book3.ShowBookInfo();

	cout<<endl;
	EBook ebook1("좋은 c++ ebook1", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook1.ShowBookInfo();

	EBook ebook2("좋은 c++ ebook2", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook2.ShowBookInfo();

	ebook2 = ebook1;
	ebook2.ShowBookInfo();

	EBook ebook3(ebook2);
	ebook3.ShowBookInfo();


	return 0;
}
