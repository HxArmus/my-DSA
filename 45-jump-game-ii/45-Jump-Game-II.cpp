class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return 0;

        int coverage = 0;   // End of the current jump's range
        int farthest = 0;   // Farthest index we can reach
        int count = 0;      // Number of jumps

        for (int i = 0; i < n; i++) {

            // Update the farthest reachable index
            farthest = max(farthest, i + nums[i]);

            // End of the current jump range
            if (i == coverage) {
                coverage = farthest;
                count++;
            }

            // If we can reach the destination
            if (coverage >= n - 1)
                return count;
        }

        return count;
    }
};