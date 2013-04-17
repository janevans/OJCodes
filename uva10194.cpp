#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<map>
#include<cctype>
#include<climits>
using namespace std;

string tolowerStr(string str)
{
	string lowerStr('0',str.length());
	for(int i=0;i<str.length();i++)
		lowerStr[i] = tolower(str[i]);
	return lowerStr;
}

class Team{
public:
	string name;
	int b;
	int c;
	int d;
	int e;
	int f;
	int g;
	int h;
	int i;
 	Team(string n):b(0),c(0),d(0),e(0),f(0),g(0),h(0),i(0),name(n){}

	bool operator<(Team tb)const
	{
		//most points earned
		if(b<tb.b) return true;
		if(b>tb.b) return false;
		//most wins
		if(d<tb.d) return true;
		if(d>tb.d) return false;
		//most goal difference
		if(g<tb.g) return true;
		if(g>tb.g) return false;
		//most goals scored
		if(h<tb.h) return true;
		if(h>tb.h) return false;
		//less games played
		if(c>tb.c) return true;
		else if(c<tb.c) return false;
		//lexicographic order
		return tolowerStr(name)>tolowerStr(tb.name); 
	}
};
void parseMatch(string &match,vector<Team> &teams,map<string,int> &teamInds)
{
 	string team1,team2;
 	int g1=0,g2=0;
 	int i=0;
 	while(match[i] !='#')
		team1.push_back(match[i++]);
 	i++;
 	while(match[i] != '@')
	 	g1 = g1*10 + (match[i++]-'0');
 	i++;
 	while(match[i] != '#')
	 	g2 = g2*10 + (match[i++]-'0');
	i++;
    /**
     * dead loop:
     * while(i<match.length())
     *    if(match[i]>=32)
     *        team2.push_back(match[i++])
     */
	while(i<match.length())
		team2.push_back(match[i++]);
	int ind1 = teamInds[team1];
	int ind2 = teamInds[team2];
	if(g1 > g2)
	{
		teams[ind1].b+=3;
		teams[ind1].d++;
		teams[ind2].f++;
	}else if(g1 == g2){
		teams[ind1].b++;
		teams[ind2].b++;
		teams[ind1].e++;
		teams[ind2].e++;
	}else if(g1<g2){
		teams[ind2].b+=3;
		teams[ind2].d++;
		teams[ind1].f++;
	}
	teams[ind1].c++;
	teams[ind2].c++;
	teams[ind1].h += g1;
	teams[ind1].i += g2;
	teams[ind2].h += g2;
	teams[ind2].i += g1;
	teams[ind1].g = teams[ind1].h - teams[ind1].i;
	teams[ind2].g = teams[ind2].h - teams[ind2].i;

}

int main()
{
	int N;
	cin>>N;
	cin.ignore();
	for(int i=0;i<N;i++)
	{
		string tournamentName;
		getline(cin,tournamentName);
		int M;
		cin>>M;
		cin.ignore();
		map<string,int> teamInds;
		vector<Team> teams;
		string teamName;
		for(int j=0;j<M;j++)
		{
			getline(cin,teamName);
			teams.push_back(Team(teamName));
			teamInds[teamName] = j;
		}
		cin>>M;
		cin.ignore();
		string match;
		for(int j=0;j<M;j++)
		{
			getline(cin,match);
			parseMatch(match,teams,teamInds);
		}
		sort(teams.begin(),teams.end());
		cout<<tournamentName<<endl;
		for(int j=(int)teams.size()-1;j>=0;j--)
		{
			cout<<teams.size()-j<<") "<<teams[j].name<<" "<<teams[j].b<<"p, "
			<<teams[j].c<<"g ("<<teams[j].d<<"-"<<teams[j].e<<"-"<<teams[j].f
			<<"), "<<(teams[j].g==INT_MIN?0:teams[j].g)<<"gd ("<<teams[j].h<<"-"<<teams[j].i<<")"<<endl;
		}	
		if(i<N-1) cout<<endl;
	}	
	return 0;
}
