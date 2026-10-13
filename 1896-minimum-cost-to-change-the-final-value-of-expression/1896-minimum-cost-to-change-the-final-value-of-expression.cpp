
class Solution {
public:
    struct Node {
        int val;
        int dp0;
        int dp1;
    };

    Node Combine(Node a, Node b, char op) {
        Node res;

        res.val = (op == '&') ? (a.val & b.val) : (a.val | b.val);
        res.dp0 = INT_MAX;
        res.dp1 = INT_MAX;

        for (int x = 0; x <= 1; x++) {
            for (int y = 0; y <= 1; y++) {
                for (int flip = 0; flip <= 1; flip++) {
                    int leftCost = (x == 0) ? a.dp0 : a.dp1;
                    int rightCost = (y == 0) ? b.dp0 : b.dp1;

                    char newop = op;
                    if (flip == 1) {
                        newop = (op == '&') ? '|' : '&';
                    }

                    int result = (newop == '&') ? (x & y) : (x | y);
                    int cost = leftCost + rightCost + flip;

                    if (result == 0)
                        res.dp0 = min(res.dp0, cost);
                    else
                        res.dp1 = min(res.dp1, cost);
                }
            }
        }

        return res;
    }

    Node ParseAtom(string& s, int& i) {
        if (s[i] == '(') {
            i++;
            Node res = ParseExpr(s, i);
            i++; // Skip ')'
            return res;
        }

        int digit = s[i] - '0';
        i++;

        return {
            digit,
            digit == 0 ? 0 : 1,
            digit == 1 ? 0 : 1
        };
    }

    // & and | have equal precedence: evaluate left to right
    Node ParseExpr(string& s, int& i) {
        Node left = ParseAtom(s, i);

        while (i < (int)s.size() && (s[i] == '&' || s[i] == '|')) {
            char op = s[i++];
            Node right = ParseAtom(s, i);
            left = Combine(left, right, op);
        }

        return left;
    }

    int minOperationsToFlip(string expression) {
        int i = 0;
        Node ans = ParseExpr(expression, i);

        return (ans.val == 0) ? ans.dp1 : ans.dp0;
    }
};