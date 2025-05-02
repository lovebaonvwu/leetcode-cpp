class Solution {
    public:
        string findCommonResponse(vector<vector<string>>& responses) {
            unordered_map<string, int> cnt;
    
            for (auto& r : responses) {
                unordered_set<string> st(begin(r) ,end(r));
                for (auto s : st) {
                    ++cnt[s];
                }
            }
    
            vector<pair<int, string>> pq;
    
            for (auto& [s, c] : cnt) {
                pq.push_back({c, s});
            }
    
            sort(begin(pq), end(pq), [](auto& a, auto& b) {
                if (a.first == b.first) {
                    return a.second < b.second;
                } else {
                    return a.first > b.first;
                }
            });
    
            return pq[0].second;
        }
    };
    // Time: O(n * m)
    // Space: O(n * m)
    // n: number of responses
    // m: number of strings in each response