class SQL {
  unordered_map<string, unordered_map<int, vector<string>>> table;
  unordered_map<string, int> cnt;

 public:
  SQL(vector<string>& names, vector<int>& columns) {
    for (int i = 0; i < names.size(); ++i) {
      cnt[names[i]] = 0;
    }
  }

  void insertRow(string name, vector<string> row) {
    int id = ++cnt[name];
    table[name][id] = row;
  }

  void deleteRow(string name, int rowId) { table[name].erase(rowId); }

  string selectCell(string name, int rowId, int columnId) {
    return table[name][rowId][columnId - 1];
  }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * obj->insertRow(name,row);
 * obj->deleteRow(name,rowId);
 * string param_3 = obj->selectCell(name,rowId,columnId);
 */
// Runtime 601 ms
// Memory 145.9 MB
// 2022.11.22 at 茗筑美嘉