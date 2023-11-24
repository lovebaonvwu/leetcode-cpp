class Solution {
 public:
  vector<int> arraysIntersection(vector<int>& arr1,
                                 vector<int>& arr2,
                                 vector<int>& arr3) {
    map<int, int> cnt;
    for (auto a : arr1) {
      ++cnt[a];
    }

    for (auto a : arr2) {
      ++cnt[a];
    }

    for (auto a : arr3) {
      ++cnt[a];
    }

    vector<int> ans;
    for (auto& [a, n] : cnt) {
      if (n == 3) {
        ans.push_back(a);
      }
    }

    return ans;
  }
};
// Runtime 32 ms
// Memory 14.3 MB
// 2023.1.23 at 茗筑美嘉

class Solution {
 public:
  vector<int> arraysIntersection(vector<int>& arr1,
                                 vector<int>& arr2,
                                 vector<int>& arr3) {
    auto a = arr1.begin();
    auto b = arr2.begin();
    auto c = arr3.begin();

    vector<int> ans;
    while (a != arr1.end() && b != arr2.end() && c != arr3.end()) {
      if (*a == *b && *b == *c) {
        ans.push_back(*a);
        ++a, ++b, ++c;
      } else if (*a < *b) {
        ++a;
      } else if (*b < *c) {
        ++b;
      } else {
        ++c;
      }
    }

    return ans;
  }
};
// Runtime 12 ms
// Memory 11.8 MB
// 2023.1.23 at 茗筑美嘉