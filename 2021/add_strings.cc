class Solution {
 public:
  string addStrings(string num1, string num2) {
    string ans = "";
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
      int n1 = i >= 0 ? num1[i--] - '0' : 0;
      int n2 = j >= 0 ? num2[j--] - '0' : 0;

      int sum = n1 + n2 + carry;
      ans = (char)(sum % 10 + '0') + ans;
      carry = sum / 10;
    }

    return ans;
  }
};  // 16ms faster than 49.59%