class Solution {
 public:
  string similarRGB(string color) {
    string ans = "#";

    char ch[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                 '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    for (int i = 1; i < 7; i += 2) {
      int ori = 0;
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 16; ++k) {
          if (ch[k] == color[i + j]) {
            ori = ori * 16 + k;
            break;
          }
        }
      }

      int j = 0, minval = INT_MAX;

      for (int k = 0; k < 16; ++k) {
        int cur = k * 16 + k;
        if (abs(cur - ori) < minval) {
          minval = abs(cur - ori);
          j = k;
        }
      }

      ans.append(2, ch[j]);
    }

    return ans;
  }
};
// Runtime 0 ms
// Memory 5.9 MB
// 2023.2.2 at 聊城滦河路汉庭优佳