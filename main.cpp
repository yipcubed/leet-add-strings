#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

// https://leetcode.com/problems/add-strings/

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string addStrings(string num1, string num2) {
        stringstream os;
        int i = num1.length();
        int j = num2.length();
        if (--i < 0) return num2;
        if (--j < 0) return num1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = (i >= 0 ? (num1[i] - '0') : 0) +
                      (j >= 0 ? (num2[j] - '0') : 0) +
                      carry;
            if (sum > 9) {
                carry = 1;
                sum -= 10;
            } else {
                carry = 0;
            }
            os << sum;
            --i;
            --j;
        }
        string s = os.str();
        reverse(s.begin(), s.end());
        return s;
    }
};

void test1() {

    cout << " ? " << Solution().addStrings("275", "1006") << endl;
}

void test2() {

}

void test3() {

}