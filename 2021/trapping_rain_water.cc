class Solution {
 public:
  int trap(vector<int>& height) {
    if (height.size() == 0) {
      return 0;
    }

    int n = height.size();

    vector<int> left(n, 0);
    vector<int> right(n, 0);

    int highest = height[0];
    for (int i = 1; i < n; ++i) {
      left[i] = highest;

      if (height[i] > highest) {
        highest = height[i];
      }
    }

    highest = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      right[i] = highest;

      if (height[i] > highest) {
        highest = height[i];
      }
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
      int lvl = min(left[i], right[i]);
      ans += height[i] < lvl ? lvl - height[i] : 0;
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 95.96%
// Memory Usage: 9.2 MB, less than 51.90%

class Solution {
 public:
  int trap(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;

    int left_highest = 0;
    int right_highest = 0;

    int ans = 0;

    while (left < right) {
      if (height[left] < height[right]) {
        if (height[left] < left_highest) {
          ans += left_highest - height[left];
        } else {
          left_highest = height[left];
        }

        ++left;
      } else {
        if (height[right] < right_highest) {
          ans += right_highest - height[right];
        } else {
          right_highest = height[right];
        }

        --right;
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 59.78%
// Memory Usage: 9.1 MB, less than 87.34%