#include<iostream>
#include<stack>
#include<string>

using namespace std;
bool check(string str);

int main()
{
    int tc;
    string str;
    bool result;
    int count=0;
    cin >> tc;
    while(tc--)
    {
        cin>>str;
        result=check(str);
        cout<<"#"<<++count<<" "<<result<<endl;
    }
    return 0;
}

bool check(string str)
{
	auto f=str.begin();
	auto r=str.rbegin();
	auto size=str.size()/2;
	do{
		if(*f!=*r)
		{
			return false;
		}
		f++;
		r++;
			
	}while(size--);
	return true;
}

