class Node {
public:
    Node(int freq) : freq(freq), prev(nullptr), next(nullptr) {

    }

    ~Node() {
        prev = nullptr;
        next = nullptr;
    }
private:
    friend class AllOne;

    int freq;
    Node* prev;
    Node* next;
    unordered_set<string> keys;
};
class AllOne {
public:
    AllOne() : head(new Node(0)), tail(new Node(0)) {
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        if (mp.find(key) == mp.end()) {
            Node* nextNode = head->next;
            Node* prevNode = nextNode->prev;
            if (nextNode->freq == 1) {
                nextNode->keys.insert(key);
                mp[key] = nextNode;
            } else {
                Node* newNode = new Node(1);
                newNode->keys.insert(key);
                mp[key] = newNode;

                newNode->next = nextNode;
                nextNode->prev = newNode;
                newNode->prev = prevNode;
                prevNode->next = newNode;
            }
        } else {
            Node* curNode = mp[key];
            Node* nextNode = curNode->next;
            Node* prevNode = curNode->prev;
            curNode->keys.erase(key);

            if (nextNode->freq == curNode->freq + 1) {
                nextNode->keys.insert(key);
                mp[key] = nextNode;

                if (curNode->keys.empty()) {
                    nextNode->prev = prevNode;
                    prevNode->next = nextNode;
                    delete curNode;
                }
            } else {
                Node* newNode = new Node(curNode->freq + 1);
                newNode->keys.insert(key);
                mp[key] = newNode;
                if (curNode->keys.empty()) {
                    newNode->next = nextNode;
                    nextNode->prev = newNode;
                    newNode->prev = prevNode;
                    prevNode->next = newNode;
                    delete curNode;
                } else {
                    newNode->next = nextNode;
                    nextNode->prev = newNode;
                    curNode->next = newNode;
                    newNode->prev = curNode;
                }
            }
        }
    }
    
    void dec(string key) {
        if (mp.find(key) == mp.end()) {
            return;
        }

        Node* node = mp[key];
        node->keys.erase(key);
        int freq = node->freq;

        if (freq == 1) {
            mp.erase(key);
        } else {
            Node* prevNode = node->prev;

            if (prevNode == head || prevNode->freq != node->freq - 1) {
                Node* newNode = new Node(node->freq - 1);
                newNode->keys.insert(key);

                newNode->next = node;
                newNode->prev = prevNode;
                prevNode->next = newNode;
                node->prev = newNode;

                mp[key] = newNode;
            } else {
                prevNode->keys.insert(key);
                mp[key] = prevNode;
            }
        }


        if (node->keys.empty()) {
            removeNode(node);
        }
    }
    
    string getMaxKey() {
        if (tail->prev == head) {
            return "";
        }

        return *tail->prev->keys.begin();
    }
    
    string getMinKey() {
        if (head->next == tail) {
            return "";
        }

        return *head->next->keys.begin();
    }
private:
    Node* head;
    Node* tail;
    unordered_map<string, Node*> mp;

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;  
        nextNode->prev = prevNode;  

        delete node;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
 // 97 ms
 // 61.63 MB
