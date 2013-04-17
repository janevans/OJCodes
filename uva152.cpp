#include<iostream>
#include<vector>
#include<cmath>

using namespace std;


class Point{
public:
	double x;
	double y;
	double z;
	double minDistance;
	Point(double _x,double _y,double _z):x(_x),y(_y),z(_z),minDistance(-1){}
	double distance(Point p1)
	{
		return sqrt((p1.x-x)*(p1.x-x) +
					(p1.y-y)*(p1.y-y) +
					(p1.z-z)*(p1.z-z) );
	}
	//void updateMinDistance(double distance)
	void update(double distance)
	{
		if(minDistance == -1)
			minDistance = distance;
		else
			minDistance = distance<minDistance?distance:minDistance;
	}
};

int main()
{
 	vector<Point> points;
	double a,b,c;
	while(cin>>a>>b>>c)
	{
		if(a==0 && b==0 && c==0) break;
		double mindisc = -1;
		//Point pt = new Point(a,b,c);
		Point pt(a,b,c);
		for(int i=0;i<points.size();i++)
		{
			double disc = points[i].distance(pt);
			points[i].update(disc);
			pt.update(disc);
		}
		points.push_back(pt);
	}	
	//int a[10];
	int count[10];
	for(int i=0;i<10;i++) count[i] = 0;
	for(int i=0;i<points.size();i++)
	{
		int disc = (int)points[i].minDistance;
		if(disc>=0 && disc<=9)
			count[disc]++;
	}
	for(int i=0;i<10;i++)
    {
        if(count[i]<10)
            cout<<"   "<<count[i];
        else if(count[i]<100)
            cout<<"  "<<count[i];
        else if(count[i]<1000)
            cout<<" "<<count[i];
        else
            cout<<count[i];
    }
	cout<<endl;
	return 0;
}
