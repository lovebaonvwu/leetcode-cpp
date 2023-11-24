class Solution {
 public:
  int minOperations(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<int>& n1 = nums1;
    vector<int>& n2 = nums2;

    int cnt1 = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (n1[i] <= n1[n - 1] && n2[i] <= n2[n - 1]) {
        continue;
      } else if (min(n1[i], n2[i]) > n1[n - 1] ||
                 min(n1[i], n2[i]) > n2[n - 1]) {
        return -1;
      } else if (max(n1[i], n2[i]) > n1[n - 1] &&
                 max(n1[i], n2[i]) > n2[n - 1]) {
        return -1;
      } else {
        ++cnt1;
      }
    }

    swap(n1[n - 1], n2[n - 1]);
    int cnt2 = 1;
    for (int i = 0; i < n - 1; ++i) {
      if (n1[i] <= n1[n - 1] && n2[i] <= n2[n - 1]) {
        continue;
      } else if (min(n1[i], n2[i]) > n1[n - 1] ||
                 min(n1[i], n2[i]) > n2[n - 1]) {
        return -1;
      } else if (max(n1[i], n2[i]) > n1[n - 1] &&
                 max(n1[i], n2[i]) > n2[n - 1]) {
        return -1;
      } else {
        ++cnt2;
      }
    }

    return min(cnt1, cnt2);
  }
};
// 21ms
// 43.10MB