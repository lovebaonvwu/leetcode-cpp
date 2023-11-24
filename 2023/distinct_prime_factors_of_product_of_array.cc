class Solution {
 public:
  int distinctPrimeFactors(vector<int>& nums) {
    unordered_set<int> st;

    for (auto n : nums) {
      int divisor = 2;
      while (n > 1) {
        if (n % divisor == 0) {
          st.insert(divisor);
          n /= divisor;
        } else {
          ++divisor;
        }
      }
    }

    return st.size();
  }
};
// Runtime 198 ms
// Memory 18.9 MB
// 2023.1.6 at 奥盛大厦