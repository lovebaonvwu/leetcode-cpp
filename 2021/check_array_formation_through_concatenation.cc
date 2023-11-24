class Solution {
 public:
  bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    unordered_map<int, int> mp;

    for (int i = 0; i < pieces.size(); ++i) {
      mp[pieces[i][0]] = i;
    }

    for (int i = 0; i < arr.size();) {
      if (mp.find(arr[i]) == mp.end()) {
        return false;
      }

      auto piece = pieces[mp[arr[i]]];

      for (int j = 0; j < piece.size(); ++j, ++i) {
        if (arr[i] != piece[j]) {
          return false;
        }
      }
    }

    return true;
  }
};
// Runtime: 8 ms, faster than 100.00%
// Memory Usage: 10.4 MB, less than 100.00%