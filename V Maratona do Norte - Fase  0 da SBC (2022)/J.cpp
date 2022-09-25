#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ll long long
# define MOD 1000000007
# define EPS 1e-9
# define fi first
# define se second
#define _ ios_base::sync_with_stdio(0), cin.tie(NULL);
using namespace std;


int main() {_

    int t, n;
    string o;
    cin >> t;
    
    while(t--){
        cin >> n >> o;
        if(o[0]=='1'){
            if(n<=45){
                cout << n << endl;
            }
            else{
                cout << "45+" << n-45 << endl;
            }
        }
        else{
          if(n<=45){
                cout << 45+n << endl;
            } 
            else{
                cout << "90+" << (45+n)-90 << endl;
            }
        }
    }

    
	
return 0;
}