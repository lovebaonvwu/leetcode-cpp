class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        string ans = "";
        // vector<vector<bool>> cached(n, vector<bool>(numFriends + 1, false));
        function<void(int, int, vector<string>&)> dfs = [&](int idx, int f, vector<string>& st) -> void {
            if (idx == n && f == 0) {
                for (auto s : st) {
                    ans = max(ans, s);
                }

                return;
            }

            if (idx == n) {
                return;
            }

            if (f == 0) {
                return;
            }

            for (int i = idx; i < n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    st.push_back(word.substr(idx, j));
                    dfs(idx + j, f - 1, st);
                    st.pop_back();
                }
            }
        };

        vector<string> s;
        dfs(0, numFriends, s);
        return ans;
    }
};
// Time Limit Exceeded

class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();

        if (numFriends == 1) {
            return word;
        }

        int m = n - numFriends + 1;

        string ans;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, word.substr(i, m));
        }

        return ans;
    }
};
// 79 ms
// 169.28 MB