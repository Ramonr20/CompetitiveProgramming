#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

int main() {
    std::string s;
    int i =1;

    do {
        std::cin >> s;
        if (s == "*")
            break;
        if (s == "Hajj")
            printf("Case %d: Hajj-e-Akbar\n", i++);
        else 
            printf("Case %d: Hajj-e-Asghar\n", i++);        
    }while (s != "*");

    return 0;
}