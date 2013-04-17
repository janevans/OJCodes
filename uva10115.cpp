#include<iostream>
#include<vector>
#include<list>
#include<cstdio>
using namespace std;


bool check(string &result, string &find)
{
	int rlen = result.length();
	int flen = find.length();
	if(result.length() < find.length()) return false;
	for(int i=0;i<flen;i++)
	{
		if(result[rlen-1-i] != find[flen-1-i])
			return false;
	}
	return true;
}

void shuffle(string &result,list<char> &aq, string &find,string &replace)
{
	int rlen = replace.length();
	int flen = find.length();
	for(int i=0;i<flen;i++)
		result.erase(result.end()-1);
	for(int i=0;i<rlen;i++)
		aq.push_front(replace[rlen-i-1]);
}
string applyRule(string &text,string &find,string &replace)
{
	list<char> aq;
	//list<char> aq(text.length()) will first fill aq with text.length() 0!!!!!
	for(int i=0;i<text.length();i++)
		aq.push_back(text[i]);
	string result="";
	while(!aq.empty())
	{
		result.push_back(aq.front());
		aq.pop_front();
		if(check(result,find))
			shuffle(result,aq,find,replace);
	}	
	return result;
}

string applyRule2(string &text,string &find,string &replace)
{
	string result = text;
	bool replaced = true;
	while(replaced)
	{
		replaced = false;
		for(int i=0;i<(int)result.length()-(int)find.length()+1;i++)
		/*
		   off by one error
			for(int i=0;i<(int)result.length()-(int)find.length()+1;i++)
		*/
		{
			int j = i;
			for(;j<i+find.length();j++)
				if(result[j] != find[j-i])
					break;
			if( j == i+find.length())
			{
				replaced = true;
				string newStr;
				for(int k=0;k<i;k++)
					newStr.push_back(result[k]);
				newStr.append(replace);
				for(int k=j;k<result.length();k++)
					newStr.push_back(result[k]);
				result = newStr;
				break;
			}

		}
	}
	return result;
}
int main()
{

	while(!cin.eof() )
	{
		int num=0;
		string line;
		getline(cin,line);
		if(line.length() == 1 && line[0] == '0') break;
		sscanf(line.c_str(),"%i",&num);
		vector<string> finds;
		vector<string> replaces;
		string find,replace,text;
		for(int i=0;i<num;i++)
		{
			getline(cin,find);
			getline(cin,replace);
			finds.push_back(find);
			replaces.push_back(replace);
		}
		getline(cin,text);
		for(int i=0;i<num;i++)
		{
			text = applyRule(text,finds[i],replaces[i]);
		}
		cout<<text<<endl;
	}
	return 0;
}
