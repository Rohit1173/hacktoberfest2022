#include<bits/stdc++.h>

using namespace std;
int main()
{	vector <long int> v;
	stack <long int> s;
	long int t,i,n;
	long long max_xor=0,min_xor;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>t;
		v.push_back(t);
	}
	for(i=0;i<n;i++)
	{
		while(!s.empty())
		{
			min_xor=v[i]^s.top();
			if(min_xor>max_xor)
			max_xor=min_xor;
			if(v[i]<s.top())
			s.pop();
			else
			break;
		}
		s.push(v[i]);
	}
	cout<<max_xor<<endl;
}