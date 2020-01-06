#include <iostream>
 
using namespace std;
 
int is_pal(char* word)
{
    for(int i=0;i<10;i++)
        {
            if(word[i]==NULL)
            {
                for(int j=i-1;j>=(i-1)/2;j--)
                {
                    if (word[j]!=word[i-j-1])
                    {
                        cout<<0<<endl;
                        return 0;
                    }
                }
                cout<<1<<endl;
                return 0;
            }
        }
}
 
int main()
{
    int T;
    char word[10];
    scanf("%d\n",&T);
    for (int t=0;t<T;t++)
    {
        cin>>word;
        cout<<"#"<<t+1<<" ";
        is_pal(word);
    }
}
