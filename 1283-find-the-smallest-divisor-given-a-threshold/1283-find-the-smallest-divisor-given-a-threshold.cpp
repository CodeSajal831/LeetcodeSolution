int calcsmalldiv(vector<int>& nums, int mid) {
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += (nums[i] + mid - 1) / mid;
    }

    return sum;
}

int maxArr(vector<int>& nums, int n) {
    int maxi = nums[0];

    for (int i = 0; i < n; i++) {
        if (nums[i] > maxi)
            maxi = nums[i];
    }

    return maxi;
}

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = -1;
        int n = nums.size();

        int low = 1;
        int high = maxArr(nums, n);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int smaldiv = calcsmalldiv(nums, mid);

            if (smaldiv <= threshold) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};