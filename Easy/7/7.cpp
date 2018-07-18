#include <iostream>
#include <cmath>

class Solution {
public:
    int reverse(int x) {
        int reverse = 0;
        while (x != 0) {
            if (abs(reverse) > INT_MAX / 10) return 0;
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return reverse;
    }
};
