#include<iostream>

using namespace std;

bool strGreater(string &num1,string &num2,int pos)
{
	int len1 = num1.length();
	int len2 = num2.length();
	int s = pos - len2;
	//if(s++ >='0') return true;
	//if(s>=0 && num1[s] >='0') return true;
	if(s>=0 && num1[s] >'0') return true;
	for(int i=0;i<len2;i++)
	{
		if(num1[s+1+i]>num2[i]) return true;
		else if(num1[s+1+i]<num2[i]) return false;
	}
	return true;
}
int subtract(string &num1,string &num2,int pos)
{
	int len2 = num2.length();
	int count = 0;
	while(strGreater(num1,num2,pos))
	{
		count++;
		for(int i=0;i<len2;i++)
		{
			if(num1[pos-i] < num2[len2-1-i])
			{
				int p = pos-i-1;
				while(num1[p] == '0') p--;
				num1[p] = num1[p] - 1;
				for(int j=p+1;j<pos-i;j++)
					num1[j] += 9;
				num1[pos-i] += 10;
			}
			num1[pos-i] = '0' + (num1[pos-i]-num2[len2-1-i]) ;
		}
	}
	return count;
}

void divide(string &num1,string &num2,string &result)
{
	int len1 = num1.length();
	int len2 = num2.length();
	for(int i=len2-1;i<len1;i++)
		result.push_back('0'+subtract(num1,num2,i));
}
void output(string &str)
{
	int s = 0;
	while(s<str.length() && str[s] == '0') s++;
	if(s == str.length()) cout<<'0';
	while(s<str.length()) cout<<str[s++];
	cout<<endl;
}
int main()
{
	string num1,op,num2;
	while(cin>>num1>>op>>num2)
	{
		string result;
		divide(num1,num2,result);
		if(op == "/")
			output(result);
		else
			output(num1);
	}
	return 0;
}
