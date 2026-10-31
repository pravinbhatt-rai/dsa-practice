
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();

        int zeros = count(s.begin(), s.end(), '0');

        if (zeros == 0) return 0;

        // Store undiscovered states according to parity.
        set<int> st[2];

        for (int i = 0; i <= n; i++) {
            st[i % 2].insert(i);
        }

        queue<int> q;
        vector<int> dist(n + 1, -1);

        q.push(zeros);
        dist[zeros] = 0;

        // Starting state is already discovered.
        st[zeros % 2].erase(zeros);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            // Minimum and maximum zeros we can select.
            int xMin = max(0, k - (n - cur));
            int xMax = min(k, cur);

            // Reachable range of zero counts.
            int L = cur + k - 2 * xMax;
            int R = cur + k - 2 * xMin;

            // All reachable states have this parity.
            int parity = (cur + k) % 2;

            auto it = st[parity].lower_bound(L);

            while (it != st[parity].end() && *it <= R) {
                int nxt = *it;

                if (nxt == 0) {
                    return dist[cur] + 1;
                }

                dist[nxt] = dist[cur] + 1;
                q.push(nxt);

                // Remove discovered state.
                it = st[parity].erase(it);
            }
        }

        return -1;
    }
};
