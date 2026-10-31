constexpr int mod = 1e9 + 7;
int row[500];

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();

        memset(row, 0, M * sizeof(int));
        row[0] = 1;

        for (const auto& r : grid) {
            for (int i = 0, prv = 0; i < M; ++i) {
                if (r[i]) {
                    swap(prv, row[i]);
                } 
                else {
                    row[i] = prv = (prv + row[i]) % mod;
                }
            }
        }

        return row[M - 1];
    }
};