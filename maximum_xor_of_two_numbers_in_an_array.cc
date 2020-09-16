class Trie {
 public:
  Trie() { next[0] = next[1] = nullptr; }

  void insert(int n) {
    Trie* cur = this;

    for (int i = 31; i >= 0; --i) {
      if (n & (1 << i)) {
        if (!cur->next[1]) {
          cur->next[1] = new Trie();
        }
        cur = cur->next[1];
      } else {
        if (!cur->next[0]) {
          cur->next[0] = new Trie();
        }
        cur = cur->next[0];
      }
    }

    cur->val = n;
  }

  int findOpposite(int n) {
    Trie* cur = this;

    for (int i = 31; i >= 0; --i) {
      if (n & (1 << i)) {
        if (cur->next[0]) {
          cur = cur->next[0];
        } else {
          cur = cur->next[1];
        }
      } else {
        if (cur->next[1]) {
          cur = cur->next[1];
        } else {
          cur = cur->next[0];
        }
      }
    }

    return cur->val;
  }

 private:
  int val;
  Trie* next[2];
};

class Solution {
 public:
  int findMaximumXOR(vector<int>& nums) {
    int ans = 0;

    Trie root;

    for (auto n : nums) {
      root.insert(n);
    }

    for (auto n : nums) {
      ans = max(ans, n ^ root.findOpposite(n));
    }

    return ans;
  }
};
// Runtime: 68 ms, faster than 75.49%
// Memory Usage: 30.2 MB, less than 43.54%

class Trie {
 public:
  Trie() { next[0] = next[1] = nullptr; }

  ~Trie() {
    if (next[0]) {
      delete next[0];
    }

    if (next[1]) {
      delete next[1];
    }
  }

  void insert(int n) {
    Trie* cur = this;

    for (int i = 31; i >= 0; --i) {
      if (n & (1 << i)) {
        if (!cur->next[1]) {
          cur->next[1] = new Trie();
        }
        cur = cur->next[1];
      } else {
        if (!cur->next[0]) {
          cur->next[0] = new Trie();
        }
        cur = cur->next[0];
      }
    }

    cur->val = n;
  }

  int findOpposite(int n) {
    Trie* cur = this;

    for (int i = 31; i >= 0; --i) {
      if (n & (1 << i)) {
        if (cur->next[0]) {
          cur = cur->next[0];
        } else {
          cur = cur->next[1];
        }
      } else {
        if (cur->next[1]) {
          cur = cur->next[1];
        } else {
          cur = cur->next[0];
        }
      }
    }

    return cur->val;
  }

 private:
  int val;
  Trie* next[2];
};

class Solution {
 public:
  int findMaximumXOR(vector<int>& nums) {
    int ans = 0;

    Trie root;

    for (auto n : nums) {
      root.insert(n);
    }

    for (auto n : nums) {
      ans = max(ans, n ^ root.findOpposite(n));
    }

    return ans;
  }
};
// Runtime: 184 ms, faster than 32.21%
// Memory Usage: 130.1 MB, less than 5.04%