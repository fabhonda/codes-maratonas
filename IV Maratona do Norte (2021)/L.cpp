#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int main(){
	
	long long n,m,x,y;
	vector<long long> v,v2;
	set<long long> s;
	cin >> n >> m;
	while(m--){
		cin >> x >> y;
		v.pb(abs(x-y));
	}
	for(int i=0;i<v.size();i++){
		v2.pb(count(v.begin(),v.end(),v[i]));
	}
	long long mx = *max_element(v2.begin(),v2.end());
	if(mx*2 > n) cout << n/2 << endl;
	else cout << mx << endl;
	
	return 0;
}
