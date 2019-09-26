class Solution {
 public:
  vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    int min = INT_MAX;

    for (int i = 1; i < arr.size(); ++i) {
      if (arr[i] - arr[i - 1] < min) {
        min = arr[i] - arr[i - 1];
      }
    }

    vector<vector<int>> ans;

    for (int i = 1; i < arr.size(); ++i) {
      if (arr[i] - arr[i - 1] == min) {
        ans.push_back(vector<int>{arr[i - 1], arr[i]});
      }
    }

    return ans;
  }
};
// Runtime: 120 ms, faster than 56.08%
// Memory Usage: 17 MB, less than 100.00%