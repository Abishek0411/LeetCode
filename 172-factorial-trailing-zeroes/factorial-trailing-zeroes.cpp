class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n > 0) {
            n /= 5; // Count multiples of 5, 25, 125, etc.
            res += n;
        }
        return res;
    }
};