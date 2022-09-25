#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);

using namespace std;

int main(){_
	
	int gl=0, gr=0, pl=0, pr=0, turn=1;
	string eventos;
	
	cin >> eventos;
	
	for(int i=0; i<eventos.size();i++){
		
		if(turn == 1){
			if(eventos[i] == 'S'){pl++;}
			else if(eventos[i] == 'R'){pr++; turn=0;}
		}
		else if(turn == 0){
			if(eventos[i] == 'S') {pr++;}
			else if(eventos[i] == 'R') {pl++;turn=1;}		
		}
		
		if(eventos[i] == 'Q'){
			
			if(i == eventos.size() -1){
				if(pr > pl) gr++;
				else if(pl > pr) gl++;		
				
				if(gr > gl) cout << gl << " - " << gr << " (winner)" << endl;
				else if(gl > gr) cout << gl << " (winner) - " << gr << endl;
				
			}
			else{
				if(turn == 0) cout << gl << " (" << pl << ")" << " - " << gr << " (" << pr << "*)" << endl;
				else if(turn == 1) cout << gl << " (" << pl << "*)" << " - " << gr << " (" << pr << ")" << endl;				
			}
		}
		
		if(pr>=5 & pr-pl >= 2 || pr == 10){
			pr = 0;
			pl = 0;
			gr++;
			turn = 0;
		}
		
		else if(pl>=5 & pl-pr >= 2 || pl == 10){
			pr = 0;
			pl = 0;
			gl++;
			turn = 1;
		}
	}
	return 0;
}
