#include <bits/stdc++.h>

using namespace std;

//没做完。现在的标号是2092
//class Solution {
//public:
//    static bool cmp(const vector<int> &meeting1, const vector<int> &meeting2){
//        return meeting1[2] < meeting2[2];
//    }
//    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
//        //按时间排序会议
//        sort(meetings.begin(), meetings.end(), cmp);
//
//        unordered_set<int> knownPerson;
//        knownPerson.insert(0);
//        knownPerson.insert(firstPerson);
//
//        int lastTime = 0;
//        int i = 0;
//        while (i < meetings.size()){
//            vector<int> sameTimeMeetings;
//            while (i < meetings.size() && meetings[i][2] == lastTime){
//                sameTimeMeetings.emplace_back(i);
//                i++;
//            }
//
//
//
//
//        }
//
//
//    }
//};