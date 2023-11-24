class CombinationIterator {
  vector<string> combinations;
  int i = 0;

 public:
  CombinationIterator(string characters, int combinationLength) {
    vector<string> c = {""};

    for (int i = 0; i < characters.size(); ++i) {
      for (int j = 0, cnt = c.size(); j < cnt; ++j) {
        c.push_back(c[j] + characters[i]);
      }
    }

    for (auto cc : c) {
      if (cc.size() == combinationLength) {
        combinations.push_back(cc);
      }
    }

    sort(combinations.begin(), combinations.end());
  }

  string next() { return combinations[i++]; }

  bool hasNext() {
    if (i < combinations.size()) {
      return true;
    }

    return false;
  }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters,
 * combinationLength); string param_1 = obj->next(); bool param_2 =
 * obj->hasNext();
 */
// Runtime: 48 ms, faster than 20.51%
// Memory Usage: 15.8 MB, less than 5.08%

class CombinationIterator {
  int cur;
  int len;

  string s;

 public:
  CombinationIterator(string characters, int combinationLength) {
    len = combinationLength;
    cur = (1 << characters.size()) - 1;

    s = characters;
  }

  int countOne(int n) {
    int cnt = 0;

    while (n != 0) {
      ++cnt;

      n &= n - 1;
    }

    return cnt;
  }

  string next() {
    while (cur >= 0 && countOne(cur) != len) {
      --cur;
    }

    string res = "";

    for (int i = 0; i < s.size(); ++i) {
      if (cur & (1 << i)) {
        res = s[s.size() - i - 1] + res;
      }
    }

    --cur;

    return res;
  }

  bool hasNext() {
    while (cur >= 0 && countOne(cur) != len) {
      --cur;
    }

    if (cur < 0) {
      return false;
    }

    return true;
  }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters,
 * combinationLength); string param_1 = obj->next(); bool param_2 =
 * obj->hasNext();
 */
// Runtime: 32 ms, faster than 52.43%
// Memory Usage: 12.3 MB, less than 82.03%