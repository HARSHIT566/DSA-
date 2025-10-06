#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int dayCount = 1;  // start from day 1
        int currentLoad = 0;

        for (int w : weights) {

            if (currentLoad + w > capacity) {
                dayCount++;
                currentLoad = 0;
            }
            currentLoad += w;
        }

        return dayCount <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());   // minimum possible capacity
        int high = accumulate(weights.begin(), weights.end(), 0); // maximum possible capacity
        int ans = high;

        // Binary Search on capacity
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canShip(weights, days, mid)) {
                ans = mid;        // possible answer
                high = mid - 1;   // try smaller capacity
            } else {
                low = mid + 1;    // need larger capacity
            }
        }

        return ans;
    }
};

