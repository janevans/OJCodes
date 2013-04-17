#include<iostream>
using namespace std;
int main()
{
	string result;
	string line;
	while(!cin.eof())
	{
		getline(cin,line);
		if(line.length()>=11 && line[0] == '|' && line[10] == '|')
		{
			char a=0;
			for(int i=0;i<8;i++)
			{
				if( line[9-i-(i>2?1:0)] == 'o')
					a |= (1<<i);
			}
                        result.push_back(a);
		}
	}
        cout<<result<<endl;
}
