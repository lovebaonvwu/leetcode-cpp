class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s;
        int ans = 0;
        for (;s.size() < b.size(); ++ans) {
            s += a;
        }
        if (s.find(b) != string::npos) {
            return ans;
        }

        s += a;
        if (s.find(b) != string::npos) {
            return ans + 1;
        }

        return -1;
    }
};
// 3 ms
// 9.82 MB
