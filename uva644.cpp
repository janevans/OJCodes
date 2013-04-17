#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;
void skip()
{
	string line = " ";
	while(!cin.eof() && line[0] != '9')
		getline(cin,line);
}
bool checkPrefix(string &shortStr,string &longStr)
{
	for(int i=0;i<shortStr.length();i++)
		if(shortStr[i] != longStr[i])
			return false;
	return true;
}
bool check(map<int,vector<string> > &table, string &line)
{
	for(map<int,vector<string> >::iterator iter = table.begin();
		iter != table.end();iter++)
	{
		if(iter->first < line.length())
        {
            for(int j=0;j<iter->second.size();j++)
                if(checkPrefix((iter->second)[j],line)) return true;
        }else{
            for(int j=0;j<iter->second.size();j++)
                if(checkPrefix(line,(iter->second)[j])) return true;
        }
	}
	return false;
}

int main()
{
	map<int,vector<string> > table;
	string line;
	int count=1;
	while(!cin.eof())
	{
		getline(cin,line);
		bool violated = false;
		if(line[0] == '9') //if(line[0] == 9)......
		{
			table.clear();
			cout<<"Set "<<count++<<" is immediately decodable"<<endl;
			continue;
		}else{
			violated = check(table,line);
		}
		if(violated){
			cout<<"Set "<<count++<<" is not immediately decodable"<<endl;
			table.clear();
			skip();
		}else{
			table[line.length()].push_back(line);
		}
	}
	return 0;
}
