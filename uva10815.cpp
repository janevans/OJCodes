#include<iostream>
#include<cstdio>
#include<cctype>
#include<sstream>
#include<map>
#include<string>
using namespace std;


class TrieNode{
public:
	bool isEnd;
	char nodeChar;
   	map<char,TrieNode*> children;	
	TrieNode(char c=0):nodeChar(c),isEnd(false){}
	void insert(const string &str,int i)
	{
		if(i == str.length())
		{		
			isEnd = true;
			return;
		}
		char c = str[i];
		if(children.count(c) == 0)
			children[c] = new TrieNode(c);
		children[c]->insert(str,i+1);
	}	
	void print(string &buffer)
	{
		if(isEnd)
		{	
			cout<<buffer<<endl;
		}
		for(map<char,TrieNode*>::iterator iter = children.begin();
			iter != children.end();iter++)
		{
			buffer.push_back(iter->first);
			iter->second->print(buffer);
			buffer.erase(buffer.end()-1);
		}
		
	}
	~TrieNode()
	{
		for(map<char,TrieNode*>::iterator iter = children.begin();
			iter != children.end();iter++)
			delete (iter->second);
		children.clear();
	}
};

class Trie{
public:
	TrieNode root;
	Trie(){}
	~Trie(){}
	void insert(string &str)
	{
		root.insert(str,0);
	}
	void printTree()
	{
		string buffer;
		root.print(buffer);	
	}

};

int main()
{
	string line;
	Trie trie;
	while(!cin.eof())
	{
		getline(cin,line);
		for(int i=0;i<line.length();i++)
		{	
			if(!isalpha(line[i]))
				line[i] = ' ';
			else
				line[i] = tolower(line[i]);
		}
		stringstream ss(line);
		string word;
		while(ss>>word)
			trie.insert(word);
	}
	trie.printTree();

}


