/*
*
//***************************************************1694. Reformat Phone Number.******************************************************

https://leetcode.com/problems/reformat-phone-number/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


"1-23-45 6"
"1-23-45 67"
"1-23-45 678"
"1-23-45 6789"
"23456"



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, we iter. over intital string and form the revised string of digits. Now, we form digits
// blocks of size 3, until there are atleast 4 rem. chars. We adjust the rem. chars as per the question's requirement.








class Solution {
public:
    string reformatNumber(string s) {
        string res="";
        int j=0, k=0;
        while(k<s.length()){												// Forming revised string.
            if(isdigit(s[k])) s[j++]=s[k];
            k++;
        }
        cout<<s.substr(0,j)<<endl;
        int i=0;
        while(i+4<j){														// Until 4 or less chars are remaining.
            res+=s.substr(i,3)+"-";
            i+=3;
        }
        if(i+3>=j) res+=s.substr(i,j-i);									// If 2 or 3 rem. chars.
        else res+=s.substr(i,2)+"-"+s.substr(i+2,2);						// If 4 rem. chars.
        return res;															// Returning the new string as per the required format.
    }
};