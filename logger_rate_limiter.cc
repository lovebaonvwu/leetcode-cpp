class Logger {
  unordered_map<string, int> mp;

 public:
  Logger() {}

  bool shouldPrintMessage(int timestamp, string message) {
    if (mp.find(message) != mp.end() && timestamp - mp[message] < 10) {
      return false;
    }

    mp[message] = timestamp;
    return true;
  }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
// Runtime 62 ms
// Memory 32.5 MB
// 2023.2.2 at 聊城月季西路长江路