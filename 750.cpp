#include<bits/stdc++.h>

using namespace std;

const int sz = 30;
const int cbsz = 8;
int col[sz], a, b, t, lineCounter = 0;

bool place(int reina, int fila){
	// reina anterior
	for(int rant = 1; rant < reina; ++rant){
		if(col[rant] == fila || (abs(rant - reina) == abs(fila - col[rant])))
			return false;
	}
	return true;
}
void solve(int reina){
	for(int row = 1; row <= cbsz; ++row){
		if(place(reina, row)){
			col[reina] = row;
			if(reina == cbsz && col[b] == a){
				if(lineCounter < 10) cout<<" "<<lineCounter<<"     ";
            	 else cout<<lineCounter<<"     ";
            	 lineCounter++;
                for(int j = 1; j <= 8; j++)
                	cout << " "<<col[j];
                printf("\n");
			}
			else{
				solve(reina + 1);
			}
		}
	}


}




int main(){

	cin >> t;
    while(t--)
    {
        cin >> a >> b;
        memset(col, 0, sizeof(col));
        lineCounter = 1;
        cout<<"SOLN       COLUMN"<<endl<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;
        solve(1);
        if(t)
        	cout << endl;
    }
    return 0;


	return 0;
}