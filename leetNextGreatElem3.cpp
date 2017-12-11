/*

//*******************************************************556. Next Greater Element III.**************************************************

Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits 
existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

Example 1:
Input: 12
Output: 21

Example 2:
Input: 21
Output: -1

// Example: Test cases on which I had worked on.
//1423423452
//134234521
//1263321
//12364421


//Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/


//Solution 1:
// The main logic is that, we reverse the last decreasing substring, and swap the integer before it with the closest greater value in-
//- the reversed largest substring.
 
class Solution {
public:
    int nextGreaterElement(int n) {
        long int a;
        string s,t;
        s=to_string(n);
        //cout<<"string is: "<<s<<endl;
        int i=0,b=-1;
        while(i<s.length()-1){						//Finding the index of the last decreasing substring.
            if(s[i]<s[i+1])
                b=i;
            i++;
        }
        if(b==-1)									// If a dec. substring is not found returning -1.
            return -1;
        //cout<<"index is: "<<b<<endl;
        reverse(s.begin()+b+1, s.end());			//Reversing the elements in the last dec. substring.
        //cout<<"string is: "<<s<<endl;
        int j=b+1;
        while(j<s.length()){						//Finding the closest value greater than the integer just before the largest dec. substring.
            if(s[b]<s[j]){
                swap(s[b], s[j]);
                break;
            }
            j++;
        }
        a=stol(s);									//Converting the string to integer back.
        return (a>INT_MAX)?-1:a;			
    }
};