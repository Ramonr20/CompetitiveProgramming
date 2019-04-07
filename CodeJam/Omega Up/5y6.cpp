#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define MAX_CHAR 7

using namespace std;

int calculateMax(char a[]){

    for(int i = 0; i < MAX_CHAR; ++i){
        if(a[i] == '5')
            a[i] = '6';
    }
    return atoi(a);
}
int calculateMin(char a[]){

    for(int i = 0; i < MAX_CHAR; ++i){
        if(a[i] == '6')
            a[i] = '5';
    }
    return atoi(a);
}
int main(){

    char a[MAX_CHAR],b[MAX_CHAR];
    int max,min;

    for(int i = 0; i < MAX_CHAR; ++i){
        a[i] = 0;
        b[i] = 0;
    }
    
    cin >> a >> b;

    max = calculateMax(a);
    max += calculateMax(b);
    
    min = calculateMin(a);
    min += calculateMin(b);

    cout << min << " " << max << "\n";

    return 0;
}