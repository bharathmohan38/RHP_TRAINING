#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<pair<int,int>> choco(N), box(M);
    for (int i = 0; i < N; i++) cin >> choco[i].first;  
    for (int i = 0; i < N; i++) cin >> choco[i].second;  
    for (int i = 0; i < M; i++) cin >> box[i].first;     
    for (int i = 0; i < M; i++) cin >> box[i].second;    
    sort(choco.begin(), choco.end(), greater<pair<int,int>>());
    sort(box.begin(), box.end(), greater<pair<int,int>>());
    multiset<int> s;
    int j = 0;
    for (auto [a, b] : choco) {
        while (j < M && box[j].first >= a) {
            s.insert(box[j].second);
            j++;
        }
        auto it = s.lower_bound(b);
        if (it == s.end()) {
            cout << "No\n";
            return 0;
        }
        s.erase(it);
    }
    cout << "Yes\n";
    return 0;
}
