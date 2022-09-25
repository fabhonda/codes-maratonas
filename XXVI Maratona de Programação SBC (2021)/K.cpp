#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int t,d,m;
	cin >> t >> d >> m;
	vector<int> refeicoes(m);
	bool can = false;
	
	//Lê todos os horários das refeições
	for(int i=0;i<m;i++){
		cin >> refeicoes[i];
	}
	
	
	for(int i=0;i<refeicoes.size();i++){
		
		//Se o intervalo entre refeições for maior que T, ele consegue descansar
		if(refeicoes[i+1] - refeicoes[i] >= t){
			can = true;
			break;
		}
		
		//Se o tempo até a primeira refeição por maior que T, ele consegue descansar
		if(i==0 && refeicoes[i] >= t){
			can = true;
			break;
		}
		
		//Se o tempo após a ultima refeição até o término do voo for maior que T, ele consegue descansar
		if(d-refeicoes[refeicoes.size()-1] >= t){
			can = true;
			break;
		}
	}
	
	
	if(can || (m==0 && d>=t)) cout << "Y" << endl;
	else cout << "N" << endl;
	
	return 0;
}
