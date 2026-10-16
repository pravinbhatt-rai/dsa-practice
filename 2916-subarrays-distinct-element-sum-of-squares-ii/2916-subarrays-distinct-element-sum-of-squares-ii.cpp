class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<long long> sum, sqSum, lazy;
    int n;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        // Update sum of squares before updating sum
        sqSum[node] = (
            sqSum[node] + 2 * val * sum[node] % MOD
            + val * val % MOD * len % MOD
        ) % MOD;

        sum[node] = (sum[node] + val * len) % MOD;
        lazy[node] = (lazy[node] + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (lazy[node] == 0 || l == r) return;

        int mid = l + (r - l) / 2;

        apply(node * 2, l, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, r, lazy[node]);

        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;

        sqSum[node] = (
            sqSum[node * 2] + sqSum[node * 2 + 1]
        ) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();

        sum.assign(4 * n, 0);
        sqSum.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int x = nums[r];

            // Only these starting positions gain a new distinct value
            update(1, 0, n - 1, last[x] + 1, r);

            // Sum of squares for every subarray ending at r
            ans = (ans + sqSum[1]) % MOD;

            last[x] = r;
        }

        return ans;
    }
};