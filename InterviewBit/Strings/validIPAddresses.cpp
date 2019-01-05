/*
*
//**************************************************************Valid Ip Addresses.*******************************************************


https://www.interviewbit.com/problems/valid-ip-addresses/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



12121212112



010010



// Time Complexity: O(3^4).													// As, we are forming 4 nums, each with max. length of 3.
// Space Complexity: O(12*(3^4)).											// Time *12, as maxm. space for each num is 3.

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(3^4).													// As, we are forming 4 nums, each with max. length of 3.
// Space Complexity: O(12*(3^4)).											// Time *12, as maxm. space for each num is 3.
// This algorithm is Backtracking/Recursion based. Here, we start iterating from the first index, we as a whole need 4 nums which are [0,255].So,
// here in every step of recursion, we form the num in this range append it to string and give recursive calls to form else nums. While in a 
// recursive call, if #nums formed ==4, then stop iteration, if the curr. num. we are forming is >255, then we stop forming nums and return from 
// call, if the formed num is '0' and gave recursive call, then stop iteration to prevent a '0' prefix. If we end of iteration with 4 formed
// nums, we push the string formed into final result vector of strings.









void findCombi(string &s, int index, int num, string temp, vector<string>&res){
    // if(num>4) return ;
    if(index==s.length()){													// If entire string is iterated.
        temp.pop_back();													// Remove the last char which is '.'
        if(num==4)															// IF 4 nums formed.
            res.push_back(temp);											// Push the string into final result vector.
        return ;															// Stop iteration, as entire string is iterated.
    }   
    if(num==4) return ;														// If 4 nums are formed and string isn't completely iterated, return.
    int addn=0;																// Tracking curr. val formed.
    for(int i=index;i<s.length();i++){										// Iterating over string to form curr. str.
        addn=addn*10+(s[i]-'0');											// Adding curr. char's value to curr. forming value.
        if(addn>255) return ;												// If formed value is>255, return(stop forming).
        findCombi(s,i+1, num+1, temp+to_string(addn)+'.', res);				// Recursive call to form else nums.
        if(addn==0) return ;												// If formed num. is 0, then in next iter. we have '0' prefix, which
																			// isn't allowed, so return.
    }
    
}

vector<string> Solution::restoreIpAddresses(string s) {
    vector<string>res;														// Stores all valid ip addresses.
    findCombi(s, 0, 0, "", res);											// Call to form all possible valid IP addresses.
    return res;																// Return all valid IP addresses.
}
