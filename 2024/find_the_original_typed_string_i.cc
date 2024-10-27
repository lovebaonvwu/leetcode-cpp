class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;

        for (int i = 1; i < word.size(); ++i) {
            if (word[i] == word[i - 1]) {
                ++ans;
            }
        }

        return ans;
    }
};
// 0 ms
// 8.37 MB