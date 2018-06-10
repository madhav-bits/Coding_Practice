/*
*
//**********************************************************93. Restore IP Addresses.***************************************************

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"010010"

"010000"



// Time Complexity: O(n^4).  
// Space Complexity: O(n^4).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^4).
// Space Complexity: O(n^4).	
// This algorithm is DFS based. At each step, we extract a value from the given string, and call the fn. to extract ints from the remaining string.
// If the #ints is 4 and the total string is iterated, then push it into final result vector, if the #ints is 4 and length is<len, then stop recur.
// In a call, we extract values until the int is <=255. We avoid extracting "00" as an int, as it doesn't reflect two chars from string in the 
// final IP address. 






class Solution {
public:
    vector<string>res;													// Final result vector of strings.
    void extractIp(string &s, int start,int count, string &ans){
        //cout<<"Inside the fn. with start: "<<start<<" and count: "<<count<<endl;
        
        if(start==s.length() && count==4){								// If count==4 and total str is iterated, push  ans into vector.
            res.push_back(ans);
        }
        if(count==4) return;											// Stops extraction of further int. from string.
        int i=start, val=0;
        string temp=ans;												// Stores the str, we got from the caller.
        while(i<s.length() ){											// Keep extracing until 255 is reached.
            val=val*10+(s[i]-48);										// Extract curr. index's char.
            if(val>255) break;
            if(ans.length()==0){										// Extracting very first int in IP address.
                ans+=to_string(val);									// As, very first int, doesn't need "." prior to it.
                extractIp(s,i+1,count+1, ans);							// Call next fn. to extract further digits.
            }
            else{
                ans+="."+to_string(val);								// Adding extr. int to IP address string.
                extractIp(s,i+1,count+1, ans);							// Call next fn. to extract further digits.
            }
                
            if(val==0) break;											// Avoids digits starting with 0 other than 0,i.e.,(001).
            ans=temp;													// Restoring str,so that next iterations can use it to make new IP addr str.
            i++;														// Inc. the iterator.
            
        }
       
        
    }
    
    vector<string> restoreIpAddresses(string s) {
        string temp="";													// Init. the IP address string.
        extractIp(s,0,0,temp);    										// Call fn. to extract ints.
        return res;														// Returning the vector of Valid IP addresses.
    }
};