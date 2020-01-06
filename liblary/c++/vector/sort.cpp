#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int arr[10]={3,4,1,0,49,13,46,37,89,45};
	vector<int> v(arr,arr+10);
	sort(arr,arr+10);
	/*
	for(auto i=v.begin(); i!=v.end(); i++)
	{
		cout<<*i<<endl;
	}*/
	for(auto i=0; i<10; i++)
	{
		cout<<arr[i]<<endl;
	}
	return 0;
}


