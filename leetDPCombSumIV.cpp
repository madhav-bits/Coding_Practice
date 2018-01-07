/*

//********************************************************377. Combination Sum IV.*******************************************************

Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a 
positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.


//Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//Follow up:
//What if negative numbers are allowed in the given array?
//How does it change the problem?
//What limitation we need to add to the question to allow negative numbers?

// If Negative numbers are allowed, add the largest negative number to all the integers in the vector and also the target and work in the 
// same way as below.


//The idea of algorithm is that "i" has same no. of combinations as "i-num" number. Then Incrementing the no. of occurences considering the  
//val. of each member of the vector. 


class Solution {
public:
    int combinationSum4(vector<int>& v, int target) {
        int len=v.size();
        int arr[target+1]={0};                          //Initializing the array.
        for(int i=0;i<len;i++)                          //Initializing the first occurence of array numbers.
            if(v[i]<=target)                            //Not initializing those which are more than target to avoid access errors.
                arr[v[i]]=1;
        
        for(int i=1;i<=target;i++){						// Contains the number of occurences of all the numbers till target.
            for(int j=0;j<len;j++){
                int num =v[j];
                if((i-num)>=0)							//If (i-num) occurs "x" times, then (i) also occurs "x" times. 
                    arr[i]+=arr[i-num];
            }
        }
        
        /*
        for(const auto& k:arr)
            cout<<"The member of array for num: "<<l<<" is: "<<k<<endl;
        */
        
        //cout<<"The answer is: "<<arr[target]<<endl;
        return arr[target];								//Returns the array element which contains no. of combinatins to get target.
    }
};