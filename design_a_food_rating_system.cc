class FoodRatings {
  unordered_map<string, pair<string, int>> fo_cu_ra;
  unordered_map<string, set<pair<int, string>>> cu_ra_fo;

 public:
  FoodRatings(vector<string>& foods,
              vector<string>& cuisines,
              vector<int>& ratings) {
    for (int i = 0; i < foods.size(); ++i) {
      cu_ra_fo[cuisines[i]].insert({-ratings[i], foods[i]});
      fo_cu_ra[foods[i]] = {cuisines[i], ratings[i]};
    }
  }

  void changeRating(string food, int newRating) {
    auto& cu_ra = fo_cu_ra[food];
    cu_ra_fo[cu_ra.first].erase({-cu_ra.second, food});
    cu_ra_fo[cu_ra.first].insert({-newRating, food});

    cu_ra.second = newRating;
  }

  string highestRated(string cuisine) {
    return cu_ra_fo[cuisine].begin()->second;
  }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
// Runtime: 885 ms, faster than 33.33%
// Memory Usage: 155.1 MB, less than 33.33%
// 2022.7.28 at 奥盛大厦