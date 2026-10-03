// #include<bits/stdc++.h>
// class solution{
//     public:

//     vector<vector<int>> triplet(int n, vector<int>& nums)
//     {
//         set <vector<int>>st;
//         for (int i=0; i<n; i++){
//             set <int>hashset;
//             for( int j=i+1; j<n; j++){
//                 int third = -(nums[i]+ nums[j] );
//                 if (hashset.find(third) != hashset.end( )) {
//                     vector<int> temp ={nums[i], nums[j],third };
//                     sort (temp.begin(), temp.end());
//                     st.insert(temp); 
//                 }
//                 hashset.insert(nums[j]);
//             }
//         }
//         vector <vector<int >> ans(st.begin(), st.end());
//         return ans;
//     }
// };


/// hatching approch answer is correct but not acceptable 
// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums){
//         int n = nums.size();
//         set<vector<int>> st;
//         for (int i = 0; i < n; i++){
//             set<int> hashset;
//             for (int j = i + 1; j < n; j++){
//                 int third = -(nums[i] + nums[j]);
//                 if (hashset.find(third) != hashset.end()){
//                     vector<int> temp = {nums[i], nums[j], third};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 hashset.insert(nums[j]);
//             }
//         }
//         vector<vector<int>> ans(st.begin(), st.end());
//         return ans;
//     }
// };

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {

            // Duplicate i ko skip karo
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {

                    ans.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });

                    // Duplicate left values skip
                    while (left < right &&
                           nums[left] == nums[left + 1])
                        left++;

                    // Duplicate right values skip
                    while (left < right &&
                           nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }

                else if (sum < 0) {
                    left++;
                }

                else {
                    right--;
                }
            }
        }

        return ans;
    }
};