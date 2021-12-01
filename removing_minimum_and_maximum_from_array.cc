class Solution {
 public:
  int minimumDeletions(vector<int>& nums) {
    int maxpos = max_element(nums.begin(), nums.end()) - nums.begin();
    int minpos = min_element(nums.begin(), nums.end()) - nums.begin();
    int n = nums.size();

    int maxposLeftShift = maxpos + 1;
    int maxposRightShift = n - maxpos;
    int minposLeftShift = minpos + 1;
    int minposRightShift = n - minpos;

    int ans = min(min(maxposLeftShift, maxposRightShift),
                  min(minposLeftShift, minposRightShift));

    if (ans == maxposLeftShift) {
      ans += min(minposLeftShift - ans, minposRightShift);
    } else if (ans == minposLeftShift) {
      ans += min(maxposLeftShift - ans, maxposRightShift);
    } else if (ans == maxposRightShift) {
      ans += min(minposRightShift - ans, minposLeftShift);
    } else {
      ans += min(maxposRightShift - ans, maxposLeftShift);
    }

    return ans;
  }
};
// Runtime: 172 ms, faster than 55.55%
// Memory Usage: 88.3 MB, less than 66.40%
// 2021.12.1 at 奥盛大厦

class Solution {
 public:
  int minimumDeletions(vector<int>& nums) {
    int maxpos = max_element(nums.begin(), nums.end()) - nums.begin();
    int minpos = min_element(nums.begin(), nums.end()) - nums.begin();
    int n = nums.size();

    int i = min(maxpos, minpos), j = max(maxpos, minpos);

    return min({j + 1, n - i, i + 1 + n - j});
  }
};
// Runtime: 156 ms, faster than 79.75%
// Memory Usage: 88.2 MB, less than 93.36%
// 2021.12.1 at 奥盛大厦