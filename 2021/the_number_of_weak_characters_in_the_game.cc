class Solution {
 public:
  int numberOfWeakCharacters(vector<vector<int>>& properties) {
    sort(properties.begin(), properties.end(), [](auto& a, auto& b) {
      if (a[0] == b[0]) {
        return a[1] < b[1];
      } else {
        return a[0] < b[0];
      }
    });

    int ans = 0;

    int n = properties.size();

    for (int i = 0; i < n; ++i) {
      bool find = false;

      for (int j = n - 1; j > i; --j) {
        if (properties[j][0] > properties[i][0] &&
            properties[j][1] > properties[i][1]) {
          find = true;
          break;
        }
      }

      if (find) {
        ++ans;
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int numberOfWeakCharacters(vector<vector<int>>& properties) {
    sort(properties.begin(), properties.end(), [](auto& a, auto& b) {
      if (a[0] == b[0]) {
        return a[1] < b[1];
      } else {
        return a[0] > b[0];
      }
    });

    int ans = 0;
    int maxd = properties[0][1];

    int n = properties.size();

    for (int i = 1; i < n; ++i) {
      if (properties[i][1] < maxd) {
        ++ans;
      }

      maxd = max(maxd, properties[i][1]);
    }

    return ans;
  }
};
// Runtime: 584 ms, faster than 92.14%
// Memory Usage: 125.1 MB, less than 70.44%
// 2021.9.13 at 奥盛大厦