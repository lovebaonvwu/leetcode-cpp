class Solution {
 public:
  int numTimesAllBlue(vector<int>& light) {
    int n = light.size();

    vector<int> on(n);
    vector<int> blue(n);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      on[light[i] - 1] = 1;

      if (light[i] - 1 == 0 || blue[light[i] - 2]) {
        blue[light[i] - 1] = 1;
      }

      for (int j = light[i]; j < n && on[j]; ++j) {
        blue[j] = 1;
      }

      if (on == blue) {
        ++ans;
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int numTimesAllBlue(vector<int>& light) {
    int n = light.size();

    vector<int> on(n);
    vector<int> blue(n);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      on[light[i] - 1] = 1;

      if (light[i] - 1 == 0 || blue[light[i] - 2]) {
        blue[light[i] - 1] = 1;
      }

      if (blue[light[i] - 1]) {
        for (int j = light[i]; j < n && on[j]; ++j) {
          blue[j] = 1;
        }

        if (on == blue) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// Runtime: 420 ms, faster than 5.91%
// Memory Usage: 42.2 MB, less than 20.41%

class Solution {
 public:
  int numTimesAllBlue(vector<int>& light) {
    int right_most_on_light = -1;
    int ans = 0;

    for (int i = 0; i < light.size(); ++i) {
      right_most_on_light = max(right_most_on_light, light[i]);

      if (i + 1 == right_most_on_light) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 136 ms, faster than 94.31%
// Memory Usage: 38.4 MB, less than 81.63%