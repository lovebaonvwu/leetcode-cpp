class Solution {
    public:
        vector<string> removeInvalidParentheses(string s) {
            int left = 0;
            int right = 0;
            for (auto c : s) {
                if (c == '(') {
                    ++left;
                } else if (c == ')') {
                    if (left > 0) {
                        --left;
                    } else {
                        ++right;
                    }
                }
            }
    
            int n = s.size();
            unordered_set<string> ans;
            function<void(int, int, int, int, int, string)> dfs =[&](int i, int leftCnt, int rightCnt, int leftRem, int rightRem, string expression) -> void {
                if (i == n) {
                    if (leftRem == 0 && rightRem == 0) {
                        ans.insert(expression);
                    }
                    return;
                }
    
                if (s[i] == '(' && leftRem > 0) {
                    dfs(i + 1, leftCnt, rightCnt, leftRem - 1, rightRem, expression);
                } else if (s[i] == ')' && rightRem > 0) {
                    dfs(i + 1, leftCnt, rightCnt, leftRem, rightRem - 1, expression);
                }
    
                if (s[i] != '(' && s[i] != ')') {
                    dfs(i + 1, leftCnt, rightCnt, leftRem, rightRem, expression + s[i]);
                } else if (s[i] == '(') {
                    dfs(i + 1, leftCnt + 1, rightCnt, leftRem, rightRem, expression + s[i]);
                } else if (rightCnt < leftCnt) {
                    dfs(i + 1, leftCnt, rightCnt + 1, leftRem, rightRem, expression + s[i]);
                }
            };
    
            dfs(0, 0, 0, left, right, "");
    
            return vector<string>(begin(ans), end(ans));
        }
    };
    // 1263 ms
    // 100.04 MB
