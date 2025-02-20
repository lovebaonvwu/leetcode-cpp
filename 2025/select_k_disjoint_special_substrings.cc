class Solution {
    public:
        bool maxSubstringLength(string s, int k) {
            int n = s.size();
            vector<vector<int>> pos(26);
    
            for (int i = 0; i < n; ++i) {
                pos[s[i] - 'a'].push_back(i);
            }
    
            vector<pair<int, int>> intervals;
            for (int ch = 0; ch < 26; ++ch) {
                if (pos[ch].empty()) {
                    continue;
                }
    
                int start = pos[ch][0];
                int end = pos[ch].back();
                int cur = start;
    
                while (cur < end) {
                    if (pos[s[cur] - 'a'][0] < start) {
                        break;
                    }
                    end = max(end, pos[s[cur] - 'a'].back());
                    ++cur;
                }
    
                if (end - start + 1 == n) {
                    continue;
                }
                if (cur == end) {
                    intervals.push_back({start, end});
                }
            }
    
            sort(begin(intervals), end(intervals), [](auto& a, auto& b) {
                return a.second < b.second;
            });
            int count = 0;
            int prev = -1;
            for (auto& interval : intervals) {
                if (interval.first > prev) {
                    ++count;
                    prev = interval.second;
                }
            }
    
            return count >= k;
        }
};
// 14 ms
// 26.00 MB
