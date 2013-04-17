#include<iostream>
#include<cstdio>
#include<sstream>
using namespace std;

string multiply(string num1,string num2)
{
	size_t len1 = num1.length();
	size_t len2 = num2.length();
	string result(len1+len2,'0');
	for(int i = len1-1;i>=0;i--)
	{
		int carry = 0;
		for(int j = len2-1;j>=0;j--)
		{
			int val = (result[i+j+1]-'0') + (num1[i]-'0')*(num2[j]-'0') + carry;
			carry = val/10;
			result[i+j+1] = '0' + (val%10);
		}
		result[i] = carry+'0';
	}
	return result;
}

void calculate(string num, int exp)
{
	string newNum;
	int points=-1;
	for(int i=0;i<num.length();i++)
	{
		if(num[i] >='0' && num[i] <='9')
		{
			newNum.push_back(num[i]);
			if(points >= 0) points++;
		}else if(num[i] == '.'){
			points=0;
		}
	}

	string result ="1";
	for(int i=1;i<=exp;i++)
		result = multiply(result,newNum);
	int pointPos = result.length()-1-exp*points;
	int s = 0;
	while(s<=pointPos && result[s] == '0') s++;
	int e = result.length()-1;
	while(e>pointPos && result[e]=='0') e--;
	for(int i=s;i<=e;i++)
	{
		if( i == pointPos+1) cout<<'.';
		cout<<result[i];
	}
	if(s>e) cout<<".";
	cout<<endl;
}

int main()
{
	string line;
	while(!cin.eof())
	{
		getline(cin,line);
		string num;
	    int	exp;
		if(line.length() < 9) break;
		stringstream ss(line);
		ss>>num>>exp;
		calculate(num,exp);
	}
	return 0;
}
