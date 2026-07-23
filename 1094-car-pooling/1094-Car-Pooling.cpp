class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>>events;
        for(auto & it : trips){
            events.push_back({it[1],it[0]});
            events.push_back({it[2],-1*it[0]});
        }
        sort(events.begin(),events.end());
        int passengers =0;
        for(auto &event : events){
            if(passengers > capacity) return false;
            passengers += event.second;
        }
        return true;
    }
};