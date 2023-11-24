class MagicDictionary {
  unordered_map<int, vector<string>> mp;

 public:
  /** Initialize your data structure here. */
  MagicDictionary() {}

  /** Build a dictionary through a list of words */
  void buildDict(vector<string> dict) {
    for (auto& s : dict) {
      mp[s.size()].push_back(s);
    }
  }

  /** Returns if there is any word in the trie that equals to the given word
   * after modifying exactly one character */
  bool search(string word) {
    if (mp.find(word.size()) == mp.end()) {
      return false;
    }

    auto& words = mp[word.size()];

    for (auto& w : words) {
      int cnt = 0;

      for (int i = 0; i < w.size(); ++i) {
        if (w[i] != word[i]) {
          ++cnt;
        }

        if (cnt > 1) {
          break;
        }
      }

      if (cnt == 1) {
        return true;
      }
    }

    return false;
  }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
// Runtime: 28 ms, faster than 96.63%
// Memory Usage: 18.4 MB, less than 88.00%

class MagicDictionary {
  unordered_set<string> st;

 public:
  /** Initialize your data structure here. */
  MagicDictionary() {}

  /** Build a dictionary through a list of words */
  void buildDict(vector<string> dict) {
    st = unordered_set<string>(dict.begin(), dict.end());
  }

  /** Returns if there is any word in the trie that equals to the given word
   * after modifying exactly one character */
  bool search(string word) {
    for (int i = 0; i < word.size(); ++i) {
      char t = word[i];

      for (int j = 'a'; j <= 'z'; ++j) {
        if (t != j) {
          word[i] = j;

          if (st.count(word)) {
            return true;
          }
        }
      }

      word[i] = t;
    }

    return false;
  }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
// Runtime: 228 ms, faster than 36.84%
// Memory Usage: 18.1 MB, less than 93.05%