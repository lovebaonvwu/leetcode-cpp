class Solution {
 public:
  int numFriendRequests(vector<int>& ages) {
    int ans = 0;

    for (int i = 0; i < ages.size(); ++i) {
      for (int j = 0; j < ages.size(); ++j) {
        if (i == j) {
          continue;
        }

        if (ages[j] > ages[i]) {
          continue;
        }

        if (ages[j] <= ages[i] * 0.5 + 7) {
          continue;
        }

        if (ages[j] > 100 && ages[i] < 100) {
          continue;
        }

        ++ans;
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int numFriendRequests(vector<int>& ages) {
    sort(ages.rbegin(), ages.rend());

    int ans = 0;

    for (int i = 0; i < ages.size(); ++i) {
      for (int j = i + 1; j < ages.size(); ++j) {
        if (ages[j] > ages[i]) {
          continue;
        }

        if (ages[j] <= ages[i] * 0.5 + 7) {
          continue;
        }

        if (ages[j] > 100 && ages[i] < 100) {
          continue;
        }

        if (ages[i] == ages[j]) {
          ++ans;
        }

        ++ans;
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
  bool request(int a, int b) {
    return !((b <= 0.5 * a + 7) || b > a || (b > 100 && a < 100));
  }

 public:
  int numFriendRequests(vector<int>& ages) {
    unordered_map<int, int> mp;

    for (auto n : ages) {
      ++mp[n];
    }

    int ans = 0;

    for (auto& a : mp) {
      for (auto& b : mp) {
        if (request(a.first, b.first)) {
          ans += a.second * (b.second - (a.first == b.first));
        }
      }
    }

    return ans;
  }
};
// Runtime: 76 ms, faster than 56.03%
// Memory Usage: 37.6 MB, less than 20.71%
// 2022.3.11 at 奥盛大厦