#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 100010

using namespace std;

int pizzas_pieces [MAXN];
long long int M, pieces = 0;
int N;

vector<int> types;

void solve(int i) {
    if (i > (N-1)) return;

    int s = pizzas_pieces[(N-1)-i];

    if ((pieces + s) > M) {
        solve(i+1);
    } else if ((pieces + s) <= M) {
        types.push_back((N-1)-i);
        pieces += s;
        solve(i+1);
    }
}   

int main() {

    cin >> M >> N;

    for (int i = 0; i < N; ++i) {
        cin >> pizzas_pieces[i];
    }

    solve(0);
    reverse(types.begin(), types.end());

    cout << types.size() << '\n';    
    for (int i = 0; i < types.size(); ++i)
        cout << types[i] << ' ';
    cout << '\n';

    return 0;
}
