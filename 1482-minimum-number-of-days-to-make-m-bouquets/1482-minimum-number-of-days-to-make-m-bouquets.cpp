int maxiele(vector<int>& bloomDay){
    int maxi=bloomDay[0];
    for(int i=1;i<bloomDay.size();i++){
        if(bloomDay[i]>maxi){
            maxi=bloomDay[i];
        }
    }
    return maxi;
}

int miniele(vector<int>& bloomDay){
    int mini=bloomDay[0];
    for(int i=1;i<bloomDay.size();i++){
        if(bloomDay[i]<mini){
            mini=bloomDay[i];
        }
    }
    return mini;
}


bool possibleTomake(vector<int>& bloomDay,int day, int m, int k){
    int cnt=0;
    int toboq=0;
    for(int i=0;i<bloomDay.size();i++){
         if(bloomDay[i]<=day){
            cnt++;
         }else{
            toboq+=(cnt/k);
            cnt=0;
         }
        
    }
     toboq+=(cnt/k);
         if(toboq>=m) return true;
         return false;
}

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long c=1LL*m*k;
        if(c>bloomDay.size()) return -1;
        int low=miniele(bloomDay);
        int high=maxiele(bloomDay);
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            bool recieved=possibleTomake(bloomDay,mid,m,k);
            if(recieved==true){
               ans=mid;
               high=mid-1;
            }else{
                low=mid+1;
            }

        }
        return ans;
    }
};