class Solution {
 public:
  string alphabetBoardPath(string target) {
    unordered_map<char, pair<int, int>> mp{
        {'a', {0, 0}}, {'b', {0, 1}}, {'c', {0, 2}}, {'d', {0, 3}},
        {'e', {0, 4}}, {'f', {1, 0}}, {'g', {1, 1}}, {'h', {1, 2}},
        {'i', {1, 3}}, {'j', {1, 4}}, {'k', {2, 0}}, {'l', {2, 1}},
        {'m', {2, 2}}, {'n', {2, 3}}, {'o', {2, 4}}, {'p', {3, 0}},
        {'q', {3, 1}}, {'r', {3, 2}}, {'s', {3, 3}}, {'t', {3, 4}},
        {'u', {4, 0}}, {'v', {4, 1}}, {'w', {4, 2}}, {'x', {4, 3}},
        {'y', {4, 4}}, {'z', {5, 0}}};

    int i = 0;
    int j = 0;

    string ans;

    for (const char& t : target) {
      auto p = mp[t];

      bool oneMoreMove = false;

      if (i < p.first) {
        if (t == 'z' && j > 0) {
          oneMoreMove = true;
          ans.append(p.first - i - 1, 'D');
        } else {
          ans.append(p.first - i, 'D');
        }
      } else if (i > p.first) {
        ans.append(i - p.first, 'U');
      }

      i = p.first;

      if (j < p.second) {
        ans.append(p.second - j, 'R');
      } else if (j > p.second) {
        ans.append(j - p.second, 'L');
      }

      j = p.second;

      if (oneMoreMove) {
        ans.append("D");
      }

      ans.append("!");
    }

    return ans;
  }
};  // 0ms

class Solution {
 public:
  string alphabetBoardPath(string target) {
    unordered_map<char, pair<int, int>> mp;

    for (int i = 0; i < 26; ++i) {
      mp[i + 'a'] = {i / 5, i % 5};
    }

    string ans;
    int i = 0;
    int j = 0;

    for (const char& t : target) {
      auto p = mp[t];

      if (i - p.first > 0)
        ans.append(i - p.first, 'U');
      if (j - p.second > 0)
        ans.append(j - p.second, 'L');
      if (i - p.first < 0)
        ans.append(p.first - i, 'D');
      if (j - p.second < 0)
        ans.append(p.second - j, 'R');

      i = p.first;
      j = p.second;

      ans.append("!");
    }

    return ans;
  }
};  // 4ms