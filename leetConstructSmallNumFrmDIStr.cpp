/*
*
//******************************************************2375. Construct Smallest Number From DI String.******************************************************

https://leetcode.com/problems/construct-smallest-number-from-di-string/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"IIIDIDDD"
"IIDDIDDD"
"DDD"
"IIIDIDDD"
"IIIDDII"
"IDIIDDD"
"IDIDDD"
"DIDDD"
"DDIDDIII"
"DIIDIID"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Based on the observation that conse. 'I' lead to consec. chars getting appended to res, while conse. 'D' would lead
// to their count+1 chars getting appended in reverse order(Dec. order). We append number if we have "I" at the first or at the end.







class Solution {
public:
    string smallestNumber(string s) {
        string res="";
        int maxm=s.length()+1, i=s.length()-1;
        while(i>=0) {
            int cnt=0;
            if(s[i]=='D') {
                while(i>=0 && s[i]=='D') cnt++, i--;						// Counting #Ds
                int temp=cnt+1;
                while(cnt>=0) res+=(maxm-cnt)+'0', cnt--;					// Appending #Ds+1 chars in reverse order.
                maxm-=temp;
                // cout<<"temp after D: "<<res<<endl;
            } else {
                if(i==s.length()-1) cnt++;									// Append an extra num, if we have 'I's on both ends of the string.
                while(i>=0 && s[i]=='I') cnt++, i--;						// Counting #Is
                if(cnt==1) continue;										// If there is only 1 'I', ignore it.
                cnt--;
                while(cnt>0) res+=(maxm)+'0', maxm--, cnt--;				// Appending #Is chars.
                // cout<<"temp after I: "<<res<<endl;
            }
        }
        if(s[0]=='I') res+=(maxm)+'0';										// Append an extra num, if we have 'I's on both ends of the string.
        reverse(res.begin(), res.end());									// Reversing the entire string.
        return res;															// Returning the Smallest Number string.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack and Observation based. Here, we store the chars in a stack when we encounter 'D' and pop them out when we encounter 'I' and add
// curr. char to stack now, we ensure that curr. char gets added to stack at the end of curr. iter, thus we get 'D's+1 chars in stack when we encounter 'I'
// adjacent to 'D's and we add them to res. At the end of iter. we will have some extra chars in stack maybe because of 'I' or consec. 'D's, we pop them out 
// and add to res.







class Solution {
public:
    string smallestNumber(string s) {
        string res="";
        stack<char>st;
        char ch='1';
        st.push(ch);														// We add extra char first and also ensure to add one char per index of the string.
        for(int i=0;i<s.length();i++) {
            ch++;
            if(s[i]=='I') {
                while(!st.empty()) {										// We pop chars related to prev. 'D's, probably one single 'I' before them and add to res. 
                    res+=st.top();
                    st.pop();
                }
                st.push(ch);												// Adding curr. char to stack.
            }else st.push(ch);												// Adding 'D' corresponding char to stack.
        }
        while(!st.empty()) {												// Pop rem. chars from stack and add to res.
            res+=st.top();
            st.pop();
        }
        return res;															// Returning the Smallest Number string.
    }
};

