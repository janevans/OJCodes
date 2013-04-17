#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

void readN(int* a,int n)
{
	for(int i=0;i<n;i++)
		cin>>a[i];
}

int main()
{
	int N,M;
	int count = 1;
	while(true)
	{
		cin>>N>>M;
		if(N==0 && M==0) break;
		cout<<"CASE# "<<count++<<":"<<endl;
		int* marbles = new int[N]();
		int* queries = new int[M]();
		readN(marbles,N);
		readN(queries,M);
		sort(marbles,marbles+N);
		map<int,int> indices;
		int prev = marbles[0]-1;
		for(int i=0;i<N;i++)
		{
			if(marbles[i] != prev)
			{
				prev = marbles[i];
				indices[marbles[i]] = i+1;
			}
		}
		for(int i=0;i<M;i++)
		{
			map<int,int>::iterator iter = indices.find(queries[i]);
			if(iter == indices.end())
				cout<<queries[i]<<" not found"<<endl;
			else
				cout<<queries[i]<<" found at "<<iter->second<<endl;
		}
		delete[] marbles;
		delete[] queries;
	}

	return 0;
}
