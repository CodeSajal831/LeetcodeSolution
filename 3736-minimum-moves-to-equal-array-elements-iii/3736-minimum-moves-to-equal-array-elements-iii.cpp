class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int lar=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]>lar){
                lar=nums[i];
            }
        }
        int ans =0;
        for(int i=0;i<n;i++){
            ans+=(lar-nums[i]);
        }
        return ans;
    }
};