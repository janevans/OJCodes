#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<cctype>
#include<set>
using namespace std;


int main()
{
	string word;
	map<string,vector<string> > dictionary;
	while(cin>>word)
	{
		if(word == "#")
			break;
		string key(word);
		for(int i=0;i<key.length();i++)
			key[i] = tolower(key[i]);
		sort(key.begin(),key.end());
		dictionary[key].push_back(word);
	}
	set<string> result;
	for(map<string,vector<string> >::iterator iter=dictionary.begin();
		iter != dictionary.end();iter++)
	{
		if((iter->second).size() == 1)
			result.insert((iter->second)[0]);
	}
	for(set<string>::iterator iter=result.begin();
		iter != result.end();iter++)
		cout<<*iter<<endl;
	return 0;
}
