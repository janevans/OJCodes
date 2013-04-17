/**
A keyword ``occurs" in an excuse if and only if it exists in the string 
in contiguous form and is delimited by the beginning or end of the line 
or any non-alphabetic character or a space.

Plz read carefully into the instruction, then you will know how to define 
a keyword.
*/

#include<iostream>
#include<cstdio>
#include<set>
#include<ctype>
#include<stringstream>
#include<vector>
using namespace std;

string extractWord(string &word)
{
	int s = 0;
	string result;
	while(s<word.length() && !isalpha(word[s])) 
		s++;
	while(s<word.length() && isalpha(word[s])) 
		result.push_back(word[s++]);
	return result;
}

int countKeyWords(set<string> &keywords,string &line)
{
	string word;
	int matchCount = 0;
	stringstream ss(line);
	while(ss>>word)
	{
		if(keywords.count(extractWord(word)))
			matchCount++;
	}
	return matchCount;
}
int main()
{
	int wordNum,excuseNum;
	int setCounter = 0;
	while(cin>>wordNum && cin>>excuseNum)
	{
		setCounter++;
		set<string> keywords;
		string w;
		for(int i=0;i<wordNum;i++)
		{	
			cin>>w;
			keyword.insert(w);
		}
		int lamestCount=0;
		string line;
		geline(cin,line);
		vector<string> lamest;
		for(int i=0;i<excuseNum;i++)
		{
			getline(cin,line);
			int count = countKeyWords(keywords,line);
			if(count > lamestCount)
			{
				
				lamestCount = count;
				lamest.clear();
				lamest.push_back(line);
			}else if(count == lamestCount){
				lamest.push_back(line);
			}
		}
		cout<<"Excuse Set #"<<setCounter<<endl;
		for(size_t i=0;i<lamest.size();i++)
			cout<<lamest[i]<<endl;
		cout<<endl;
	}
	return 0;
}

