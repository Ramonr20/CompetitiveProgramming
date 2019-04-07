#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){

	int a,b,c, N = 1;
	int ans = 0;

	while(N != 0){
		cin >> N;
		for(a = 1; a <= N; a++){
				for(b = a; b <= N; b++){
						for(c = b; c <= N; c++){
								if((a*a)+(b*b) == (c*c)){
										ans++;
								}
						}
				}
		}if(N != 0){
			cout << ans << "\n";
		}
	}	
	
}