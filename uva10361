#include<iostream>
#include<sstream>
using namespace std;

void extractWords(string&,int,string&,string&,string&,string&);

void processPair(string &word1,string &word2)
{
	string s2,s3,s4,s5;
        for(size_t i=0;i<word1.length();i++)
	{
		if(word1[i] == '<')
		{
                    extractWords(word1,i,s2,s3,s4,s5);
                    break;
		}else{
                    cout<<word1[i]; 
		}
	}
	cout<<s2<<s3<<s4<<s5<<endl;
	for(size_t i=0;i<word2.length()-3;i++)
	{       
            cout<<word2[i];
	}
        cout<<s4<<s3<<s2<<s5<<endl;
	
}
/**
 * Please Read carefully on the instructions.
 * s1<s2>s3<s4>s5, just split them according to '<' and '>', it is much easier.
 */
void extractWords(string &word1,int start, string &s2, string &s3,string &s4,string &s5)
{
	start++;
	while(word1[start] != '>')
                s2.push_back(word1[start++]);
	start++;
	while(word1[start] != '<')
                s3.push_back(word1[start++]);
        start++;
        while(word1[start] != '>')
            s4.push_back(word1[start++]);
        start++;
        while(start<word1.length())
            s5.push_back(word1[start++]);
        
}

int main()
{
	string firstLine;
        getline(cin,firstLine);
        stringstream ss(firstLine);
        int num;
        ss>>num;
	for(int i=0;i<num;i++)
	{
		string word1,word2;
		getline(cin,word1);
		getline(cin,word2);
		processPair(word1,word2);
	}
	return 0;
}
