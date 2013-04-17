#include<iostream>

using namespace std;


int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int M;
		cin>>M;
		int *nums = new int[M]();
		for(int j=0;j<M;j++)
			cin>>nums[j];
		int swapCounts = 0;
		for(int k=0;k<M;k++)
		{
			int l;
			for(l=k;l<M;l++)
				if(nums[l] == k+1) break;
			while(l>k)
			{
				int temp = nums[l-1];
				nums[l-1] = nums[l];
				nums[l--] = temp;
				swapCounts++;
			}
		}
		delete[] nums;
		cout<<"Optimal train swapping takes "<<swapCounts<<" swaps."<<endl;
	}
}
