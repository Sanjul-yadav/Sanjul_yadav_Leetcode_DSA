// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0;
        int right = n;
        int FBD =-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
             
            bool res= isBadVersion( mid);
            if (res){
                FBD =mid;
                right =mid -1;
               } else{
                left =mid +1;                
             }
        }
        return FBD;
    }    
};

/*
1. What is the question asking?
Suppose there are 5 software versions:
[1, 2, 3, 4, 5]
Version 4 is the first bad version. Every version after it is also bad.
- Version 1 → Good
- Version 2 → Good
- Version 3 → Good
- Version 4 → Bad
- Version 5 → Bad
Our task is to find the first bad version using the minimum number of API calls.
2. Code explanation

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

What does each line do?
Code	Meaning
left = 1	First version
right = n	Last version
mid = left + (right-left)/2	Find the middle version
isBadVersion(mid)	Check whether the middle version is bad
right = mid	If bad, search the left half
left = mid + 1	If good, search the right half
return left	Return the first bad version
3. Dry run with example
Input: n = 5, first bad version = 4.
Step 1
left = 1, right = 5
1
Good
2
Good
3
mid
4
Bad
5
Bad

mid = 3 → isBadVersion(3) returns false.
So, left = mid + 1 = 4.

Step 2
left = 4, right = 5
4
mid · Bad
5
Bad

mid = 4 → isBadVersion(4) returns true.
So, right = mid = 4.

Step 3: Finish
Now left = 4 and right = 4. The loop stops because left < right is false.
Output: 4

4. Why use Binary Search?
Instead of checking every version one by one, binary search eliminates approximately half the remaining versions with each API call.
- Time complexity: \(O(\log n)\)
- Extra space complexity: \(O(1)\)
Remember this rule:
- Bad version → right = mid
- Good version → left = mid + 1
- Finally → return left
The important detail is right = mid, not mid - 1, because the middle version itself might be the first bad version.
*/
