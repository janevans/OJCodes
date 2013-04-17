#include<iostream>
using namespace std;
int main()
{
    //using long long to avoid overflow.
    long long a,b;
    while(cin>>a>>b)//could be used to detect EOF.
	{
		if(a>b) cout<<a-b<<endl;
		else cout<<b-a<<endl;
	}
    return 0;
} 
