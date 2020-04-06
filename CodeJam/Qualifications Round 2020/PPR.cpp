#include <iostream>
#include <vector>
#include <algorithm> 
#include <tuple>

#define FOR(t,i,init,end) for (t i = init; i < end; ++i)

using namespace std;

typedef pair<int,int> pi;
typedef tuple<int,int,int,char> tiiis;

void print_tasks(vector<tiiis> &v, int nc) {
    cout << "Case #" << nc << ": ";
    FOR(int,i,0,v.size()) {
        cout << get<3>(v[i]);
    }
    cout << '\n';
};

int main() {

    int T, N, s, e, nc = 1;
    vector<tiiis> tasks;

    cin >> T;

    while (T--) {
        cin >> N;

        FOR(int,i,0,N) {
            cin >> s >> e;
            tasks.push_back({s,e,i,' '});
        }

        sort(begin(tasks), end(tasks), 
            [](tiiis const &t1, tiiis const &t2){
                return get<0>(t1) < get<0>(t2);
        });

        bool desition = 1;
        int ct = 1;
        tiiis J = make_tuple(get<0>(tasks[0]),get<1>(tasks[0]),get<2>(tasks[0]),'J'), C (-1,-1,-1,' ');
        tasks[0] = J;

        while (desition && (ct < tasks.size())) {
            if ((get<1>(J) - get<0>(tasks[ct])) <= 0) {
                J = tasks[ct];
                tasks[ct] = make_tuple(get<0>(J),get<1>(J),get<2>(J), 'J');
            }else if ((get<1>(C) - get<0>(tasks[ct])) <= 0) {
                C = tasks[ct];
                tasks[ct] = make_tuple(get<0>(C),get<1>(C),get<2>(C), 'C');
            } else {
                desition = false;
            }
            ++ct;
        }

        if (!desition) {
            cout << "Case #" << nc << ": " << "IMPOSSIBLE\n"; 
            nc++;
            tasks.clear();
            continue;
        }
        
        sort(begin(tasks), end(tasks), 
            [](tiiis const &t1, tiiis const &t2){
                return get<2>(t1) < get<2>(t2);
        });

        print_tasks(tasks, nc);
        tasks.clear();
        nc++;
    }

    return 0;
}