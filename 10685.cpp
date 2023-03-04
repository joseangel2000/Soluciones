#include<bits/stdc++.h>
#define f0(n) for(int i = 0; i < n; ++i)
#define pb push_back
using namespace std;


unordered_map<string, string> parent;
unordered_map<string, int> ssize;

string findpar(string s){
	string k = s;
	while(parent[k] != k)
		k = parent[k];
	//cout << "papa "<<s<<" = "<<k<<endl;
	return parent[s] = k;
}
void unite(string a, string b){
	string pa = findpar(a);
	string pb = findpar(b);
	if(pa == pb){
		return ;
	}
	if(pa < pb){
		parent[pb] = pa;
		parent[b] = pa;
		ssize[pa] = ssize[pa] + ssize[pb];
		return ;
	}
	else{
		parent[pa] = pb;
		parent[a] = pb;
		ssize[pb] = ssize[pb] + ssize[pa];
	}
	return ;
}

int main(){
	int C, R;
	string saux, saux2;
	while(true){
		parent.clear();
		ssize.clear();
		cin >> C >> R;
		if(!C && !R)
			break;
		vector<string> animal;
		f0(C){
			cin >> saux;
			animal.pb(saux);
			parent[saux] = saux;
			ssize[saux] = 1;
		}
		f0(R){
			cin >> saux >> saux2;
			unite(saux, saux2);
		}
		int ans = 0;
		f0(animal.size()){
			ans = max(ans, ssize[findpar(animal[i])]);
		}
		cout << ans << endl;
	}

	return 0;
}