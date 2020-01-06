#include<iostream>
#include<cstring>
using namespace std;
const int MOD =1000000007;
int cover(int n);
int cache[101];
int main()
{
 	int tc=0;
  	int n=0;
  	int result=0;
  	int resultarr[51];
  	int count=0;
  	memset(cache, -1, sizeof(cache));
  	cin>>tc;
  	while(tc--)
	{
		cin>>n;
		/*
	  	if(n%2==0){
		  result=(cover(n)-cover(n/2-1)-cover(n/2))%MOD;
		}else{
		  coverresult=cover(n);
		  result=(cover(n)-cover(n/2))%MOD;
		}
	  	resultarr[count++]=result;
	  	*/
		resultarr[count++]=cover(n);
	  	memset(cache, -1, sizeof(cache));
	}
  	for(int i =0; i<count; i++)
	  	cout<<resultarr[i]<<endl;
  	
 	return 0;
}
int cover(int n)
{
   	if(n<=1)
	  	return 1;
  	int &ret = cache[n];
	if(ret != -1)
	  	return ret;
	ret=(cover(n-1)+cover(n-2))%MOD;
   	return ret;
}

