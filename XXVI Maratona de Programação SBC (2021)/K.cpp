#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int t,d,m;
	cin >> t >> d >> m;
	vector<int> refeicoes(m);
	bool can = false;
	
	//L� todos os hor�rios das refei��es
	for(int i=0;i<m;i++){
		cin >> refeicoes[i];
	}
	
	
	for(int i=0;i<refeicoes.size();i++){
		
		//Se o intervalo entre refei��es for maior que T, ele consegue descansar
		if(refeicoes[i+1] - refeicoes[i] >= t){
			can = true;
			break;
		}
		
		//Se o tempo at� a primeira refei��o por maior que T, ele consegue descansar
		if(i==0 && refeicoes[i] >= t){
			can = true;
			break;
		}
		
		//Se o tempo ap�s a ultima refei��o at� o t�rmino do voo for maior que T, ele consegue descansar
		if(d-refeicoes[refeicoes.size()-1] >= t){
			can = true;
			break;
		}
	}
	
	
	if(can || (m==0 && d>=t)) cout << "Y" << endl;
	else cout << "N" << endl;
	
	return 0;
}
