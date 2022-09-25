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

int n, v;

struct Corredor {
    int id, melhor_volta, tempo_total, vez_melhor_volta;
};

bool cmp (Corredor a, Corredor b) {
    return a.tempo_total < b.tempo_total;
}


int main () {_
    scanf("%d %d", &n, &v);
    
    vector<Corredor> vet(n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i].id);
        
        vet[i].melhor_volta = INF;
        
        for (int j = 0, min, seg, mseg; j < v; j++) {
            scanf("%d:%d:%d", &min, &seg, &mseg);
            int tempo_em_mseg = 60000 * min + 1000 * seg + mseg;
            vet[i].tempo_total += tempo_em_mseg;
            
            if (tempo_em_mseg < vet[i].melhor_volta) {
                vet[i].melhor_volta = tempo_em_mseg;
                vet[i].vez_melhor_volta = vet[i].tempo_total;
            } 
        }
    }
    
    sort(all(vet), cmp);
    
    // for (int i = 0; i < n; i++) {
    //     cout << i << "º\n";
    //     cout << "ID = " << vet[i].id << "\n";
    //     cout << "Tempo = " << vet[i].tempo_total << "\n";
    //     cout << "Melhor volta = " << vet[i].melhor_volta << "\n";
    //     cout << "Vez melhor = " << vet[i].vez_melhor_volta << "\n\n";
    // }
    
    int melhor_volta_global = INF, vez_melhor_volta_global = INF, vencedor = -1;
    
    for (int i = 0; i < n; i++) {
        melhor_volta_global = min(melhor_volta_global, vet[i].melhor_volta);
    }
    
    for (int i = 0; i < min(n, 9); i++) {
        if (vet[i].melhor_volta == melhor_volta_global && vet[i].vez_melhor_volta < vez_melhor_volta_global) {
            vez_melhor_volta_global = vet[i].vez_melhor_volta;
            vencedor = vet[i].id;
        }
    }
    
    if (vencedor == -1) {
        cout << "NENHUM\n";
    }
    
    else {
        cout << vencedor << "\n";
    }
}