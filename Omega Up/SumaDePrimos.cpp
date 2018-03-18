#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

bool primo(int num);

int main(){
	
	int n,cont;
	int suma;
	int p = 0, q = 0;
	cin >> n;

	int arr[n];

	if(n != 1)
	{
	//incializar arr
		for(int i = 0; i < n; i++)
		{
			arr[i] = i+2;
		}

		int i,j;
		for(i = 0; i < n; i++)
		{
			for(j = i; j < n;j++)
			{
				suma = 0;
				if(primo(arr[j]) && primo(arr[i]))
				{
					suma = arr[j] + arr[i];	
					if(n == suma)
					{	
						p = arr[j];
						q = arr[i];
						break;
					}			
				}
			}
			if(n == suma) break;
		}

		if(primo(n))
		{
			p = n;
			q = 0;
		}
	}	
	cout << p << " " << q << "\n";

	return 0;
}

bool primo(int num)
{
    int contador,primo;

        primo = 1;
        contador = 2;

        while ( contador <= num / 2 && primo )
        {
            if ( num % contador == 0 )
                primo = 0;

            contador++;
        }

        if ( primo )
              return true;

    return false;      
}




