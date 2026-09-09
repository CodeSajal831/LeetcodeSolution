long long calctotal(vector<int>& piles, int mid) {
    long long totalhours = 0;

    for (int i = 0; i < piles.size(); i++) {
        totalhours += (piles[i] + mid - 1) / mid;
    }

    return totalhours;
}

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = INT_MAX;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long hours = calctotal(piles, mid);

            if (hours <= h) {
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