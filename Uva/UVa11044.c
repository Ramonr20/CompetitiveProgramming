#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {

    int t, a, b, i;
    scanf("%d", &t);
    int ans[t][2];

    for (i = 0; i < t; ++i) {
        scanf("%d %d",&a, &b);
        ans[i][0] = a;
        ans[i][1] = b;
    }

    for (i = 0; i < t; ++i) {
        printf("%i\n", (int) floor((ans[i][0]/3)*(ans[i][1]/3)) );
    }

    return 0;
}