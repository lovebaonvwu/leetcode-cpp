class Solution {
 public:
  vector<int> distributeCandies(int candies, int num_people) {
    vector<int> ans(num_people);

    for (int i = 0, round = 0; candies > 0;) {
      int distribute = round * num_people + i + 1;

      if (candies >= distribute) {
        candies -= distribute;
        ans[i] += distribute;
      } else {
        ans[i] += candies;
        candies = 0;
      }

      if (++i >= num_people) {
        i = 0;
        ++round;
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.5 MB, less than 28.26%

class Solution {
 public:
  vector<int> distributeCandies(int candies, int num_people) {
    vector<int> ans(num_people);

    for (int i = 0; candies > 0; candies -= ++i) {
      ans[i % num_people] += min(i + 1, candies);
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 95.77%