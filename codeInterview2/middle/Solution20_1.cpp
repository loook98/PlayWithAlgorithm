#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //自动机的状态
    enum State {
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END
    };

    //自动机的状态
    enum Input {
        INPUT_NUMBER,
        INPUT_EXP,
        INPUT_POINT,
        INPUT_SIGN,
        INPUT_SPACE,
        INPUT_ILLEGAL
    };

    Input charToInput(char ch) {
        if (ch >= '0' && ch <= '9')
            return INPUT_NUMBER;
        else if (ch == 'e' || ch == 'E')
            return INPUT_EXP;
        else if (ch == '.')
            return INPUT_POINT;
        else if (ch == '+' || ch == '-')
            return INPUT_SIGN;
        else if (ch == ' ')
            return INPUT_SPACE;
        else
            return INPUT_ILLEGAL;
    }

    //自动机的状态转移图
    //当前State | 当前State对应不同Input时的下一个State
    unordered_map<State, unordered_map<Input, State>> table = {
            {STATE_INITIAL,
                    {{INPUT_SPACE, STATE_INITIAL},
                     {INPUT_NUMBER, STATE_INTEGER},
                     {INPUT_POINT, STATE_POINT_WITHOUT_INT},
                     {INPUT_SIGN, STATE_INT_SIGN}}},
            {STATE_INT_SIGN,
                    {{INPUT_NUMBER, STATE_INTEGER},
                    {INPUT_POINT, STATE_POINT_WITHOUT_INT}}},
            {STATE_INTEGER,
                    {{INPUT_NUMBER, STATE_INTEGER},
                             {INPUT_EXP, STATE_EXP},
                             {INPUT_POINT, STATE_POINT},
                             {INPUT_SPACE, STATE_END}}},
            {STATE_POINT, {
                                  {INPUT_NUMBER, STATE_FRACTION},
                                  {INPUT_EXP, STATE_EXP},
                                  {INPUT_SPACE, STATE_END}
                               }
            },
            {STATE_POINT_WITHOUT_INT, {
                                              {INPUT_NUMBER, STATE_FRACTION}
                                      }
            },
            {STATE_FRACTION,
                    {
                            {INPUT_NUMBER, STATE_FRACTION},
                            {INPUT_EXP, STATE_EXP},
                            {INPUT_SPACE, STATE_END}
                    }
                },
            {STATE_EXP,
                    {
                            {INPUT_NUMBER, STATE_EXP_NUMBER},
                            {INPUT_SIGN, STATE_EXP_SIGN}
                    }
            },
            {STATE_EXP_SIGN, {
                                     {INPUT_NUMBER, STATE_EXP_NUMBER}
                             }
            },
            {STATE_EXP_NUMBER, {
                                       {INPUT_NUMBER, STATE_EXP_NUMBER},
                                       {INPUT_SPACE, STATE_END}
                               }
            },
            {STATE_END, {
                                {INPUT_SPACE, STATE_END}
                        }
            }
    };

    bool isNumber(string s) {
        int len = s.size();
        State st = STATE_INITIAL;

        for (int i = 0; i < len; ++i) {
            Input in = charToInput(s[i]);
            if (!table[st].count(in)){ //当前状态不能处理这种输入
                return false;
            }else{
                st = table[st][in];
            }
        }

        return st  == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
    }
};