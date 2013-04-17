#include<iostream>

using namespace std;

int main()
{
   int testcases=0;
   cin>>testcases;
   for(int i=1;i<=testcases;i++)
   {  
        int farmers = 0;
        cin>>farmers;
        long long amount = 0;
        int space,animal,environ;
        for(int j=1;j<=farmers;j++) //for(int i=1;i<=farmers;i++)
        {
             cin>>space>>animal>>environ;
             amount += space*environ;
        }
        cout<<amount<<endl;
   }
   return 0;
}
