class Solution {
 public:
  int largestUniqueNumber(vector<int>& nums) {
    map<int, int> mp;
    for (auto n : nums) {
      ++mp[n];
    }

    int ans = -1;
    for (auto& [n, cnt] : mp) {
      if (cnt == 1) {
        ans = n;
      }
    }

    return ans;
  }
};
// Runtime 15 ms
// Memory 9.1 MB
// 2022.11.30 at 茗筑美嘉

class Solution {
 public:
  int largestUniqueNumber(vector<int>& nums) {
    short cnt[1001] = {};
    for (auto n : nums) {
      ++cnt[n];
    }

    int i = 1000;
    for (; i >= 0 && cnt[i] != 1; --i)
      ;

    return i;
  }
};
// Runtime 6 ms
// Memory 8.3 MB
// 2022.11.30 at 茗筑美嘉