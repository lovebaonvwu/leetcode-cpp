class Solution {
public:
    int minLength(string s) {
        string ans;
        for (auto c : s) {
            if (c == 'B' && !ans.empty() && ans.back() == 'A') {
                ans.pop_back();
            } else if (c == 'D' && !ans.empty() && ans.back() == 'C') {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }

        return ans.size();
    }
};
// 3 ms
// 10.47 MB