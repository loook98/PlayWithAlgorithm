#include <bits/stdc++.h>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class NestedIterator {
private:
    vector<int> vectorlize;
    int index = -1;
public:
    void nestedList2vector(const vector<NestedInteger> &nestedList){
        for (auto i : nestedList) {
            if (i.isInteger()){
                vectorlize.emplace_back(i.getInteger());
            } else{
                nestedList2vector(i.getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        nestedList2vector(nestedList);
    }

    int next() {
        index++;
        return vectorlize[index];
    }

    bool hasNext() {
        if (index + 1 < vectorlize.size())
            return true;
        else
            return false;
    }
};