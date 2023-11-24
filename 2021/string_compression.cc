class Solution {
 public:
  int compress(vector<char>& chars) {
    chars.push_back(0);

    char prev = chars[0];

    int cnt = 1;
    int i = 0;

    for (int j = 1; j < chars.size(); ++j) {
      if (chars[j] == prev) {
        ++cnt;
      } else {
        chars[i++] = prev;
        prev = chars[j];

        if (cnt > 1) {
          i += sprintf(&chars[i], "%d", cnt);
          cnt = 1;
        }
      }
    }

    return i;
  }
};  // 8ms

class Solution {
 public:
  int compress(vector<char>& chars) {
    if (chars.size() < 2) {
      return chars.size();
    }

    char prev = chars[0];

    int cnt = 1;
    int i = 0;

    for (int j = 1; j < chars.size(); ++j) {
      if (chars[j] == prev) {
        ++cnt;
      } else {
        chars[i++] = prev;

        if (cnt > 1) {
          string s = to_string(cnt);

          for (char& c : s) {
            chars[i++] = c;
          }

          cnt = 1;
        }
        prev = chars[j];
      }
    }

    chars[i++] = prev;

    if (cnt > 1) {
      string s = to_string(cnt);

      for (char& c : s) {
        chars[i++] = c;
      }
    }

    return i;
  }
};  // 8ms