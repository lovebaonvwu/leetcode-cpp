class Solution {
    public:
        vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
            unordered_map<int, set<int>> mp;
            int n = nums.size();
            for (int i = 0; i < n; ++i) {
                mp[nums[i]].insert(i);
                mp[nums[i]].insert(i + n);
                mp[nums[i]].insert(i - n);
            }
    
            vector<int> ans;
            for (auto q : queries) {
                int target = nums[q];
                int dist = 2 * n;
                if (mp.find(target) == mp.end() || mp[target].size() == 3) {
                    ans.push_back(-1);
                } else {
                    auto cur = mp[target].find(q);
                    
                    auto right = upper_bound(begin(mp[target]), end(mp[target]), q);
                    dist = min(dist, *right - *cur);
    
                    auto left = lower_bound(begin(mp[target]), end(mp[target]), *prev(cur));
                    dist = min(dist, *cur - *left);
    
                    ans.push_back(dist);
                }
            }
    
            return ans;
        }
    };
    // Time Limit Exceeded

    class Solution {
        public:
            vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
                int n = nums.size();
                unordered_map<int, int> lastSeen;
                vector<int> dist(n, n);
                for (int i = 0; i < 2 * n; ++i) {
                    int num = nums[i % n];
                    if (lastSeen.find(num) != lastSeen.end()) {
                        dist[i % n] = i - lastSeen[num];
                    }
                    lastSeen[num] = i;
                }
        
                lastSeen.clear();
                for (int i = 2 * n - 1; i >= 0; --i) {
                    int num = nums[i % n];
                    if (lastSeen.find(num) != lastSeen.end()) {
                        dist[i % n] = min(dist[i % n], lastSeen[num] - i);
                    }
                    lastSeen[num] = i;
                }
        
                vector<int> ans;
                for (auto q : queries) {
                    if (dist[q] == n) {
                        ans.push_back(-1);
                    } else {
                        ans.push_back(dist[q]);
                    }
                }
        
                return ans;
            }
        };
        // Time: O(n)
        // Space: O(n)