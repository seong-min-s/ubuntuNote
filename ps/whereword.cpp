#include <iostream>
#include <vector>
using namespace std;
int getCount(int arr[][15],int arr_size,int word_size);
int main()
{	
    int tc,idx,k,count,arr_size,cout_number;
	int arr[15][15];
    cin>>tc;
    while(tc--)
    {
        cin>>arr_size>>k;
        for(int i=0; i<arr_size; i++)
        {
            for(int j=0; j<arr_size; j++)
            {
                cin>>arr[i][j];
            }
        }
        cout<<"#"<<cout_number<<" "<<getCount(arr,arr_size,k)<<endl;
    }
    return 0;
}
int getCount(int arr[][15], int arr_size, int word_size)
{
    int count=0;
    int idx=0;
    for(int y=0; y<arr_size; ++y)//가로
    {
        for(int x=0; x<arr_size; ++x)
        {
       	   if(arr[y][x]==0)
           {	
                idx=0;
            	do{
                 	  ++idx; 
                }while(x<arr_size && arr[y][++x]==0);
                
                if(idx==word_size)
                {
                    ++count;
                }
            }
        }
    }
    for(int x=0; x<arr_size; ++x)
    {
        for(int y=0; y<arr_size; ++y)
        {
            if(arr[y][x]==0)
            {
                idx=0;
            	do{
                 	  ++idx; 
                }while(x<arr_size && arr[++y][x]==0);
                
                if(idx==word_size)
                {
                    ++count;
                }
            }
        }
    }
}

