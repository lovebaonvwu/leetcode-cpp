class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<vector<string>> g;
    int cur_len = 0;
    int words_len = 0;
    vector<string> line;
    vector<string> ans;
    for (int i = 0; i < words.size();) {
      if (cur_len + words[i].size() <= maxWidth) {
        cur_len += words[i].size() + 1;
        words_len += words[i].size();
        line.push_back(words[i]);
        ++i;
      } else {
        if (line.size() > 1) {
          string s;
          int space_cnt = (maxWidth - words_len) / (line.size() - 1);
          int left_space = (maxWidth - words_len) % (line.size() - 1);
          for (int k = 0; k < line.size() - 1; ++k) {
            line[k].append(space_cnt, ' ');
            if (left_space > 0) {
              line[k].append(1, ' ');
              --left_space;
            }

            s += line[k];
          }
          s += line.back();
          ans.push_back(s);
        } else if (line.size() == 1) {
          string s;
          s += line.back();
          s.append(maxWidth - words_len, ' ');
          ans.push_back(s);
        }

        cur_len = 0;
        words_len = 0;
        line.clear();
      }
    }

    if (!line.empty()) {
      string s;
      for (auto& w : line) {
        s += w;
        if (s.size() < maxWidth) {
          s += ' ';
        }
      }

      s.append(maxWidth - s.size(), ' ');
      ans.push_back(s);
    }

    return ans;
  }
};
// 0 ms
// 7.6 MB