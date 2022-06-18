#include <bits/stdc++.h>

using namespace std;

class MSDSort {
public:
    static void sort(vector<string> &arr) {
        vector<string> temp(arr.size());
        sort(arr, 0, arr.size() - 1, 0, temp);
    }

private:
    //对于arr[left...right]，对其中的字符串按r位置进行排序
    static void sort(vector<string> &arr, int left, int right, int r, vector<string> &temp) {
        //递归终止条件
        if (left >= right)
            return;

        //一、计数排序
        int R = 256;
        vector<int> cnt(R + 1, 0); //0表示为空，1~R为正常字符
        vector<int> index(R + 2, 0);

        //1.计数
        //1.1计算出现的次数
        for (int i = left; i <= right; ++i)
            cnt[r >= arr[i].size() ? 0 : (arr[i][r] + 1)]++;
        //1.2计算每个字符串的index
        for (int i = 0; i < R + 1; ++i)
            index[i + 1] = index[i] + cnt[i];

        //2.排序
        //2.1进行排序，结果放到temp中
        for (int i = left; i <= right; ++i) {
            int letter = r >= arr[i].size() ? 0 : (arr[i][r] + 1);
            temp[left + index[letter]] = arr[i];
            index[letter]++;
        }
        //2.2将temp中的结果放回原数组中
        for (int i = left; i <= right; ++i)
            arr[i] = temp[i];


        //二、递归下去
        for (int i = 0; i < R; ++i) {
            sort(arr, left + index[i], left + index[i + 1] - 1, r + 1, temp);
        }
    }
};

//int main(){
//    vector<string> arr = {"BCA", "CBAA", "AC", "BADFE", "ABC", "CBA"};
//    MSDSort().sort(arr);
//    for (auto s: arr) {
//        cout << s << endl;
//    }
//}