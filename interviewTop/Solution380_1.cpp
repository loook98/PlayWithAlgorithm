#include <bits/stdc++.h>

using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> numToIndex;
public:

    RandomizedSet() {

    }

    bool insert(int val) {
        if (numToIndex.count(val))
            return false;
        nums.emplace_back(val);
        numToIndex[val] = nums.size()-1;
        return true;
    }

    bool remove(int val) {
        if (!numToIndex.count(val))
            return false;
        int index = numToIndex[val];
        numToIndex[nums.back()] = index;
        swap(nums[index], nums.back());
        nums.pop_back();
        numToIndex.erase(val);
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};