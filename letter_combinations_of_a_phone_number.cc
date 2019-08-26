class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return {};
    }

    string mp[10] = {"",    "",    "abc",  "def", "ghi",
                     "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> ans;

    queue<string> q;
    q.push("");

    for (int i = 0; i < digits.size(); ++i) {
      string arr = mp[digits[i] - '0'];

      int cnt = q.size();
      while (cnt > 0) {
        for (int j = 0; j < arr.size(); ++j) {
          string tmp = q.front();
          tmp += arr[j];

          q.push(tmp);
        }

        q.pop();

        --cnt;
      }
    }

    while (!q.empty()) {
      ans.push_back(q.front());
      q.pop();
    }

    return ans;
  }
};  // 4ms

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