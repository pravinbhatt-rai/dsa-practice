
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefmax(n + 1, 0);
        vector<int> sufmin(n + 1, INT_MAX);
        vector<int> drop(n, 0);

        for (int i = 0; i < n; i++) {
            prefmax[i + 1] = max(prefmax[i], nums[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            sufmin[i] = min(sufmin[i + 1], nums[i]);
        }

        for (int i = 1; i < n; i++) {
            drop[i] = drop[i - 1] + (nums[i - 1] > nums[i]);
        }

        auto check = [&](int k) -> bool {
            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;

                int drops = drop[end] - drop[start];

                if (nums[end] > nums[start]) {
                    drops++;
                }

                if (drops > 1) {
                    return false;
                }

                if (prefmax[start] > sufmin[start]) {
                    return false;
                }
            }

            return true;
        };

        int ans = 0;

        for (int i = 1; i <= n / i; i++) {
            if (n % i == 0) {
                if (check(i)) {
                    ans += i;
                }

                int other = n / i;

                if (other != i && check(other)) {
                    ans += other;
                }
            }
        }

        return ans;
    }
};
