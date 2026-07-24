class Solution {
public:
static int myComparator(int &a,int &b){
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(b) + to_string(a);

    return s1>s2;
}
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),myComparator);

        if(nums[0]==0) return "0"; // edge case 
        
        string res = "";
        for(auto &num : nums){
            res += to_string(num);
        }
        return res;
    }
};