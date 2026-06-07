#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int capacity;

    // key, value
    list<pair<int, int>> cache;

    // key -> iterator in list
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto it = mp[key];
        int value = it->second;

        // Move accessed node to front (most recently used)
        cache.erase(it);
        cache.push_front({key, value});
        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            cache.erase(mp[key]);
        }
        else if ((int)cache.size() == capacity) {
            // Remove least recently used
            int lruKey = cache.back().first;
            mp.erase(lruKey);
            cache.pop_back();
        }

        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};

int main() {
    int capacity, Q;
    cin >> capacity;
    cin >> Q;

    LRUCache lru(capacity);

    while (Q--) {
        string op;
        cin >> op;

        if (op == "PUT") {
            int key, value;
            cin >> key >> value;
            lru.put(key, value);
        }
        else if (op == "GET") {
            int key;
            cin >> key;
            cout << lru.get(key) << "\n";
        }
    }

    return 0;
}