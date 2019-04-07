#include <iostream>
#include <stdio.h>

using namespace std;

int sumatoriaIzq(int pivote){
	int suma1 = 0;

	for(int i = 1; i < pivote; i++){
			suma1 += i;
	}
	// cout <<"suma 1: "<< suma1<<"\n";
	return suma1;
}

int sumatoriaDer(int pivote, int cantCasas){
	int suma2 = 0;

	for(int i = pivote + 1; i <= cantCasas; i++){
					suma2 += i;
	}
	// cout <<"suma 2: "<< suma2<<"\n";
	return suma2;
}

int main(){

	int N;
	int suma1, suma2;

	int pivote;
	int ans;
	do{
		cin >> N;
		ans = 0;
		pivote = 2;
		while(pivote <= (N-1)){
			// cout << ans <<"\n";
			suma1 = sumatoriaIzq(pivote);
			suma2 = sumatoriaDer(pivote,N);
			if(suma1 == suma2){
				ans = pivote;
				break;
			}			
				pivote++;
		}
		if(ans == 0){
			ans = -1;
		}
			cout << ans << "\n";

	}while(N != 0);

	return 0;
}