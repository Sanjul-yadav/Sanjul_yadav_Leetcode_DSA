class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      //  return lower_bound(nums.begin(), nums.end(), target) - nums.begin(); //  this is a gpt method
//BINARY SEARCH 
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};


        //this is practice 
        //  int n = nums.size();

        // for (int i = 0; i < n; i++) {
        //     if (nums[i] == target) {
        //         return i;
        //     }
        //   else if(nums[i] > target){
        //         return i;
        //     }
        //    else if(nums[i] < target){
        //         return i;
        //     }
        // }

        // return n;