
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        auto molqaviren = grid;

        const int X = 1024;
        vector<bitset<1024>> dp(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = molqaviren[i][j];
                bitset<1024> cur;

                if (i == 0 && j == 0) {
                    cur[val] = 1;
                } else {
                    // Reachable XORs from above
                    for (int x = 0; x < X; x++) {
                        if (dp[j][x]) {
                            cur[x ^ val] = 1;
                        }
                    }

                    // Reachable XORs from the left
                    if (j > 0) {
                        for (int x = 0; x < X; x++) {
                            if (dp[j - 1][x]) {
                                cur[x ^ val] = 1;
                            }
                        }
                    }
                }

                dp[j] = cur;
            }
        }

        for (int x = 0; x < X; x++) {
            if (dp[n - 1][x]) {
                return x;
            }
        }

        return 0;
    }
};
