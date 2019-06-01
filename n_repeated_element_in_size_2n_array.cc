class Solution {
 public:
  int repeatedNTimes(vector<int>& A) {
    unordered_map<int, int> mp;

    for (int& a : A) {
      if (mp[a]) {
        return a;
      } else {
        mp[a] = 1;
      }
    }

    return -1;
  }
};  // 40ms

class Solution {
 public:
  int repeatedNTimes(vector<int>& A) {
    unordered_map<int, int> mp;

    for (int& a : A) {
      if (!mp[a]) {
        mp[a] = 1;
      } else {
        mp[a]++;
      }

      if (mp[a] == A.size() / 2) {
        return a;
      }
    }

    return -1;
  }
};  // 76ms