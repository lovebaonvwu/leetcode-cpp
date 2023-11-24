class Solution {
 public:
  vector<int> threeEqualParts(vector<int>& arr) {
    int cnt = 0;

    for (auto n : arr) {
      if (n == 1) {
        ++cnt;
      }
    }

    if (cnt % 3 != 0) {
      return {-1, -1};
    }

    if (cnt == 0) {
      return {0, 2};
    }

    cnt /= 3;

    int j = arr.size();

    while (cnt > 0) {
      --j;

      if (arr[j] == 1) {
        --cnt;
      }
    }

    int k = j, i = 0;

    while (arr[i] == 0) {
      ++i;
    }

    while (k < arr.size() && arr[i] == arr[k]) {
      ++i;
      ++k;
    }

    if (k < arr.size()) {
      return {-1, -1};
    }

    vector<int> ans;
    ans.push_back(i - 1);

    while (arr[i] == 0) {
      ++i;
    }

    k = j;
    while (k < arr.size() && arr[i] == arr[k]) {
      ++i;
      ++k;
    }

    if (k < arr.size()) {
      return {-1, -1};
    }

    ans.push_back(i);

    return ans;
  }
};
// Runtime: 40 ms, faster than 63.25%
// Memory Usage: 38.9 MB, less than 81.33%
// 2021.7.17 at 茗筑美嘉