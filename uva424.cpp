#include<iostream>

using namespace std;

int result[111];

int main()
{
	string line;
	while(!cin.eof())
	{
		getline(cin,line);
		if(line=="0") break;
		int llen = line.length();
		int carry = 0;
		int i=0;
		for(;i<llen;i++)
		{
			//There will be a CR if you are using getline()!!!!,remember to avoid that!
			if(line[llen-1-i]>'9' || line[llen-1-i] <'0') continue;
			result[110-i] += (line[llen-1-i]-'0') + carry;
			carry = result[110-i]/10;
			result[110-i] %= 10;
		}
		while(carry>0)
		{
			result[110-i] = result[110-i] + carry;
			carry = result[110-i]/10;
			result[110-i] %= 10;
			i++;
		}
	}
	int s = 0;
	while(result[s] == 0) s++;
	for(;s<111;s++)
		cout<<result[s];
	cout<<endl;
	return 0;
}
