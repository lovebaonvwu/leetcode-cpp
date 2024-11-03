class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string cur = "";
        for (int i = 0; i < target.size(); ++i) {
            if (cur.size() < i + 1) {
                cur += "a";
                ans.push_back(cur);
            }

            while (cur.back() < target[i]) {
                cur.back() = (cur.back() - 'a' + 1 + 'a');
                ans.push_back(cur);
            }
        }

        return ans;
    }
};
// 25 ms
// 94.70 MB

