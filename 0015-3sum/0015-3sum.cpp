class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        vector<vector<int>> temp;
        int sum=0;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            
             int j=i+1;
             int k=n-1;
           while(j<k){
            sum=0;
            sum+=nums[i];
            sum+=nums[j];
            sum+=nums[k];
            if(sum==0){
                vector<int> ans={nums[i],nums[j],nums[k]};
                temp.push_back(ans);
                j++;
                k--;
                while(j<k&&nums[j]==nums[j-1]) j++;
                while(j<k&&nums[k]==nums[k+1]) k--;
            }
            else if(sum>0){
                k--;
            }
            else{
                j++;
            }
           }
        }
        return temp;
    }
};