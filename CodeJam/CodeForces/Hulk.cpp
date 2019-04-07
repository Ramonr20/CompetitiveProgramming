#include <bits/stdc++.h>

using namespace std;

int main() {

    string  that = "that ", it = "it ", ans("");
    string love = "I love ", hate = "I hate ";
    bool flag = true;
    int n;
    int i = 0;

    cin >> n;

    while (i < n) {
        ans += flag ? hate : love;
        if (flag)
            flag = false;
        else   
            flag = true;
        if (i < n - 1)
            ans += that;
        i++;
    }
    ans += it;

    cout << ans << "\n";
    return 0;
}