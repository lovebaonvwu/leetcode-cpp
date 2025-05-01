class Solution {
    public:
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            int n = tasks.size();
            int m = workers.size();
    
            sort(begin(tasks), end(tasks));
    
            int lo = 0;
            int hi = n;
    
            function<bool(int)> ok = [&](int target) -> bool {
                if (target > m) {
                    return false;
                }
    
                int k = pills;
    
                multiset<int> st(workers.begin(), workers.end());
    
                for (int i = target - 1; i >= 0; --i) {
                    if (*st.rbegin() >= tasks[i]) {
                        st.erase(prev(st.end()));
                    } else {
                        if (k == 0) {
                            return false;
                        }
    
                        auto it = st.lower_bound(tasks[i] - strength);
                        if (it == st.end()) {
                            return false;
                        }
    
                        st.erase(it);
                        --k;
                    }
                }
    
                return true;
            };
    
            while (lo < hi) {
                int md = (lo + hi + 1) / 2;
    
                if (ok(md)) {
                    lo = md;
                } else {
                    hi = md - 1;
                }
            }
    
            return lo;
        }
    };
    // Time: O(log n * log m)
    // Space: O(m)