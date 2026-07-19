class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });

        int startP = p[0][0];
        int endP = p[0][1];
        int cnt = 1;

        for(int i=1;i<p.size();i++){
            int nxtSp  = p[i][0];
            int nxtEp = p[i][1];
            if(endP < nxtSp){
                cnt++;
                endP = nxtEp;
            }
        }

        return cnt;
        
    }
};