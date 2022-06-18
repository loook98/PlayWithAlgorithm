#include <bits/stdc++.h>

using namespace std;

//<没有会员，没提交这个题>
class Solution {
public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        //按结束时间排序的最下堆
        auto comp = [](vector<int> interval1, vector<int> interval2){
            return interval1[1] > interval2[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> meetings(comp);

        int res = 0;
        sort(intervals.begin(), intervals.end());
        for (auto &interval: intervals) {
            //「当前没有会议室」或者「最早结束会议室也冲突」，需要新开一个会议室
            if (meetings.empty() || meetings.top()[1] > interval[0]) {
                meetings.push(interval);
                res++;
            } else { //旧的会议室可以使用
                meetings.pop();
                meetings.push(interval);
            }
        }
        return res;
    }
};

int main(){
    vector<vector<int>> meetings = {{0, 30},{4,6}, {5, 10},{15, 20}};
    cout << Solution().minMeetingRooms(meetings);
    return 0;
}