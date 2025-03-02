#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        
        // Handle edge cases where the array has only one or two elements
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) return nums[0] > nums[1] ? 0 : 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            // Check if mid is a peak
            if ((mid == 0 || nums[mid] > nums[mid - 1]) &&
                (mid == nums.size() - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
            }
            // Move to the left side if the left neighbor is greater
            else if (mid > 0 && nums[mid] < nums[mid - 1]) {
                e = mid - 1;
            }
            // Move to the right side if the right neighbor is greater
            else {
                s = mid + 1;
            }
        }

        // This line is technically unreachable but added for completeness
        return -1;
    }
};