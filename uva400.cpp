#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N;
	while(cin>>N)
	{
		vector<string> fileNames;
		int maxLength = 0;
		string name;
		for(int i=0;i<N;i++)
		{
			cin>>name;
			fileNames.push_back(name);
			if(name.length() > maxLength)
				maxLength = name.length();
		}
		sort(fileNames.begin(),fileNames.end());
		int columnCount = 1;
		int currentLength = maxLength;
		while(currentLength + maxLength + 2 <= 60)
		{
			columnCount++;
			currentLength += maxLength +2;
		}
		int R = fileNames.size()/columnCount + (fileNames.size()%columnCount==0?0:1);
		for(int i=0;i<60;i++)
			cout<<"-";
		cout<<endl;
		for(int i=0;i<R;i++)
		{	
			for(int j=0;j<columnCount;j++)
			{
				int ind = j*R + i;
				int len = (j==columnCount-1?maxLength:maxLength+2);
				if(ind < fileNames.size())
				{
					cout<<fileNames[ind];
					for(int l=0;l<(len-fileNames[ind].length());l++)
						cout<<" ";
				}
			}
			cout<<endl;
		}
	}
}
