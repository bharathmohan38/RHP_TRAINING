#include <iostream>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    long long pre[200005] = {0};

    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        pre[i] = pre[i - 1] + x;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << endl;
    }

    return 0;
}
