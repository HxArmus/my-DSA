class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, int> lastPos;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            lastPos[s[i]] = i;
        }
        int i = 0;
        int start = 0;
        int end = 0;
        while (i < n) {
            end = max(end, lastPos[s[i]]);

            if (i == end) {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
            i++;
        }
        return ans;
    }
};
