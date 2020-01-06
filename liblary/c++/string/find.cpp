#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{
	string code[9] = { "0001101" ,"0011001" ,"0010011" ,"0111101" ,"0100011" ,"0110001" ,"0101111" ,"0111011" ,"0001011" };

	string temp = "0101111";
	auto it = find(code+0,code+9,temp);

	cout<<it<<endl;
	int n = stoi(*it, nullptr, 2);
	int where=0;
	for(int i=0; i<9; i++)
	{
		if(code[i]==*it)
		{
			where=i;
			break;
		}
	}
	cout<<where<<endl;

	return 0;
}
