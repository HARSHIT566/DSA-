class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        auto computeSum = [&](int divisor) {
            int sum = 0;
            for (int num : nums) {
                sum += (num + divisor - 1) / divisor; // equivalent to ceil(num/divisor)
            }
            return sum;
        };

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = computeSum(mid);

            if (sum <= threshold) {
                ans = mid;      // possible answer, try smaller
                high = mid - 1;
            } else {
                low = mid + 1;  // need a larger divisor
            }
        }
        return ans;
    }
};
