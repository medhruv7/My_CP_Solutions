class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return -1;
        int lo = 0,hi = n - 1;
        while(lo < hi){
            int mid = (lo + hi)>>1;
            cout << mid << '\n';
            if(nums[mid] == target) return mid;
            if(nums[mid] > target){
                // the right sorted range
                if(nums[mid] < nums[0]){
                    hi = mid - 1;
                }else{
                    // left sorted range
                    if(target >= nums[0]){
                        hi = mid - 1;
                    }else{
                        lo = mid + 1;
                    }
                }
            }
            else if(nums[mid] < target){
                // right sorted 
                if(nums[mid] < nums[0]){
                    if(target > nums[n - 1]){
                        hi = mid - 1;
                    }else{
                        lo = mid + 1;
                    }
                }else{
                    // left sorted
                    lo = mid + 1;
                }
            }
        }
        
        if(nums[lo] == target) return lo;
        if(nums[hi] == target) return hi;
        return -1;
    }
};
