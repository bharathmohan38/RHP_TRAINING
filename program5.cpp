#include <iostream>
#include <vector>
using namespace std;

vector<long long> getFSMAX(vector<vector<long long>> &dp, int R, int col) {
    long long fmax = max(dp[0][col], dp[1][col]);
    long long smax = min(dp[0][col], dp[1][col]);

    for (int row = 2; row < R; row++) {
        if (dp[row][col] > fmax) {
            smax = fmax;
            fmax = dp[row][col];
        } else if (dp[row][col] > smax) {
            smax = dp[row][col];
        }
    }

    return {fmax, smax};
}

int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<int>> grid(R, vector<int>(C));
    vector<vector<long long>> dp(R, vector<long long>(C));

    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            cin >> grid[row][col];
            if (col == 0) {
                dp[row][col] = grid[row][col];
            }
        }
    }

    for (int col = 1; col < C; col++) {
        vector<long long> fsmax = getFSMAX(dp, R, col - 1);

        for (int row = 0; row < R; row++) {
            dp[row][col] = grid[row][col] +
                           (dp[row][col - 1] == fsmax[0] ? fsmax[1] : fsmax[0]);
        }
    }

    cout << getFSMAX(dp, R, C - 1)[0];

    return 0;
}