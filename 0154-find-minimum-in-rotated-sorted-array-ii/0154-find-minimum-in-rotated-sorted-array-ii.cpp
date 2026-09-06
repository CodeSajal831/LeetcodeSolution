class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        int low=0;
        int high=n-1;
        if(n==1) return nums[0];
        while(low<=high){
            int mid=(low+(high-low)/2);
            if(nums[low]==nums[mid]&&nums[mid]==nums[high]){
             mini = min(mini, nums[low]);
                low++;
                high--;
                continue;
            }
            if(nums[low]<=nums[mid]){
                mini=min(nums[low],mini);
                low=mid+1;
            }else{
                mini=min(nums[mid],mini);
                high=mid-1;
            }
        }
        return mini;
    }
};