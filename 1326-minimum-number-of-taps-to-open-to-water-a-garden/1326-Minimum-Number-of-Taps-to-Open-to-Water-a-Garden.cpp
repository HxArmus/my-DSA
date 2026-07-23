class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxReach(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);

            maxReach[left] = max(maxReach[left], right);
        }

        int coverage = 0;
        int farthest = 0;
        int taps = 0;

        for (int i = 0; i <= n; i++) {
            if (i > farthest){
                return -1;
            }
            if(i>coverage){
                taps++;
                coverage = farthest;
            }
            farthest = max(farthest,maxReach[i]);

           
        }
    return taps;

    }
};

