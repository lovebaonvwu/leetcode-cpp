class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    map<int, int> mp;

    for (auto w : people) {
      ++mp[w];
    }

    mp[0] = 1;

    int ans = 0;
    for (auto w : people) {
      if (mp.find(w) != mp.end() && mp[w] > 0) {
        ++ans;
        --mp[w];

        for (auto it = mp.upper_bound(limit - w); it != mp.begin(); --it) {
          if (it->first <= (limit - w) && it->second > 0) {
            --mp[it->first];
            break;
          }
        }
      }
    }

    return ans;
  }
};
// Runtime: 340 ms, faster than 13.32%
// Memory Usage: 48.3 MB, less than 5.08%

class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.rbegin(), people.rend());

    int ans = 0;
    for (int i = 0, j = people.size() - 1; i <= j; ++i) {
      if (people[i] + people[j] <= limit) {
        --j;
      }
      ++ans;
    }

    return ans;
  }
};
// Runtime: 104 ms, faster than 100.00%
// Memory Usage: 41.9 MB, less than 100.00%