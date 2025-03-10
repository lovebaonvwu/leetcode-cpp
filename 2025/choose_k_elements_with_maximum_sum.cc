class Solution {
    public:
        vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
            int n = nums1.size();
    
            vector<pair<int, int>> n1;
            for (int i = 0; i < n; ++i) {
                n1.push_back({nums1[i], i});
            }
    
            sort(begin(n1), end(n1));
    
            priority_queue<int, vector<int>, greater<>> pq;
            vector<long long> ans(n);
    
            for (long long i = 0, j = 0, sum = 0; i < n; ++i) {
                while (j < i) {
                    int index = n1[j].second;
    
                    if (n1[j].first >= n1[i].first) {
                        break;
                    }
    
                    pq.push(nums2[index]);
                    sum += nums2[index];
    
                    if (pq.size() > k) {
                        sum -= pq.top();
                        pq.pop();
                    }
                    ++j;
                }
    
                ans[n1[i].second] = sum;
            }
    
            return ans;
        }
    };
    // 91 ms
    // 154.86 MB