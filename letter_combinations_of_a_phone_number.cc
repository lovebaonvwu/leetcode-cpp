class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return {};
    }

    string mp[10] = {"",    "",    "abc",  "def", "ghi",
                     "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> ans;
    ans.push_back("");

    for (int i = 0; i < digits.size(); ++i) {
      string arr = mp[digits[i] - '0'];

      vector<string> tmp;
      for (int j = 0; j < arr.size(); ++j) {
        for (int k = 0; k < ans.size(); ++k) {
          tmp.push_back(ans[k] + arr[j]);
        }
      }

      ans = tmp;
    }

    return ans;
  }
};  // 4ms