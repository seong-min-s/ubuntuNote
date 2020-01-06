#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> first;
	vector<int> second(4,100);

	vector<int> third(second.begin(), second.end());
	vector<int> fourth(third);

	int myints[]={16,2,77,29};

	vector<int> fifth(myints,myints+sizeof(myints)/sizeof(int));
	fifth.erase(fifth.begin(),fifth.end());

	fifth.push_back(1);
	cout<<"The contents of fifth are : ";
	for(vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		cout<<' '<<*it;
	cout << '\n';

	cout <<"fifth.end() :" <<*(fifth.end())<<endl;
	return 0;
}
