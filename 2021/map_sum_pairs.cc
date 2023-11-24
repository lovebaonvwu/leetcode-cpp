class Trie {
  class TrieNode {
   public:
    TrieNode() : children{nullptr}, isWord(false) {}

    TrieNode* children[26];
    bool isWord;
    string word;
  };

 public:
  Trie() : root(new TrieNode) {}

  ~Trie() { delete root; }

  void insert(string w) {
    TrieNode* cur = this->root;

    for (auto c : w) {
      if (!cur->children[c - 'a']) {
        cur->children[c - 'a'] = new TrieNode;
      }

      cur = cur->children[c - 'a'];
    }

    cur->isWord = true;
    cur->word = w;
  }

  vector<string> find(string w) {
    vector<string> ret;

    TrieNode* cur = this->root;

    for (auto c : w) {
      if (!cur->children[c - 'a']) {
        return {};
      }

      cur = cur->children[c - 'a'];
    }

    dfs(cur, ret);

    return ret;
  }

  void dfs(TrieNode* root, vector<string>& ret) {
    if (!root) {
      return;
    }

    if (root->isWord) {
      ret.push_back(root->word);
    }

    for (int i = 0; i < 26; ++i) {
      if (root->children[i]) {
        dfs(root->children[i], ret);
      }
    }
  }

 private:
  TrieNode* root;
};

class MapSum {
  unordered_map<string, int> mp;
  Trie* trie;

 public:
  /** Initialize your data structure here. */
  MapSum() : trie(new Trie) {}

  void insert(string key, int val) {
    mp[key] = val;
    trie->insert(key);
  }

  int sum(string prefix) {
    vector<string> keys;

    keys = trie->find(prefix);

    int sum = 0;

    for (auto key : keys) {
      sum += mp[key];
    }

    return sum;
  }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// Runtime: 4 ms, faster than 68.72%
// Memory Usage: 8.4 MB, less than 8.42%
// 2021.7.30 at 奥盛大厦

class Trie {
  class TrieNode {
   public:
    TrieNode() : children{nullptr}, isWord(false) {}
    ~TrieNode() {
      for (int i = 0; i < 26; ++i) {
        delete children[i];
      }
    }

    TrieNode* children[26];
    bool isWord;
    string word;
  };

 public:
  Trie() : root(new TrieNode) {}

  ~Trie() { delete root; }

  void insert(string w) {
    TrieNode* cur = this->root;

    for (auto c : w) {
      if (!cur->children[c - 'a']) {
        cur->children[c - 'a'] = new TrieNode;
      }

      cur = cur->children[c - 'a'];
    }

    cur->isWord = true;
    cur->word = w;
  }

  vector<string> find(string w) {
    vector<string> ret;

    TrieNode* cur = this->root;

    for (auto c : w) {
      if (!cur->children[c - 'a']) {
        return {};
      }

      cur = cur->children[c - 'a'];
    }

    dfs(cur, ret);

    return ret;
  }

  void dfs(TrieNode* root, vector<string>& ret) {
    if (!root) {
      return;
    }

    if (root->isWord) {
      ret.push_back(root->word);
    }

    for (int i = 0; i < 26; ++i) {
      if (root->children[i]) {
        dfs(root->children[i], ret);
      }
    }
  }

 private:
  TrieNode* root;
};

class MapSum {
  unordered_map<string, int> mp;
  Trie* trie;

 public:
  /** Initialize your data structure here. */
  MapSum() : trie(new Trie) {}

  void insert(string key, int val) {
    mp[key] = val;
    trie->insert(key);
  }

  int sum(string prefix) {
    vector<string> keys;

    keys = trie->find(prefix);

    int sum = 0;

    for (auto key : keys) {
      sum += mp[key];
    }

    return sum;
  }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.3 MB, less than 21.93%
// 2021.7.30 at 奥盛大厦

class Trie {
  class TrieNode {
   public:
    TrieNode() : children{nullptr}, sum(0) {}
    ~TrieNode() {
      for (int i = 0; i < 26; ++i) {
        delete children[i];
      }
    }

    TrieNode* children[26];
    int sum;
  };

 public:
  Trie() : root(new TrieNode) {}

  ~Trie() { delete root; }

  void insert(string w, int val) {
    TrieNode* cur = this->root;

    for (auto c : w) {
      if (!cur->children[c - 'a']) {
        cur->children[c - 'a'] = new TrieNode;
      }

      cur->sum += val;
      cur = cur->children[c - 'a'];
    }

    cur->sum += val;
  }

  int find(string w) {
    TrieNode* cur = this->root;

    for (auto c : w) {
      if (!cur->children[c - 'a']) {
        return {};
      }

      cur = cur->children[c - 'a'];
    }

    return cur->sum;
  }

 private:
  TrieNode* root;
};

class MapSum {
  unordered_map<string, int> mp;
  Trie* trie;

 public:
  /** Initialize your data structure here. */
  MapSum() : trie(new Trie) {}

  void insert(string key, int val) {
    trie->insert(key, val - mp[key]);

    mp[key] = val;
  }

  int sum(string prefix) { return trie->find(prefix); }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// Runtime: 4 ms, faster than 68.72%
// Memory Usage: 8.3 MB, less than 12.30%
// 2021.7.30 at 奥盛大厦