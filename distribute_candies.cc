class Solution {
 public:
  int distributeCandies(vector<int>& candies) {
    unordered_set<int> st(candies.begin(), candies.end());

    return st.size() >= candies.size() / 2 ? candies.size() / 2 : st.size();
  }
};
// Runtime: 604 ms, faster than 54.47%
// Memory Usage: 110.6 MB, less than 73.31%

class Solution {
 public:
  int distributeCandies(vector<int>& candies) {
    unordered_set<int> st(candies.begin(), candies.end());

    return min(st.size(), candies.size() / 2);
  }
};
// Runtime: 488 ms, faster than 92.83%
// Memory Usage: 110.4 MB, less than 74.96%