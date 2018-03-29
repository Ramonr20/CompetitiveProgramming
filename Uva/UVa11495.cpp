#include <bits/stdc++.h>

using namespace std;

int merge(int arr[], int tmp[], int l, int m, int r) {
   
	int i, j, k;
	int inv_count = 0;
	i = l;
	j = m;
	k = l;

    	while ((i <= m - 1) && (j <= r)) {
        	if (arr[i] < arr[j]) {
            		tmp[k++] = arr[i++];
        	}else {
            		tmp[k++] = arr[j++];
			
			inv_count += (m - i);
        	}
    	}	
    
   	while (i <= m - 1)
        	tmp[k++] = arr[i++];
    	while (j <= r)
        	tmp[k++] = arr[j++];
	for (i = l; i <= r; ++i)
		arr[i] = tmp[i];

        return inv_count;
}

int mergeSort(int arr[], int tmp[], int l, int r) {
	int m, inv_count = 0;

	if (r > l) {
		m = (l + r) / 2;

        	inv_count = mergeSort(arr, tmp, l, m);
        	inv_count += mergeSort(arr, tmp, m+1, r);
        	inv_count += merge(arr, tmp, l, m+1, r);
	}
	return inv_count; 
}


int _mergeSort(int arr[], int array_size) {

	int *temp = new int[array_size];
	return mergeSort(arr, temp, 0, array_size - 1);
}

int main() {
	int N, aux, convs, i = 0;
	int *arr;
	while (scanf("%d", &N), N) {
		arr = new int[N];
		aux = N;
		while (aux--)
			scanf("%d", &arr[i++]);
		convs = _mergeSort(arr,N);
		cout << convs << "\n";
		if(convs % 2 == 0)
			cout << "Marcelo\n";
		else
			cout << "Carlos\n";
	}

	return 0;
}
