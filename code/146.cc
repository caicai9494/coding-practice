#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <unordered_map>

using namespace std;
class LRUCache
{
    public:
	LRUCache(int capacity) : capacity_(capacity) {
	}

	int get(int key) {
	    if(hash_.find(key) != hash_.end()) {
		items_.splice(items_.begin(), items_, hash_[key]);
		return hash_[key]->second;
	    }
	    else return -1;
	}

	void set(int key, int value) {
	    if(hash_.find(key) == hash_.end()) {
		if(capacity_ <= items_.size()) {
		    hash_.erase(items_.back().first);
		    items_.pop_back();
		}
		items_.push_front(make_pair(key, value));
		hash_[key] = items_.begin();

	    } else {
		hash_[key]->second = value;
		items_.splice(items_.begin(), items_, hash_[key]);
	    }
	}

    private:
	unordered_map<int, list<pair<int, int>>::iterator> hash_;
	list<pair<int, int>> items_;

	int capacity_;
};
