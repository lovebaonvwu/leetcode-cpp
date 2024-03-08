class Trie {
 public:
  Trie() { memset(next, 0, sizeof(next)); }

  ~Trie() {
    for (auto n : next) {
      delete n;
    }
  }

  void insert(const vector<int>& num) {
    Trie* cur = this;

    for (auto n : num) {
      if (!cur->next[n]) {
        cur->next[n] = new Trie;
      }

      cur = cur->next[n];
    }
  }

  int search(const vector<int>& tar) {
    Trie* cur = this;

    int i = 0;
    for (; cur && i < tar.size(); ++i) {
      if (!cur->next[tar[i]]) {
        break;
      }

      cur = cur->next[tar[i]];
    }

    return i;
  }

 private:
  Trie* next[10];
};

class Solution {
 public:
  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    Trie root;

    for (auto a : arr1) {
      vector<int> tmp;
      while (a > 0) {
        tmp.push_back(a % 10);
        a /= 10;
      }

      reverse(tmp.begin(), tmp.end());

      root.insert(tmp);
    }

    int ans = 0;
    for (auto a : arr2) {
      vector<int> tmp;
      while (a > 0) {
        tmp.push_back(a % 10);
        a /= 10;
      }

      reverse(tmp.begin(), tmp.end());

      ans = max(ans, root.search(tmp));
    }

    return ans;
  }
};
// 691 ms
// 318.14 MB