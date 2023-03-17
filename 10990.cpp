#include<bits/stdc++.h>
#define lli long long int 
#define vi vector<int> 
#define pii pair<int,int> 
#define mp make_pair 
#define pb push_back 
#define f0(n) for(int i = 0; i < n; ++i)
#define f1(n) for(int i = 1; i <= n; ++i)


using namespace std;

int const tam = 2000001;
int dp[tam], acumulada[tam], phi[tam];


void evaluate_phi(){
	phi[0] = 0, phi[1] = 1, phi[2] = 1, phi[3] = 2;
	int a = 0, b = 0;
	for(int i = 4; i < tam; ++i){
		bool found = false;
		for(int div = 2; div*div <= i; ++div){
			if(i % div == 0){
				a = div;
				found = true;
			}
			if(found)
				break;
		}
		if(found){
			int subi = i, am = 0;
			while(subi % a == 0){
				subi /= a;
				am++;
			}
			b = subi;
			if(b == 1){
				phi[i] = i - (i / a);
				continue;
			}

			phi[i] = phi[(i / b)] * phi[b];
			continue;

		}
		phi[i] = i - 1;
	}
}

void evaluatedepht(){
	dp[0] = 0, dp[1] = 0, dp[2] = 1, dp[3] = 2;
	for(int i = 4; i < tam; ++i){
		dp[i] = dp[phi[i]] + 1;
	}
	return;
}
void evaluateac(){
	acumulada[1] = dp[1];
	acumulada[2] = dp[2];
	for(int i = 3; i < tam; ++i){
		acumulada[i] = dp[i] + acumulada[i - 1];
	}
	return ;
}


int main(){

	int t, m ,n;
	cin >> t;
	
	evaluate_phi();	
	evaluatedepht();
	evaluateac();

	while(t--){
		cin >> m >> n;
		cout << acumulada[n] - acumulada[m-1]<<endl;
	}


	return 0;
}