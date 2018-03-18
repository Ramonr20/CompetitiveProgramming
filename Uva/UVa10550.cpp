#include <bits/stdc++.h>

using namespace std;

#define front(z,y) z > y ? y : y - 40
#define back(z,y) z < y ? y : y + 40

int main() {

    int p1, p2, p3;
    int init=1, n1=1, n2=1, n3=1, degrees;
    vector<int> ans;
    

    while (init || n1 || n2 || n3) {
        cin >> init >> n1 >> n2 >> n3;
        if (!(init || n1 || n2 || n3))
            break;

        p1 = 80, p2 = 40, p3 = 0;
        int v1 = front(init,n1);
        for (int i = init; i > v1; --i)
            p1 += 1;

        int v2 = back(n1,n2);
        for (int i = n1; i < v2 ; ++i)
            p2 += 1;

        int v3 = front(n2, n3);
        for (int i = n2; i > v3; --i)
            p3 += 1;

        degrees = ((p1 + p2 + p3) * 360) / 40;

        ans.push_back(degrees);
    }   

    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << "\n";

    return 0;
}