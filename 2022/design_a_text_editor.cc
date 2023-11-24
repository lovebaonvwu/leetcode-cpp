class TextEditor {
  int cur = 0;
  string s = "";

 public:
  TextEditor() {}

  void addText(string text) {
    string p1 = s.substr(0, cur);
    string p2 = s.substr(cur);

    s = p1 + text + p2;
    cur += text.size();
  }

  int deleteText(int k) {
    int res = min(k, cur);
    string p1 = s.substr(0, cur - res);
    string p2 = s.substr(cur);

    s = p1 + p2;
    cur -= res;

    return res;
  }

  string cursorLeft(int k) {
    cur = max(0, cur - k);
    int start = max(cur - 10, 0);
    string res = s.substr(start, cur - start);

    return res;
  }

  string cursorRight(int k) {
    cur = min((int)s.size(), cur + k);
    int start = max(cur - 10, 0);
    string res = s.substr(start, cur - start);

    return res;
  }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
// Memory Limit Exceeded

class TextEditor {
  string head, tail;

 public:
  TextEditor() {}

  void addText(string text) { head += text; }

  int deleteText(int k) {
    int len = min((int)head.size(), k);
    head = head.substr(0, head.size() - len);

    return len;
  }

  string cursorLeft(int k) {
    while (k-- > 0 && !head.empty()) {
      tail.push_back(head.back());
      head.pop_back();
    }

    return head.substr(max(0, (int)head.size() - 10));
  }

  string cursorRight(int k) {
    while (k-- > 0 && !tail.empty()) {
      head.push_back(tail.back());
      tail.pop_back();
    }

    return head.substr(max(0, (int)head.size() - 10));
  }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
// Runtime: 687 ms, faster than 61.93%
// Memory Usage: 398.7 MB, less than 5.37%