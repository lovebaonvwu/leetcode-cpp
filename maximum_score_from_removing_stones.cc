class Solution {
 public:
  int maximumScore(int a, int b, int c) {
    int ans = 0;
    array<int, 3> arr = {a, b, c};
    int& x = arr[0];
    int& y = arr[1];
    int& z = arr[2];

    sort(arr.rbegin(), arr.rend());
    while (y > 0) {
      x -= 1;
      y -= 1;

      sort(arr.rbegin(), arr.rend());
      ++ans;
    }

    return ans;
  }
};
// Runtime: 170 ms, faster than 46.27%
// Memory Usage: 5.9 MB, less than 93.88%
// 2022.10.28 at 奥盛大厦