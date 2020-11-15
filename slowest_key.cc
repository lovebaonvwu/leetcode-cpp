class Solution {
 public:
  char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    int keys[26] = {0};

    int maxDuration = 0;

    for (int i = 0; i < keysPressed.size(); ++i) {
      if (i == 0) {
        keys[keysPressed[i] - 'a'] = releaseTimes[i];
      } else {
        keys[keysPressed[i] - 'a'] = max(keys[keysPressed[i] - 'a'],
                                         releaseTimes[i] - releaseTimes[i - 1]);
      }

      maxDuration = max(maxDuration, keys[keysPressed[i] - 'a']);
    }

    char ans = 'a';
    for (int i = 0; i < 26; ++i) {
      if (keys[i] == maxDuration) {
        ans = i + 'a';
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 98.68%
// Memory Usage: 10.9 MB, less than 96.18%

class Solution {
 public:
  char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    char ans = keysPressed[0];
    int time = releaseTimes[0];

    for (int i = 1; i < keysPressed.size(); ++i) {
      if (releaseTimes[i] - releaseTimes[i - 1] > time) {
        time = releaseTimes[i] - releaseTimes[i - 1];
        ans = keysPressed[i];
      } else if (releaseTimes[i] - releaseTimes[i - 1] == time) {
        ans = max(ans, keysPressed[i]);
      }
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 88.87%
// Memory Usage: 11 MB, less than 45.71%