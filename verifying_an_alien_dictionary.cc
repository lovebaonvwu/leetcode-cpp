class Solution {
 private:
  map<char, int> mp;

 public:
  bool isAlienSorted(vector<string>& words, string order) {
    if (words.size() < 2) {
      return true;
    }

    for (int i = 0; i < order.size(); ++i) {
      mp[order[i]] = i;
    }

    for (int i = 1; i < words.size(); ++i) {
      if (stringCompare(words[i - 1], words[i]) > 0) {
        return false;
      }
    }

    return true;
  }

  int stringCompare(string& a, string& b) {
    int size = min(a.size(), b.size());

    for (int i = 0; i < size; ++i) {
      if (mp[a[i]] > mp[b[i]]) {
        return 1;
      } else if (mp[a[i]] < mp[b[i]]) {
        return -1;
      }
    }

    return a.size() < b.size() ? -1 : 1;
  }
};  // 8ms

class Solution {
 private:
  int arr[26];

 public:
  bool isAlienSorted(vector<string>& words, string order) {
    if (words.size() < 2) {
      return true;
    }

    for (int i = 0; i < order.size(); ++i) {
      arr[order[i] - 'a'] = i;
    }

    for (int i = 1; i < words.size(); ++i) {
      if (stringCompare(words[i - 1], words[i]) > 0) {
        return false;
      }
    }

    return true;
  }

  int stringCompare(string& a, string& b) {
    int size = min(a.size(), b.size());

    for (int i = 0; i < size; ++i) {
      if (arr[a[i] - 'a'] > arr[b[i] - 'a']) {
        return 1;
      } else if (arr[a[i] - 'a'] < arr[b[i] - 'a']) {
        return -1;
      }
    }

    return a.size() < b.size() ? -1 : 1;
  }
};  // 8ms