#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);

using namespace std;

void combinationUtil(vector<long long int> arr, long long int data[], long long int start, long long int end, long long int index, long long int r);
void printCombination(vector<long long int> arr, long long int n, long long int r);

long long int possi=0, a, b;

int main(){_

long long int n, k, peso, m=1000000007;
vector<long long int> pesos;

scanf("%lli %lli", &n, &k);

for(long long int i=0;i<n;i++){
	cin >> peso;
	pesos.push_back(peso%m);
}

scanf("%lli %lli", &a, &b);

a = a%m;
b = b%m;

printCombination(pesos, n, k);

printf("%lli", possi);

return 0;

}

void printCombination(vector<long long int> arr, long long int n, long long int r){
    long long int data[r];
    combinationUtil(arr, data, 0, n-1, 0, r);
}

void combinationUtil(vector<long long int> arr, long long int data[], long long int start, long long int end, long long int index, long long int r){
	long long int soma2=0;
    if (index == r){
        for (long long int j = 0; j < r; j++) soma2 += data[j];
        if(soma2 >= a && soma2 <= b) possi++;
        return;
    }

    for (long long int i = start; i <= end && end - i + 1 >= r - index; i++){
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}
