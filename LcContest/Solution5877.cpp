#include <bits/stdc++.h>

using namespace std;

//检测正方形No.5877（2013）
class DetectSquares {
public:
    unordered_map<uint64_t, int> points; // 坐标（x,y）出现的次数. 前32位用作x，后32位用作y
    DetectSquares() {

    }

    void add(vector<int> point) {
        points[uint64_t(point[0]) << 32 | point[1]]++;
    }

    int count(vector<int> point) {
        int ret = 0;
        int x = point[0], y = point[1];

        for (auto &p : points) {
            int x0 = (p.first >> 32), y0 = p.first & 0xffff;
            //判断两个点是否构成对角线
            if (x == x0 || y == y0) continue;
            if (abs(x-x0) != abs(y-y0)) continue;

            int x1 = x, y1 = y0;
            int x2 = x0, y2 = y;
            auto it1 = points.find(uint64_t(x1) << 32 | y1);
            auto it2 = points.find(uint64_t(x2) << 32 | y2);

            if (it1 != points.end() && it2 != points.end()){
                ret += it1->second * it2->second * p.second;
            }
        }
        return ret;
    }
};
