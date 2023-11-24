class Solution {
 public:
  vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
    for (auto& comp : favoriteCompanies) {
      sort(comp.begin(), comp.end());
    }

    vector<int> ans;
    size_t n = favoriteCompanies.size();
    for (int i = 0; i < n; ++i) {
      bool isSub = false;

      for (int j = 0; j < n && !isSub; ++j) {
        if (i == j) {
          continue;
        }

        isSub =
            includes(begin(favoriteCompanies[j]), end(favoriteCompanies[j]),
                     begin(favoriteCompanies[i]), end(favoriteCompanies[i]));
      }

      if (!isSub) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// Runtime: 1408 ms, faster than 13.83%
// Memory Usage: 44 MB, less than 100.00%

class Solution {
 public:
  vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
    unordered_map<string, int> mp;
    int id = 0;
    for (auto& comp : favoriteCompanies) {
      for (auto& c : comp) {
        if (!mp.count(c)) {
          mp[c] = id++;
        }
      }
    }

    vector<bitset<50000>> v;
    for (auto& comp : favoriteCompanies) {
      bitset<50000> b;
      for (auto& c : comp) {
        b[mp[c]] = 1;
      }

      v.push_back(b);
    }

    vector<int> ans;
    for (int i = 0; i < v.size(); ++i) {
      bool notSub = true;
      for (int j = 0; j < v.size() && notSub; ++j) {
        if (i == j) {
          continue;
        }

        if ((v[i] & v[j]) == v[i]) {
          notSub = false;
        }
      }

      if (notSub) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// Runtime: 520 ms, faster than 80.38%
// Memory Usage: 79.5 MB, less than 100.00%