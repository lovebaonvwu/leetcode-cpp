class Solution {
 public:
  string getHint(string secret, string guess) {
    unordered_map<char, int> mp;
    int bulls = 0;
    int cows = 0;

    for (int i = 0; i < secret.size(); ++i) {
      if (!mp[secret[i]]) {
        mp[secret[i]] = 1;
      } else {
        mp[secret[i]]++;
      }
    }

    for (int i = 0; i < guess.size(); ++i) {
      if (guess[i] == secret[i]) {
        ++bulls;
        mp[guess[i]]--;

        guess[i] = 'x';
      }
    }

    for (int i = 0; i < guess.size(); ++i) {
      if (mp[guess[i]]) {
        ++cows;
        mp[guess[i]]--;
      }
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
  }
};