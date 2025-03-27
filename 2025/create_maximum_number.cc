class Solution {
    public:
        vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
            int m = nums1.size();
            int n = nums2.size();
    
            vector<int> ans;
    
            function<void(int, int, int, vector<int>&)> dfs = [&](int i, int j, int k, vector<int>& v) -> void {
                if (k == 0) {
                    ans = max(ans, v);
                    return;
                }
    
                if (i < m) {
                    v.push_back(nums1[i]);
                    dfs(i + 1, j, k - 1, v);
                    v.pop_back();
    
                    dfs(i + 1, j, k, v);
                }
    
                if (j < n) {
                    v.push_back(nums2[j]);
                    dfs(i, j + 1, k - 1, v);
                    v.pop_back();
    
                    dfs(i, j + 1, k, v);
                }
            };
    
            vector<int> v;
            dfs(0, 0, k, v);
    
            return ans;
        }
    };
    // Time: O(2^(m + n)) where m and n are the sizes of nums1 and nums2 respectively.
    // Space: O(m + n)

    class Solution {
        public:
            vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
                vector<int> ans;
                int n1 = nums1.size();
                int n2 = nums2.size();
        
                for (int i = 0; i <= k; ++i) {
                    int j = k - i;
                    if (i > n1 || j > n2) {
                        continue;
                    }
        
                    ans = max(ans, merge(maxNumber(nums1, i), maxNumber(nums2, j)));
                }
        
                return ans;
            }
        
            vector<int> maxNumber(const vector<int>& nums, int k) {
                vector<int> ret;
                int drop = nums.size() - k;
                for (auto n : nums) {
                    while (!ret.empty() && n > ret.back() && drop-- > 0) {
                        ret.pop_back();
                    }
        
                    ret.push_back(n);
                }
                ret.resize(k);
        
                return ret;
            }
        
            vector<int> merge(const vector<int>& nums1, const vector<int>& nums2) {
                vector<int> ret;
        
                auto s1 = nums1.cbegin();
                auto e1 = nums1.cend();
                auto s2 = nums2.cbegin();
                auto e2 = nums2.cend();
        
                while (s1 != e1 || s2 != e2) {
                    ret.push_back(lexicographical_compare(s1, e1, s2, e2) ? *s2++ : *s1++);
                }
        
                return ret;
            }
        };

        // Time: O(km)
        // Space: O(k)