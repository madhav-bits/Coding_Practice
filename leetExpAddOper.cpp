/*
*
//******************************************************282. Expression Add Operators.***********************************************

Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between 
the digits so they evaluate to the target value.

Example 1:

Input: num = "123", target = 6
Output: ["1+2+3", "1*2*3"] 
Example 2:

Input: num = "232", target = 8
Output: ["2*3+2", "2+3*2"]
Example 3:

Input: num = "105", target = 5
Output: ["1*0+5","10-5"]
Example 4:

Input: num = "00", target = 0
Output: ["0+0", "0-0", "0*0"]
Example 5:

Input: num = "3456237490", target = 9191
Output: []




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"100203"
6

"10023"
6

"123"
6


"12"
6




// Time Complexity: O(n).  
// Space Complexity: O(n*n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*n).
// Space Complexity: O(n*n).	
// This algorithm is Depth First Search. At each step, we extract int from the string starting from the beginning index, we add this num to 
// sum which we have passed to this fn. call, so that this nums contibutes to final sum and pass the udpated sum to next fn. call, we also pass 
// the curr. num to next call, which is useful in multiplying case, as the curr. num is required in calc. mult. b/w curr. and next extracted
// num, and the curr. num shouldn't be involved in the total sum directly(has to involve through mult.), so subtract prev. num from the sum till
// now and add the product of prev. and curr. num to the sum, we pass the product of two nums as the curr. num, as this is the contibution of 
// curr. num(and prev. num) to the final sum, when the next call wants to multiply, it can go to state prior to curr. num by sub. (curr.*prev).


// We also need to have all the chars in the final res. string, means  as "02" would be converted to "2" in the sum, so, won't consider those nums.
// We also don't consider consecutive zeroes-"000", contributing to sum, as first zero in seq. has done the same contribution. 









class Solution {
public:
    vector<string>ans;
    void extractSum(string s, int index, string res, long sum,long old, int target){
        //cout<<"Inside the fn. with index: "<<index<<" with sum: "<<sum<<" with str: "<<res<<endl;
        if(index==s.length()){												// If end of str. is reached.
            // cout<<"Inside the final if condition with index: "<<index<<" with sum: "<<sum<<" with str: "<<res<<endl;
            if(sum==target)													// If target achieved, push str to final res.
                ans.push_back(res);
        }
        for(int i=index;i<s.length();i++){
            long num=stol(s.substr(index,i-index+1));						// Extract num.
            if(i>index && stol(s.substr(index,1))==0) break;				// Avoids dups bec. of consec. "0"s, trailing zeroes.
            extractSum(s,i+1,res+"*"+to_string(num), sum-old+(old*num),(old*num),target);// Calc. prod and add it, pass the calc. value to fn. 
            extractSum(s,i+1,res+"+"+to_string(num), sum+num,num,target);	// Add the curr. num to the sum, pass curr. num to next fn.
            extractSum(s,i+1,res+"-"+to_string(num), sum-num,-num,target);	// Sub. the curr. num from the sum, pass curr. num to next fn.
            
            
            
        }
        
    }
    
    vector<string> addOperators(string s, int target) {
        if(s.length()==0) return ans;
        for(int i=0;i<s.length();i++){
            long num=stol(s.substr(0,i+1));									// Avoid overflows, extract num from substr.
            if(i>0 && stol(s.substr(0,1))==0) break;						// Avoids dups bec. of consec. "0"s, trailing zeroes.
            extractSum(s,i+1,to_string(num),num,num, target);				// Pass curr. num & Call fn. to extract nums.
        }
        
        return ans;															// Returning the final vector of str of char combinations.
    }
};