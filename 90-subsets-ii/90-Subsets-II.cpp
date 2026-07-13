class Solution {
public:
void solve(vector<int>&nums,vector<int>&path,vector<vector<int>>&ans,int index){
    // base case
    if(index >= nums.size()){
        ans.push_back(path);
        return;
    }
    
    //includeing
    int element = nums[index];
    path.push_back(element);
    solve(nums,path,ans,index+1);
    path.pop_back();

    while(index+1 < nums.size() && nums[index] == nums[index+1]) index++;

    //excluding 
    solve(nums,path,ans,index+1);

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>path;
        solve(nums,path,ans,0);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};