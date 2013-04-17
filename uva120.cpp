#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

void flip(int *pancakes,int p)
{
	int s=0;
	while(s<p)
	{
		int temp = pancakes[s];
		pancakes[s++] = pancakes[p];
		pancakes[p--] = temp;
	}
}


void sortPancake(int *pancakes,int psize)
{
	for(int i=psize-1;i>=0;i--)
	{
		int maxPos = i;
		for(int j=i-1;j>=0;j--)
		{
			if(pancakes[j] > pancakes[maxPos])
				maxPos = j;
		}
		if(maxPos < i)
		{
			if(maxPos>0)
			{
				printf("%i ",psize-maxPos);
				flip(pancakes,maxPos);
			}
			printf("%i ",psize-i);
			flip(pancakes,i);
		}
	}
	printf("0\n");
}

int pancakes[30];
char buffer[1000];
int main()
{
	while(!cin.eof())
	{
		cin.getline(buffer,1000);
        int i=0,sz=0,num=0;
		if(buffer[0] == '\0')break;
        while(buffer[i]==' ' ||(buffer[i]>='0' && buffer[i]<='9') )
        {
            if(buffer[i] == ' ')
            {
                pancakes[sz++] = num;
                num = 0;
                while(buffer[i] == ' ') i++;
            }else{
                num = num*10 + (buffer[i]-'0');
            	i++;
            }
        }
        pancakes[sz++] = num;
		printf("%s\n",buffer);
		sortPancake(pancakes,sz);
	}
}

