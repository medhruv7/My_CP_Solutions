class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0;i < n;++i){
            if(i != 0 && nums[i] == nums[i - 1])continue;
            int lo = i + 1,hi = n - 1;
            while(lo < hi){
                if(nums[lo] + nums[hi] == -nums[i]){
                    ans.push_back({nums[lo],nums[hi],nums[i]});
                    while(lo < hi && nums[lo] == nums[lo + 1])++lo;
                    while(lo < hi && nums[hi] == nums[hi - 1])--hi;
                    ++lo,--hi;
                }else if(nums[lo] + nums[hi] > -nums[i]){
                    --hi;
                }else{
                    ++lo;
                }
            }
        }
        return ans;
    }
};
