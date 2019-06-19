class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    stack<int> stk;
    vector<int> locked(rooms.size(), 1);

    for (auto key : rooms[0]) {
      stk.push(key);
    }
    locked[0] = 0;

    while (!stk.empty()) {
      int key = stk.top();
      stk.pop();

      if (locked[key]) {
        for (auto k : rooms[key]) {
          stk.push(k);
        }

        locked[key] = 0;
      }
    }

    for (auto& l : locked) {
      if (l) {
        return false;
      }
    }

    return true;
  }
};  // 12ms

class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    stack<int> stk;
    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < rooms.size(); ++i) {
      mp[i] = rooms[i];
    }

    for (auto key : rooms[0]) {
      stk.push(key);
    }
    mp.erase(0);

    while (mp.size() > 0 && !stk.empty()) {
      int key = stk.top();
      stk.pop();

      auto keys = mp.find(key);
      if (keys != mp.end()) {
        for (auto key : keys->second) {
          stk.push(key);
        }

        mp.erase(key);
      }
    }

    return mp.size() > 0 ? false : true;
  }
};  // 12ms