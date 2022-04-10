class Solution {
 public:
  string minimizeResult(string expression) {
    auto plus = expression.find('+');

    string op1 = expression.substr(0, plus);
    string op2 = expression.substr(plus + 1);

    int result = INT_MAX;
    string ans;
    for (int i = 0; i < op1.size(); ++i) {
      int a = i == 0 ? 1 : stoi(op1.substr(0, i));
      int b = i == op1.size() ? 0 : stoi(op1.substr(i));

      for (int j = 1; j <= op2.size(); ++j) {
        int c = j == 0 ? 0 : stoi(op2.substr(0, j));
        int d = j == op2.size() ? 1 : stoi(op2.substr(j));

        int value = a * (b + c) * d;
        if (value < result) {
          result = value;
          ans.clear();

          if (i > 0) {
            ans += to_string(a);
          }
          ans += '(' + to_string(b) + '+' + to_string(c) + ')';
          if (j < op2.size()) {
            ans += to_string(d);
          }
        }
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 100.00%
// 2022.4.10 at 茗筑美嘉