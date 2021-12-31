class Solution {
  unordered_set<string> have;
  unordered_map<string, int> mp;
  unordered_map<string, bool> canMake;
  vector<string> ans;

 public:
  vector<string> findAllRecipes(vector<string>& recipes,
                                vector<vector<string>>& ingredients,
                                vector<string>& supplies) {
    for (auto& s : supplies) {
      have.insert(s);
    }

    for (int i = 0; i < recipes.size(); ++i) {
      mp[recipes[i]] = i;
    }

    for (auto& recipe : recipes) {
      if (dfs(recipe, ingredients)) {
        ans.push_back(recipe);
      }
    }

    return ans;
  }

  bool dfs(string& ingredient, vector<vector<string>>& ingredients) {
    if (have.find(ingredient) != have.end()) {
      return true;
    }

    if (mp.find(ingredient) == mp.end()) {
      return false;
    }

    if (canMake.count(ingredient) > 0) {
      return canMake[ingredient];
    }

    canMake[ingredient] = false;

    for (auto& ingr : ingredients[mp[ingredient]]) {
      if (!dfs(ingr, ingredients)) {
        return false;
      }
    }

    return canMake[ingredient] = true;
  }
};
// Runtime: 224 ms, faster than 99.68%
// Memory Usage: 95.4 MB, less than 68.11%