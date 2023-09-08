class Solution {
 public:
  int countSymmetricIntegers(int low, int high) {
    int ans = 0;
    for (int k = low; k <= high; ++k) {
      if (k >= 10 && k <= 99) {
        if (k % 10 == ((k / 10)) % 10) {
          ++ans;
        }
      } else if (k >= 1000 && k <= 9999) {
        int last = (k % 10) + (k / 10) % 10;
        int first = (k / 100) % 10 + (k / 1000) % 10;
        ans += first == last;
      }
    }

    return ans;
  }
};
// 12ms
// 5.90MB