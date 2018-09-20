/*
*
//**************************************************************Excel Column Title.*******************************************************


https://www.interviewbit.com/problems/excel-column-title/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.




1


25


26


27

676


675


677


35231


35232


35230



// Time Complexity: O(logn/logn10).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(logn/logn10).
// Space Complexity: O(1).	
// This algorithm is iteration/division based. we start extracting chars from the back. We first curr. char and forward the curr. num-curr. char
// for the next iteration. Thus, we get the required chars in reverse order, we reverse the chars and return it.








string Solution::convertToTitle(int num) {
    string s="";															// Final result string.
    int divi=26;															// Curr. dividing num.
    while(num>0){															// Till all chars are extracted.
        int temp=num%divi;													// Extr. curr. char's num.
        // cout<<"num: "<<num<<" and divi: "<<divi<<" and rem: "<<temp<<endl;
        if(temp==0) temp=divi;												// If curr. char is 0, assign it to 26('Z').
        int rem=temp/(divi/26);												// Extracting curr. char.
        // cout<<"rem: "<<rem<<endl;
        s+=(rem+64);														// Adding curr. char to final result string.
        num=num-temp;														// Forward rem. num to next iter.
        divi*=26;															// Inc. the divisor.
    }
    // cout<<"string: "<<s<<endl;
    reverse(s.begin(), s.end());											// Reversing the obtained string.
    return s;																// Returning the string.
}
