#include<iostream>
#define BSIZE 510
using namespace std;

int result[BSIZE];
void reset()
{
	for(int i=0;i<BSIZE;i++)
		result[i] = 0;
}
int main()
{
	string num1,num2;
	while(!cin.eof())
	{
		getline(cin,num1);
		getline(cin,num2);
		int end1 = num1.length()-1;
		int end2 = num2.length()-1;
		//ignore CR, always put boundary check in a while loop go gurantee correctness, 
		//you will never know when it will violate the boundary!
		while(end1>=0 && (num1[end1]<'0' || num1[end1]>'9')) end1--;
		while(end2>=0 && (num2[end2]<'0' || num2[end2]>'9')) end2--;
		if(end1<0 || end2<0) break;
		for(int i=end1;i>=0;i--)
		{	
			int carry = 0;
			for(int j = end2;j>=0;j--)
			{
				int val = (num1[i]-'0')*(num2[j]-'0') + carry + result[end1-i + end2-j];
				result[end1-i+end2-j] = val%10;
				carry = val/10;
			}
			result[end1-i+end2+1] = carry;
		}
		int e = BSIZE-1;
		while(result[e] == 0) e--;
		int i = e;
        /**handle cases where result is 0!!!!!*/
		if(e<0) cout<<"0";
		for(;i>=0;i--)
			cout<<result[i];
		cout<<endl;
		reset();
	}
}
