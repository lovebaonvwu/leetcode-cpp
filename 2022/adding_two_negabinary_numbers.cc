class Solution {
 public:
  vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
    int i = arr1.size() - 1, j = arr2.size() - 1, carry = 0;

    vector<int> ans;
    while (i >= 0 || j >= 0 || carry) {
      int sum = 0;
      sum += carry;
      sum += (i >= 0 ? arr1[i--] : 0);
      sum += (j >= 0 ? arr2[j--] : 0);

      ans.push_back(abs(sum) % 2);

      carry = sum < 0 ? 1 : sum > 1 ? -1 : 0;
    }

    while (ans.size() > 1 && ans.back() == 0) {
      ans.pop_back();
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 19.5 MB, less than 28.64%
// 2022.3.16 at 奥盛大厦