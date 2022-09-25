#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int main(){
	
	string a = "abcdefghijklmnopqrstuvwxyz";
	string s; cin >> s;
	
	vector<char> c, r;
	for(int i=0;i<s.size();i++){c.pb('#');r.pb('#');}
	
	int k=0; bool found;
	for(int i=0;i<s.size();i++){
		found = false;
		for(int j=0;j<c.size();j++){
			if(s[i] == c[j]){
				c[i] = c[j];
				r[i] = r[j];
				found = true;
				break;
			}
		}
		if(!found){
			c[i] = s[i];
			r[i] = a[k];
			k++;
		}
		
	}
	
	for(int i=0;i<r.size();i++){
		cout << r[i];
	}
	cout << endl;
	
	return 0;
}
