#include<iostream>
#include<cstdio>
#include<sstream>
using namespace std;

// 1 remember to skip preceding 0s !!!!!!!!!!!!!!!!!
// 2 handle special case where num is 0!!!!
void fill(string &line, string &num,int &i)
{
    // 1 remember to skip preceding 0s !!!!!!!!!!!!!!!!!
	while(i<line.length() && (line[i] == '0' || line[i] == ' ')) i++;
	while(i<line.length() && line[i] != '+' && line[i] != '*')
	//while(i<line.length() && (line[i] != '+' || line[i] != '*'))
	{
		if(line[i] >='0' && line[i] <='9')
			num.push_back(line[i]);
		i++;
	}
    // 2 handle special case where num is 0!!!!
	if(num.length() == 0)
		num.push_back('0');
}


void parse(string &line, string &num1, char &op,string &num2)
{
	int i = 0;
	fill(line,num1,i);
	if(i>=line.length()) return;
	op = line[i++];
	fill(line,num2,i);
}

/**
 * Always check if num1=0 or num2=0, what would happen
 */
void check(string &num1,char op,string &num2)
{
	long long n1 = 2147483648;
    long long n2 = 2147483648;

	if(num1.length() <= 10)
		sscanf(num1.c_str(),"%lld",&n1);
	if(num2.length() <= 10)
		sscanf(num2.c_str(),"%lld",&n2);
	if(n1 > 2147483647)
		cout<<"first number too big"<<endl;
	if(n2 > 2147483647)
		cout<<"second number too big"<<endl;
	if(( n1 ==0 || n2 ==0) && op == '*')
        return;
    if(n1 >2147483647 || n2 > 2147483647)
	{	
		cout<<"result too big"<<endl;
		return;
	}
	long long result;
	if(op == '+')
		result = n1 + n2;
	else if(op == '*')
		result = n1*n2;
	if(result > 2147483647)
		cout<<"result too big"<<endl;	
}

int main()
{
	string line;
	while(!cin.eof())
	{
		getline(cin,line);
		if(line.length() < 3 ) break;
		string num1,num2;
		char op = '+';
		parse(line,num1,op,num2);
		if(num1.length() == 0 || num2.length() == 0) break;
		cout<<line<<endl;
		check(num1,op,num2);
	}
	return 0;

}
