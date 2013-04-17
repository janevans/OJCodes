#include<iostream>
#include<set>
#include<vector>
#include<cctype>
#include<map>
using namespace std;

void printLine(string &line,int ind)
{
	string backup;
	while(ind<line.length() && isalpha(line[ind]))
	{
		backup.push_back(line[ind]);
		line[ind] = toupper(line[ind]);
		ind++;
	}
	cout<<line<<endl;
	ind -= backup.length();
	for(int i=0;i<backup.length();i++)
		line[ind+i] = backup[i];
}

int main()
{
	string line;
	set<string> ignoreWords;
	while(true)
	{
		cin>>line;
		if(line == "::") break;
		for(int i=0;i<line.length();i++)
			line[i] = tolower(line[i]);
		ignoreWords.insert(line);
	}
	vector<string> lines;
	set<string> keywords;
	vector<map<string,vector<int> > > lineKeywords;
	while(!cin.eof())
	{
		getline(cin,line);
		int i=0;
		map<string,vector<int> > lkw;
		while(i<line.length())
		{
			while(i<line.length() && !isalpha(line[i])) i++;
			if(i==line.length()) break;
			string word;
			while(i<line.length() && isalpha(line[i]))
			{
				line[i] = tolower(line[i]);
				word.push_back(line[i++]);
			}
			if(ignoreWords.count(word) == 0) //it's a keyword 
			{
				keywords.insert(word);
				lkw[word].push_back(i-word.length());
			}
		}
		lines.push_back(line);
		lineKeywords.push_back(lkw);
	}

	for(set<string>::iterator iter = keywords.begin();iter!=keywords.end();iter++)
	{
		for(int i=0;i<lineKeywords.size();i++)
		{
			if(lineKeywords[i].find(*iter) != lineKeywords[i].end())
			{
				for(int j=0;j<lineKeywords[i][*iter].size();j++)
				{
					int ind = lineKeywords[i][*iter][j];
					printLine(lines[i],ind);
				}
			}
		}
	}	
	return 0;
}
