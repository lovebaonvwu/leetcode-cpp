class Solution {
 public:
  bool strongPasswordCheckerII(string password) {
    if (password.size() < 8) {
      return false;
    }

    bool lower = false;
    bool upper = false;
    bool digit = false;
    bool specl = false;

    unordered_set<char> spe(begin("!@#$%^&*()-+"), end("!@#$%^&*()-+"));

    for (int i = 0; i < password.size(); ++i) {
      if (islower(password[i])) {
        lower = true;
      } else if (isupper(password[i])) {
        upper = true;
      } else if (isdigit(password[i])) {
        digit = true;
      } else if (spe.count(password[i])) {
        specl = true;
      }

      if (i > 0 && password[i] == password[i - 1]) {
        return false;
      }
    }

    return lower && upper && digit && specl;
  }
};
// Runtime: 7 ms, faster than 20.00%
// Memory Usage: 6.4 MB, less than 20.00%
// 2022.6.12 at 名筑美嘉

class Solution {
 public:
  bool strongPasswordCheckerII(string password) {
    if (password.size() < 8) {
      return false;
    }

    bool lower = false;
    bool upper = false;
    bool digit = false;
    bool specl = false;

    for (int i = 0; i < password.size(); ++i) {
      if (islower(password[i])) {
        lower = true;
      } else if (isupper(password[i])) {
        upper = true;
      } else if (isdigit(password[i])) {
        digit = true;
      } else {
        specl = true;
      }

      if (i > 0 && password[i] == password[i - 1]) {
        return false;
      }
    }

    return lower && upper && digit && specl;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 100.00%
// 2022.6.12 at 名筑美嘉