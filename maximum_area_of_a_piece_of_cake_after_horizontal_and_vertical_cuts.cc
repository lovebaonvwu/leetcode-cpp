class Solution {
  long long max_gap(vector<int>& cuts, int size) {
    cuts.push_back(0);
    cuts.push_back(size);

    sort(cuts.begin(), cuts.end());

    int gap = 0;

    for (int i = 1; i < cuts.size(); ++i) {
      gap = max(gap, cuts[i] - cuts[i - 1]);
    }

    return gap;
  }

 public:
  int maxArea(int h,
              int w,
              vector<int>& horizontalCuts,
              vector<int>& verticalCuts) {
    long long ans = max_gap(horizontalCuts, h) * max_gap(verticalCuts, w);

    return ans % 1000000007;
  }
};
// Runtime: 68 ms, faster than 74.92%
// Memory Usage: 32.3 MB, less than 16.10%