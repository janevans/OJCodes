#include<iostream>
#include<map>
#include<cstring>
using namespace std;


bool readNCode(int N,int *code)
{
	memset(code,0,N);
	bool allZero = true;
	for(int i=0;i<N;i++)
	{
		cin>>code[i];
		if(code[i] != 0) allZero = false;
	}
	return allZero;
}

int main()
{
	int N;
	int count = 0;
	while(true)
	{
		cin>>N;
		if(N == 0) break;
		cout<<"Game "<<++count<<":"<<endl;
		int* secret = new int[N]();
		readNCode(N,secret);
		int* guess = new int[N]();
		while(!readNCode(N,guess))
		{
			int strongMatch=0,weakMatch = 0;
			map<int,int> restCode;
			bool* used = new bool[N]();
			for(int i=0;i<N;i++)
			{
				if(guess[i] == secret[i])
				{	
					strongMatch++;
					used[i] = true;
				}else{
					restCode[guess[i]]++;
				}
			}
			for(int i=0;i<N;i++)
			{
				if(!used[i] && restCode[secret[i]]>0)
				{
					restCode[secret[i]]--;
					weakMatch++;
				}
			}
			cout<<"    ("<<strongMatch<<","<<weakMatch<<")"<<endl;
			delete[] used;

		}
		delete[] secret;
		delete[] guess;
	}
	return 0;
}
