class Solution {
public:
    int minimumLength(string s) {
        int freq[26] = {0};
        for (auto c : s) {
            ++freq[c - 'a'];
        }

        int cnt = 0;
        for (int i = 0; i < 26; ++i) {

            if (freq[i] == 0) {
                continue;
            }

            if (freq[i] % 2 == 0) {
                cnt += (freq[i] - 2);
            } else {
                cnt += (freq[i] - 1);
            }
        }
        
        return s.size() - cnt;
    }
};
// 81 ms
// 30.64 MB