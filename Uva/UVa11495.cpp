#include <bits/stdc++.h>

#define MAXN 100000

using namespace std;
int N, n1;
vector<int> nums(MAXN);
vector<int> eq(MAXN);

void copy() {
    for (int i = 0; i < n1; ++i)
        eq[i] = nums[i];
}

bool equ() {
    for (int i = 0; i < n1; ++i)
        if (eq[i] != nums[i])
            return false;
    return true;
}

int main() {
    int i, aux;
    bool flag;
    string ans("");

    while (scanf("%d", &N), N) {
        i = 0;
        n1 = N;
        flag = true;
        while (N--) {
            cin >> nums[i];
            i++;
        }

        copy();
        sort(eq.begin(),eq.end());
        for (i = 0; i < n1*n1; ++i) {
            for (int j = 0; j < n1 - 1; ++j) {
                if (nums[j] > nums[j + 1]) {
                    aux = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = aux;
                
                    if (flag) {
                        ans = "Marcelo";
                        flag = false;
                    }else {
                        ans = "Carlos";
                        flag = true;
                    }
                    break;
                }
            }
            if (equ())
                break;
        }
        cout << ans << "\n";
    }


    return 0;
}