#include <stdlib.h>
#include <stdio.h>
#include <iostream>


using namespace std;

int main()
{
	int numJ[5],numM[5];
	int contM = 0,contJ = 0; 

	for(int i = 0; i < 5; i++){
		cin >> numJ[i];
	}
	for(int i = 0; i < 5; i++){
		cin >> numM[i];
	}

	for(int i = 0; i < 5; i++)
	{
		if(numJ[i] % 2 == 0)
		{
			contJ++;
		}
		if(numM[i] % 2 == 0)
		{
			contM++;
		}
	}

	cout << contJ << "\n";
	cout << contM << "\n"; 
}