class Solution {
 public:
  string shortestCompletingWord(string licensePlate, vector<string>& words) {
    vector<int> cnt(26);

    for (auto ch : licensePlate) {
      if (isalpha(ch)) {
        ++cnt[tolower(ch) - 'a'];
      }
    }

    stable_sort(words.begin(), words.end(),
                [](auto a, auto b) { return a.size() < b.size(); });

    string ans;
    for (auto& w : words) {
      vector<int> t = cnt;

      for (auto ch : w) {
        if (t[tolower(ch) - 'a'] > 0) {
          --t[tolower(ch) - 'a'];
        }
      }

      if (all_of(t.begin(), t.end(), [](int n) { return n == 0; })) {
        ans = w;
        break;
      }
    }

    return ans;
  }
};
// Runtime: 76 ms, faster than 23.32%
// Memory Usage: 14.4 MB, less than 40.00%

class Solution {
 public:
  string shortestCompletingWord(string licensePlate, vector<string>& words) {
    vector<int> cnt(26);

    for (auto ch : licensePlate) {
      if (isalpha(ch)) {
        ++cnt[tolower(ch) - 'a'];
      }
    }

    pair<string, int> ans = {"", INT_MAX};

    for (auto& w : words) {
      vector<int> t = cnt;

      for (auto ch : w) {
        if (t[tolower(ch) - 'a'] > 0) {
          --t[tolower(ch) - 'a'];
        }
      }

      if (all_of(t.begin(), t.end(), [](int n) { return n == 0; }) &&
          w.size() < ans.second) {
        ans = {w, w.size()};
      }
    }

    return ans.first;
  }
};
// Runtime: 36 ms, faster than 48.56%
// Memory Usage: 16 MB, less than 20.00%