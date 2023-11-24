class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int carry = 1;

    for (int i = digits.size() - 1; i >= 0; i--) {
      int sum = digits[i] + carry;
      if (sum > 9) {
        digits[i] = 0;
      } else {
        digits[i] = sum;
        carry = 0;
        break;
      }
    }

    if (carry == 1) {
      vector<int> ans(digits.size() + 1);
      ans[0] = 1;

      for (int i = 0; i < digits.size(); i++) {
        ans[i + 1] = digits[i];
      }

      return ans;
    }

    return digits;
  }
};