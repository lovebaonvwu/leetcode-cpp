class Solution {
 public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> presum(arr.size() + 1, 0);

    for (int i = 0; i < arr.size(); ++i) {
      presum[i + 1] = arr[i] ^ presum[i];
    }

    vector<int> ans;

    for (auto& q : queries) {
      ans.push_back(presum[q[1] + 1] ^ presum[q[0]]);
    }

    return ans;
  }
};
// Runtime: 116 ms, faster than 97.47%
// Memory Usage: 26.2 MB, less than 100.00%

class Solution {
 public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> presum(arr.size() + 1, 0);

    for (int i = 0; i < arr.size(); ++i) {
      presum[i + 1] = arr[i] ^ presum[i];
    }

    vector<int> ans;

    for (auto q : queries) {
      ans.push_back(presum[q[1] + 1] ^ presum[q[0]]);
    }

    return ans;
  }
};
// Runtime: 148 ms, faster than 28.54%
// Memory Usage: 29 MB, less than 100.00%