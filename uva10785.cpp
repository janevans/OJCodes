#include<algorithm>
#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

int  vowels[5];
int  consonant[21];
//char consonantChar[21]
char consonantChar[21];
//char vowelsChar[5]
char vowelsChar[5];

void reset()
{
	//memset fill the memory with char as unit!!!!!!
	//memset(vowels,0,5);
	memset(vowels,0,sizeof(int)*5);
	//memset fill the memory with char as unit!!!!!!
	//memset(consonant,0,21);
	memset(consonant,0,sizeof(int)*21);
}

void setup()
{
	vowelsChar[0] = 'A';
	vowelsChar[1] = 'U';
	vowelsChar[2] = 'E';
	vowelsChar[3] = 'O';
	vowelsChar[4] = 'I';
	consonantChar[0] = 'J';
	consonantChar[1] = 'S';
	consonantChar[2] = 'B';
	consonantChar[3] = 'K';
	consonantChar[4] = 'T';
	consonantChar[5] = 'C';
	consonantChar[6] = 'L';
	consonantChar[7] = 'D';
	consonantChar[8] = 'M';
	consonantChar[9] = 'V';
	consonantChar[10] = 'N';
	consonantChar[11] = 'W';
	consonantChar[12] = 'F';
	consonantChar[13] = 'X';
	consonantChar[14] = 'G';
	consonantChar[15] = 'P';
	consonantChar[16] = 'Y';
	consonantChar[17] = 'H';
	consonantChar[18] = 'Q';
	consonantChar[19] = 'Z';
	consonantChar[20] = 'R';
}

int main()
{
	int N;
	cin>>N;
	setup();
	for(int i=0;i<N;i++)
	{
		int L;
		cin>>L;
		reset();
		cout<<"Case "<<i+1<<": ";
		int vInd=0,cInd=0;
		/**
		 * To make it lexicographically smallest, we
		 * need to sort the odd position letters and 
		 * even position letters accordingly, and then
		 * add them back.
		 */
		int oddsLen = L/2+ (L&1?1:0);
	   	int evensLen = L/2;	
		char *odds = new char[oddsLen]();
		char *evens = new char[evensLen]();
		for(int j=0;j<L;j++)
		{
			if(j&1) //even
			{
				evens[j/2] = consonantChar[cInd];
				
				if(++consonant[cInd] == 5) cInd++;
			}else{ //odd
				odds[j/2] = vowelsChar[vInd]; 
				if(++vowels[vInd] == 21) vInd++;
			}
		}
		sort(odds,odds+oddsLen);
		sort(evens,evens+evensLen);
		for(int j=0;j<L;j++)
		{
			if(j&1) cout<<evens[j/2];
			else cout<<odds[j/2];
		}
        delete []odds;
        delete []evens;
		cout<<endl;
	}

}
