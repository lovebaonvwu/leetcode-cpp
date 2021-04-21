class Solution {
 public:
  int countTriplets(vector<int>& arr) {
    int ans = 0;

    unordered_map<string, int> mp;
    for (int i = 0; i < arr.size(); ++i) {
      for (int j = i; j < arr.size(); ++j) {
        int x = 0;

        for (int k = i; k <= j; ++k) {
          x ^= arr[k];
        }

        mp[to_string(i) + '-' + to_string(j)] = x;
      }
    }

    for (int i = 0; i < arr.size(); ++i) {
      for (int j = i + 1; j < arr.size(); ++j) {
        for (int k = j; k < arr.size(); ++k) {
          int a = mp[to_string(i) + '-' + to_string(j - 1)];
          int b = mp[to_string(j) + '-' + to_string(k)];

          ans += a == b;
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int countTriplets(vector<int>& arr) {
    vector<int> prexor(arr.size());

    prexor[0] = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
      prexor[i] = prexor[i - 1] ^ arr[i];
    }

    int ans = 0;
    for (int i = 0; i < arr.size(); ++i) {
      for (int j = i + 1; j < arr.size(); ++j) {
        if (i == 0) {
          if (prexor[j] == 0) {
            ans += j;
          }
        } else {
          if (prexor[j] == prexor[i - 1]) {
            ans += j - i;
          }
        }
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.5 MB, less than 45.48%