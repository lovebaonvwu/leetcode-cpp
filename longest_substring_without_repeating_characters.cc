class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0;
    int head = 0;
    int arr[256];

    memset(arr, -1, sizeof arr);

    for (int i = 0; i < s.size(); ++i) {
      if (arr[s[i]] >= head) {
        ans = max(i - head, ans);
        head = arr[s[i]] + 1;
      }
      arr[s[i]] = i;
    }

    return max((int)s.size() - head, ans);
  }
};  // 4ms

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0;
    string sub = "";

    for (auto& c : s) {
      if (sub[sub.size() - 1] == c) {
        sub = "";
      } else {
        int pos = sub.find(c);
        sub = sub.substr(pos + 1);
      }

      sub += c;

      ans = max(ans, (int)sub.size());
    }

    return ans;
  }
};  // 28ms