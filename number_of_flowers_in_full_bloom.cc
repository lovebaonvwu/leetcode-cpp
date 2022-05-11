class Solution {
 public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers,
                               vector<int>& persons) {
    map<int, int> mp{{0, 0}};

    for (auto& f : flowers) {
      ++mp[f[0]];
      --mp[f[1] + 1];
    }

    for (auto it = next(begin(mp)); it != mp.end(); ++it) {
      it->second += prev(it)->second;
    }

    transform(begin(persons), end(persons), begin(persons),
              [&](int p) { return prev(mp.upper_bound(p))->second; });

    return persons;
  }
};
// Runtime: 369 ms, faster than 78.63%
// Memory Usage: 85.9 MB, less than 66.95%
// 2022.5.11 at 奥盛大厦

class Solution {
 public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers,
                               vector<int>& persons) {
    vector<int> start, end;

    for (auto& f : flowers) {
      start.push_back(f[0]);
      end.push_back(f[1]);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    for (auto& p : persons) {
      int st = upper_bound(start.begin(), start.end(), p) - start.begin();
      int ed = lower_bound(end.begin(), end.end(), p) - end.begin();

      p = st - ed;
    }

    return persons;
  }
};
// Runtime: 486 ms, faster than 43.86%
// Memory Usage: 80.9 MB, less than 91.19%
// 2022.5.11 at 奥盛大厦