#include<iostream>
#include<map>
#include<sstream>
#include<cstdio>
using namespace std;

int main()
{
	int N;
	string line;
	getline(cin,line);
	sscanf(line.c_str(),"%i",&N);
	map<string,int> table;
	for(int i=0;i<N;i++)
	{
		getline(cin,line);
		string country;
		for(int i=0;i<line.length();i++)
		{
			if(line[i] == ' ') break;
			country.push_back(line[i]);
		}
		table[country]++;
	}
	for(map<string,int>::iterator iter = table.begin();
			iter != table.end();iter++)
	{
		cout<<iter->first<<" "<<iter->second<<endl;
	}
}

