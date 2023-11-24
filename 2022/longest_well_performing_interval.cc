class Solution {
 public:
  int longestWPI(vector<int>& hours) {
    int ans = 0;
    int n = hours.size();
    for (int i = 0; i < n; ++i) {
      int a = 0, b = 0;
      for (int j = i; j < n; ++j) {
        if (hours[j] > 8) {
          ++a;
        } else {
          ++b;
        }

        if (a > b) {
          ans = max(ans, j - i + 1);
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int longestWPI(vector<int>& hours) {
    int ans = 0;
    int n = hours.size();
    unordered_map<int, int> mp;
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
      cnt += hours[i] > 8 ? 1 : -1;
      if (cnt > 0) {
        ans = max(ans, i + 1);
      } else {
        if (mp.find(cnt) == mp.end()) {
          mp[cnt] = i;
        }

        if (mp.find(cnt - 1) != mp.end()) {
          ans = max(ans, i - mp[cnt - 1]);
        }
      }
    }

    return ans;
  }
};
// Runtime 57 ms
// Memory 23.1 MB
// 2022.11.8 at 奥盛大厦