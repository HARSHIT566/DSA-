#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

class Solution {
private:
    
    long long calculate_hours(const std::vector<int>& piles, int k) {
        long long total_hour= 0;
        for (int p : piles) {
          
            total_hour += (long long)(p + k - 1) / k;
        }
        return total_hour;
    }

public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            long time_needed = calculate_hours(piles, mid);

            if (time_needed <= h) {
            
                result = mid;
                right = mid - 1;
            } else {
               
                left = mid + 1;
            }
        }

        return result;
    }
};
