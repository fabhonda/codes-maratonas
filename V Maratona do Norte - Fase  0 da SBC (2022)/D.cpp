# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
# define MAXN 200309
# define MOD 1000000007
# define INF 0x3f3f3f3f
# define INFLL 0x3f3f3f3f3f3f3f3f
# define EPS 1e-9
# define PI 3.141592653589793238462643383279502884
# define pb push_back
# define pf push_front
# define fi first
# define se second
# define mp make_pair
# define sz(x) int(x.size())
# define all(x) x.begin(), x.end()
# define mset(x,y) memset(&x, (y), sizeof(x))

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n;
map<int, float> pontuacoes;
string certa;

int distancia (string x, int a, string y, int b) {
    if (a == 0 || b == 0) {
        return max(a, b);
    }
    
    return min({distancia(x, a, y, b - 1) + 1, distancia(x, a - 1, y, b) + 1, distancia(x, a - 1, y, b - 1) + (x[a - 1] != y[b - 1])});
}

int main () {_
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> certa;
        
        vector<int> distancias;
        
        for (int j = 1; j <= 5; j++) {
            string resposta;
            cin >> resposta;
            distancias.push_back(distancia(resposta, sz(resposta), certa, sz(certa)));
            // cout << certa << " " << resposta << " " <<distancias.back() << "\n";
        }
        
        int menor_distancia = INF;
        vector<int> alunos_com_menor;
        
        for (int j = 1; j <= 5; j++) {
            if (distancias[j - 1] < menor_distancia) {
                menor_distancia = distancias[j - 1];
                alunos_com_menor.clear();
                alunos_com_menor.pb(j);
            } 
            
            else if (distancias[j - 1] == menor_distancia) {
                alunos_com_menor.pb(j);
            }
        }
        
        if (menor_distancia == 0) {
            for (auto aluno: alunos_com_menor) {
                pontuacoes[aluno] += 1.0;
            }
        }
        
        else {
            for (auto aluno: alunos_com_menor) {
                pontuacoes[aluno] += 0.5;
            }
        }
    }
    
    float maior_nota_geral = -1.0;
    vector<int> alunos_com_maior;
    
    for (auto [k, v]: pontuacoes) {
        if (v > maior_nota_geral) {
            maior_nota_geral = v;
            alunos_com_maior.clear();
            alunos_com_maior.pb(k);
        }
        
        else if (v == maior_nota_geral) {
            alunos_com_maior.pb(k);
        }
    }
    
    cout << fixed << setprecision(1) << maior_nota_geral << "\n";
    
    int tam = sz(alunos_com_maior);
    
    for (int i = 0; i < tam; i++) {
        cout << alunos_com_maior[i] << " \n"[i == tam - 1];
    }
}