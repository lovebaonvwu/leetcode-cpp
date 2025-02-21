class Solution {
    public:
        vector<string> maxNumOfSubstrings(string s) {
            vector<vector<int>> pos(26);
            int n = s.size();
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
    
                if (cur == end) {
                    intervals.push_back({start, end});
                }
            }
    
            sort(begin(intervals), end(intervals), [](auto& a, auto& b) {
                return a.second - a.first < b.second - b.first;
            });
    
            n = intervals.size();
            vector<bool> selected(n, true);
    
            for (int i = 0; i < n; ++i) {
                if (!selected[i]) {
                    continue;
                }
    
                for (int j = i + 1; j < n; ++j) {
                    if (!selected[j]) {
                        continue;
                    }
    
                    if (intervals[i].first > intervals[j].first && intervals[i].second < intervals[j].second) {
                        selected[j] = false;
                    }
                }
            }
    
            vector<string> ans;
            for (int i = 0; i < n; ++i) {
                if (selected[i]) {
                    ans.push_back(s.substr(intervals[i].first, intervals[i].second - intervals[i].first + 1));
                }
            }
    
            return ans;
        }
};
// 22 ms
// 42.12 MB