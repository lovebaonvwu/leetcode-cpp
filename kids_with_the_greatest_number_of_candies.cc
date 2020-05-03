class Solution {
 public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> ans(candies.size());

    int greatest = *max_element(candies.begin(), candies.end());

    for (int i = 0; i < candies.size(); ++i) {
      ans[i] = (candies[i] + extraCandies) < greatest ? false : true;
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 100.00%
// Memory Usage: 9.2 MB, less than 100.00%