#include<iostream>

using namespace std;

class TrieNode
{
public:
	TrieNode* left;
	TrieNode* right;
	TrieNode():left(NULL),right(NULL){}
	~TrieNode()
	{
		delete left;
		delete right;
	}
};

class Trie
{
public:
	TrieNode* root;
	Trie()
	{
		root = new TrieNode();
	}
	~Trie()
	{
		delete root;
	}
	bool checkPrefix(string &str)
	{
		TrieNode* node = root;
		for(int i=0;i<str.length();i++)
		{
			//existing encoding is a prefix of current encoding.
			if(node->left == NULL && node->right == NULL && node != root)
				return true;
			if(str[i] == '0')
			{
				if(node->left == NULL)
					return false;
				node = node->left;
			}else if(str[i] == '1'){
				if(node->right == NULL)
					return false;
				node = node->right;
			}
		}
		//current encoding is a prefix of existing encoding.
		return true;
	}
	void insert(string &str)
	{
		TrieNode * node = root;
		for(int i=0;i<str.length();i++)
		{
			if(str[i] == '0')
			{
				if(node->left == NULL)
					node->left = new TrieNode();
				node = node->left;
			}else{
				if(node->right == NULL)
					node->right = new TrieNode();
				node = node->right;
			}	
		}
	}
	void clear()
	{
		delete root->left;
		root->left = NULL; // remember to reset pointer to NULL after usage!!!!
		delete root->right;
		root->right = NULL;// remember to reset pointer to NULL after usage!!!!
	}
};

void skip()
{
	string line = " ";
	while(!cin.eof() && line[0] != '9')
		getline(cin,line);
}
int main()
{
	string line;
	Trie trie;
	int count =1;
	while(!cin.eof())
	{
		getline(cin,line);
		if(line.length() == 0) continue;
		if(line[0] == '9')
		{
			cout<<"Set "<<count++<<" is immediately decodable"<<endl;
			trie.clear();
		}else{
			if(trie.checkPrefix(line))
			{
				trie.clear();
				skip();
				cout<<"Set "<<count++<<" is not immediately decodable"<<endl;
			}else{
				trie.insert(line);
			}
		}
	}
	return 0;
}
