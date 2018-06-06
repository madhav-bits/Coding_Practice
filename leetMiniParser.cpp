/*
*
//************************************************************385. Mini Parser.******************************************************

Given a nested list of integers represented as a string, implement a parser to deserialize it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Note: You may assume that the string is well-formed:

String is non-empty.
String does not contain white spaces.
String contains only digits 0-9, [, - ,, ].
Example 1:

Given s = "324",

You should return a NestedInteger object which contains a single integer 324.
Example 2:

Given s = "[123,[456,[789]]]",

Return a NestedInteger object containing a nested list with 2 elements:

1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"[123,[456,[789]],123]"


"[123,[456,[789]]]"

"[123,[[789]],123]"

"[123,[[789]]]"


"[]"

"[[][]]"

"[[[]]]"

"[-123,[321,[-789],-0],-123]"

"[-123,[321,[-789],-0],[[]],-123]"




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array, at each step finds the greater following value, also makes sure that duplicates are avoided. Thus includes
// a greater following value and calls the func. to find further greater following values. Thus ,we get increasing subsequences(include only
// whose length is >= 2).








/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger extractList(string &s, int &i){
        // cout<<"Inside the fn. with index: "<<i<<endl;
        NestedInteger ans, temp;
        int val=0, sign=1;												// To store int values and return it.
        for(;i<s.length();i++){											// Continue scanning from caller has left off.
            if(s[i]=='-') sign=-1;										// Set sign for the following int.
            else if(s[i]=='['){											// Marks beginning of a NestedInt list., so we call fn. to extract it.
                i++;
                ans.add(extractList(s,i));
            }
                
            else if(s[i]>=48 && s[i]<=57){								// Extracting int values.
                val=(val*10)+s[i]-48;
            }
            else if(s[i]==',' && s[i-1]!=']'){							// Finished reading int, store those int values in list.
                temp.setInteger(val*sign);								// Create a singl val. containing NestedInt object.
                ans.add(temp);											// Push that obj. into list.
                val=0; sign=1;											// Set to default values.
            }	
            else if(s[i]==']' ){										// Close of curr. list of objects.
                if(s[i-1]>=48 && s[i-1]<=57){							// If you have a int. before ']', then push it into list and return list.
                    temp.setInteger(val*sign);							// Create a singl val. containing NestedInt object.
                    ans.add(temp);										// Push that obj. into list.
                }
                // cout<<"Returning form the fn. with index: "<<i<<endl;
                return ans;												// Return the list.
            }
                  
        }
    }
    
    
    NestedInteger deserialize(string s) {
        NestedInteger temp; 						                  		// Creates a NestedList to return.
        if(s.length()==0) return temp;
        int index=0, val=0, sign=1;
        if(s[index]=='[')													// If you have list of NestedInt objects, call fn. to extract them.
            return extractList(s,++index);
        else {																// If you just have a int in string, then return it.
            if(s[index]=='-') sign=-1;
            for(;index<s.length();index++)
                if(s[index]>=48 && s[index]<=57) val=val*10+s[index]-48;
            temp.setInteger(val*sign);										// create a NestedInt object with the value and return it.
            return temp;
        }
    }
};