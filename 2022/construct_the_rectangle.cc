class Solution {
 public:
  vector<int> constructRectangle(int area) {
    for (int l = sqrt(area); l > 0; --l) {
      if (area % l == 0) {
        return {area / l, l};
      }
    }

    return {};
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 99.84%
// 2022.1.21 at 奥盛大厦