class StringIterator {
  vector<pair<char, int>> chs;
  int cur = 0;

 public:
  StringIterator(string compressedString) {
    compressedString.append(1, '*');
    int n = compressedString.size();

    char ch;
    for (int i = 0, cnt = 0; i < n; ++i) {
      if (!isdigit(compressedString[i])) {
        if (cnt > 0) {
          chs.push_back({ch, cnt});
        }

        ch = compressedString[i];
        cnt = 0;
      } else {
        cnt = cnt * 10 + (compressedString[i] - '0');
      }
    }
  }

  char next() {
    if (!hasNext()) {
      return ' ';
    }

    char ret = chs[cur].first;
    --chs[cur].second;

    if (chs[cur].second == 0) {
      ++cur;
    }

    return ret;
  }

  bool hasNext() { return cur < chs.size(); }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// Runtime 15 ms
// Memory 14.2 MB
// 2023.2.2 at 聊城月季西路长江路