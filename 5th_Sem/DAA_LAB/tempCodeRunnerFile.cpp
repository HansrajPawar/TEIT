#include<bits/stdc++.h>
using namespace std ;

int main()
{
	vector <int> v;
	v.push_back(1);v.push_back(11);v.push_back(10);v.push_back(10);
	v.at(2)=10;
	vector<int > :: iterator it = v.begin()+1;

	cout<<*(it)<<" ";

	

	return 0;
}