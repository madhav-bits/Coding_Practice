/*
*
//******************************************************170. Two Sum III - Data structure design.***********************************************

Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example 1:

add(1); add(3); add(5);
find(4) -> true
find(7) -> false
Example 2:

add(3); add(1); add(2);
find(3) -> true
find(6) -> false




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["TwoSum","add","add","add","find","find"]
[[],[2],[1],[5],[4],[7]]


["TwoSum","add","add","add","find","find"]
[[],[2],[2],[5],[4],[7]]




["TwoSum","add","add","add","find","find"]
[[],[1],[3],[5],[4],[7]]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is HashMap based. We store the nums in the map and maintain the count of occurance of a num. Upon request for pairs,
// we iterate through the nums in map, check for presence of second num in map. If present, second num has to be different from first nums or 
// if both nums are same, then the count of that num has to be >0.






class TwoSum {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int>m;												// Maintains the count of nums.
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int num) {
        m[num]++;															// INc. the count of num.
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int target) {
        for(auto it=m.begin();it!=m.end();it++){							// Iterating through the map the pair of values.
            int num1=it->first;
            int num2=target-it->first;										// Calc. second num that makes the target sum.
            // cout<<"num1: "<<num1<<" and num2: "<<num2<<endl;
            if(m.count(num2)==1 &&(num2!=num1 || m[num1]>1)) return true;	// If second num pres., then both diff/count of num>0.
        }
        return false;														// If no such pair found, return false.
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */