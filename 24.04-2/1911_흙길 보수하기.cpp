// https://www.acmicpc.net/problem/1911
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,L,t,a,b,c;

int main(void) {
	vector<pair<int,int>> v;
	cin>>N>>L;
	for(int i=0;i<N;i++) {cin>>a>>b;v.push_back({a,b});}
	sort(v.begin(),v.end());
	for(int i=0;i<N;i++) {if(t<v[i].first)t=v[i].first;while(t<v[i].second){t+=L;c++;}}
	cout<<c;
 }