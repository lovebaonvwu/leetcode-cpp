class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        int total = 0;
        long long ans = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; ++i) {
            if (nums1[i] == nums2[i]) {
                ++total;
                ans += i;
                ++mp[nums1[i]];
            }
        }

        int maxCnt = 0;
        int maxNum = 0;

        for (auto [num, cnt] : mp) {
            if (cnt > maxCnt) {
                maxCnt = cnt;
                maxNum = num;
            }
        }

        if (maxCnt <= total - maxCnt) {
            return ans;
        }

        int extra = maxCnt - (total - maxCnt);

        for (int i = 0; i < n && extra > 0; ++i) {
            if (nums1[i] == nums2[i]) {
                continue;
            }

            if (nums1[i] == maxNum || nums2[i] == maxNum) {
                continue;
            }

            --extra;
            ans += i;
        }

        return extra == 0 ? ans : -1;
    }
};
// 25 ms
// 115.04 MB