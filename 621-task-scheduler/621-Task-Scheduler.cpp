class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26,0);
        if(n==0) return tasks.size();

        for(auto &ch : tasks){
            mp[ch-'A']++;
        }
        sort(mp.begin(),mp.end(),[](int &a ,int &b){
            return a>b;
        });
        int gaps = mp[0]-1;
        int idleSpots = n*gaps;

        for(int i=1;i<26;i++){
            idleSpots -= min(gaps,mp[i]);
            if(idleSpots<=0) return tasks.size();
        }
        
        return tasks.size()+idleSpots;
    }
};