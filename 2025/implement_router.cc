using Packet = tuple<int, int, int>;

class Router {
    unordered_map<int, vector<int>> mp;
    set<Packet> dup;
    queue<Packet> q;
    unordered_map<int, int> removed;
    int size;
public:
    Router(int memoryLimit) {
        size = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if (dup.find({source, destination, timestamp}) != dup.end()) {
            return false;
        }

        if (q.size() == size) {
            auto [src, dest, time] = q.front();
            q.pop();

            dup.erase({src, dest, time});

            ++removed[dest];
        }

        q.push({source, destination, timestamp});
        mp[destination].push_back(timestamp);
        dup.insert({source, destination, timestamp});

        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) {
            return {};
        }

        auto [src, dest, time] = q.front();
        q.pop();

        dup.erase({src, dest, time});

        ++removed[dest];

        return {src, dest, time};
    }
    
    int getCount(int destination, int startTime, int endTime) {

        auto times = mp[destination];
        auto offset = removed[destination];
        auto right = upper_bound(times.begin() + offset, times.end(), endTime);
        auto left = lower_bound(times.begin() + offset, times.end(), startTime);

        return right - left;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */

 // Time: O(log n)
 // Space: O(n)

 class Router {
    unordered_map<int, vector<int>> mp;
    map<vector<int>, int> dup;
    queue<vector<int>> q;
    unordered_map<int, int> removed;
    int size;
public:
    Router(int memoryLimit) {
        size = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int> p = {source, destination, timestamp};
        
        if (dup.find(p) != dup.end()) {
            return false;
        }

        if (q.size() == size) {
            auto res = q.front();
            q.pop();

            dup.erase(res);

            ++removed[res[1]];
        }

        q.push(p);
        mp[destination].push_back(timestamp);
        ++dup[p];

        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) {
            return {};
        }

        auto res = q.front();
        q.pop();

        dup.erase(res);

        ++removed[res[1]];

        return res;
    }
    
    int getCount(int destination, int startTime, int endTime) {

        if (mp.find(destination) == mp.end()) {
            return 0;
        }

        auto& times = mp[destination];
        auto offset = removed[destination];
        auto right = upper_bound(times.begin() + offset, times.end(), endTime);
        auto left = lower_bound(times.begin() + offset, times.end(), startTime);

        return right - left;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */

// Time: O(log n)
// Space: O(n)