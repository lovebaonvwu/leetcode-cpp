class Solution {
 public:
  string kthDistinct(vector<string>& arr, int k) {
    unordered_map<string, int> mp;

    for (int i = 0; i < arr.size(); ++i) {
      if (mp.find(arr[i]) != mp.end()) {
        arr[mp[arr[i]]] = "";
        arr[i] = "";
      }

      mp[arr[i]] = i;
    }

    for (auto& a : arr) {
      if (a != "") {
        --k;

        if (k == 0) {
          return a;
        }
      }
    }

    return "";
  }
};
// Runtime: 12 ms, faster than 98.67%
// Memory Usage: 14.5 MB, less than 88.30%
// 2021.11.8 at 奥盛大厦

class Solution {
 public:
  string kthDistinct(vector<string>& arr, int k) {
    unordered_map<string, int> mp;

    for (auto& a : arr) {
      ++mp[a];
    }

    for (auto& a : arr) {
      if (mp[a] == 1 && --k == 0) {
        return a;
      }
    }

    return "";
  }
};
// Runtime: 20 ms, faster than 77.30%
// Memory Usage: 14.6 MB, less than 52.47%
// 2021.11.8 at 奥盛大厦