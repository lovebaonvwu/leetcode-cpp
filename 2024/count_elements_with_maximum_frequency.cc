class Solution {
 public:
  int maxFrequencyElements(vector<int>& nums) {
    int cnt[101]{0};
    for (auto n : nums) {
      ++cnt[n];
    }

    int max_cnt = *max_element(begin(cnt), end(cnt));

    int p = count_if(begin(cnt), end(cnt), [&](int n) { return n == max_cnt; });

    return p * max_cnt;
  }
};
// 0ms
// 19.18MB