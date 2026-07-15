class Solution {
public:
    int oddSum(int n) {
        if (n == 1)
            return 1;

        return (2 * n - 1) + oddSum(n - 1);
    }
    int evenSum(int n) {
        if (n == 0) {
            return 0;
        }
        return (2 * n) + evenSum(n - 1);
    }
    int gcdOfOddEvenSums(int n) { return gcd(oddSum(n), evenSum(n)); }
};