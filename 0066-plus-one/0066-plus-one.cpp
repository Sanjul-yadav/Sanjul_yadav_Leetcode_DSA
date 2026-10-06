class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      // Start from the last digit

      for(int i=digits.size()-1; i>=0; i--){

        if(digits[i]<9){

            digits[i]++;

            return digits;
        }
        // If digit is 9, it becomes 0

        digits[i]=0;
      }    
      // If all digits were 9, add 1 at the beginning

      digits.insert(digits.begin(), 1);

      return digits;

    }
};
// class solution{
//     public:
//     vector<int> pluseone(vector<int>& digits){
//         // start fron the last digit
//         for (int i =digits.size()-1; i>=0; i++){
//             if (digits[i]<9){
//                 digits[i]++;
//                 return digits;

//             }
//             // if digit is 9 , it because 0 
//             digits [i]=0;

//         }
//         // if all digits were 9 , add 1 at the beginning 
//         digits.insert(digits.begin(),1);
//         return digits;
//     }
// };