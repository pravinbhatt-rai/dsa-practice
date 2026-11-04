
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        multiset<int> left, right;

        long long leftSum = 0;
        long long rightSum = 0;

        vector<long long> cost;

        // Insert an element
        auto add = [&](int val) {

            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                leftSum += val;
            }
            else {
                right.insert(val);
                rightSum += val;
            }
        };

        // Remove an element
        auto remove = [&](int val) {

            auto it = left.find(val);

            if (it != left.end()) {
                left.erase(it);
                leftSum -= val;
            }
            else {
                it = right.find(val);
                right.erase(it);
                rightSum -= val;
            }
        };

        // Balance both multisets
        auto balance = [&]() {

            while (left.size() < right.size()) {

                int val = *right.begin();

                right.erase(right.begin());
                rightSum -= val;

                left.insert(val);
                leftSum += val;
            }

            while (left.size() > right.size() + 1) {

                int val = *left.rbegin();

                auto it = prev(left.end());

                left.erase(it);
                leftSum -= val;

                right.insert(val);
                rightSum += val;
            }
        };

        // Step 1: Sliding window + median cost
        for (int i = 0; i < n; i++) {

            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            balance();

            if (i >= x - 1) {

                long long median = *left.rbegin();

                long long currCost =
                    median * left.size() - leftSum +
                    rightSum - median * right.size();

                cost.push_back(currCost);
            }
        }

        // Step 2: Dynamic Programming
        int m = cost.size();

        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dp(
            k + 1,
            vector<long long>(m + 1, INF)
        );

        // Base case
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        // DP transitions
        for (int j = 1; j <= k; j++) {

            for (int i = 1; i <= m; i++) {

                // Option 1: Skip current window
                dp[j][i] = dp[j][i - 1];

                // Option 2: Select current window
                int prev = max(0, i - x);

                if (dp[j - 1][prev] != INF) {

                    dp[j][i] = min(
                        dp[j][i],
                        dp[j - 1][prev] + cost[i - 1]
                    );
                }
            }
        }

        return dp[k][m];
    }
};
