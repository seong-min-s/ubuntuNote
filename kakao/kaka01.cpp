#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int i,j;
    int Min=1000;
    for(int len=1; len<=s.size()/2; len++)
    {
        string neww;
        i=j=0;
        for(i=j; i<s.size(); ){
            string df=s.substr(i,len);
            int count=0;
            
            for(j=i+len; j<s.size()&&df==s.substr(j,len); j=j+len)
            {
                count++;
            }
            if(count==0)
                neww=neww+df;
            else
                neww=neww+ to_string(count+1)+df; 
        }
        if(Min>neww.size())
            Min=neww.size();
        answer=Min;

    }
    
    return answer;
}
int main(void)
{
  cout<<solution("aabbaccc")<<endl;
  return 0;
}
