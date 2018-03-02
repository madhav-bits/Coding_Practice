/*
*
//******************************************************241. Different Ways to Add Parentheses.***********************************************

Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and 
operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

"2*1-2+3-4"
"3*2"
"2"
"-2"									// Not testing properly on these test cases starting with '-' sign.



// Time Complexity: O(n!).  			// Not exactly.
// Space Complexity: O(n*n!).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*n!).			// Not exactly.
// Space Complexity: O(n*n!).
// This is Divide and Conquer Algorithm.	
// This algorithm divides the array into two parts, left and right strings, we extract all the possible nums from them, and form various 
// combinations of sums/minus/multiply from them.



class Solution {
public:
    vector<int> findPossib(vector<int> num, vector<char>sign, int start, int finish){
        vector<int> res;
        //cout<<"Start is: "<<start<<" and finish is; "<<finish<<endl;
        if(start>finish) return vector<int>(1,num[start]);					// Only single num. is left in this part.
        vector<int>v,u;
        for(int i=start;i<=finish;i++){										// Choosing a particular sign and dividing based on it.
            u=findPossib(num, sign, start,i-1);								//Extract num. from the left part of signs division.
            v=findPossib(num, sign, i+1,finish);							//Extract num. from the right part of signs division.
            //cout<<"For start: "<<start<<" and finish is; "<<finish<<" u size is: "<<u.size()<<" and v size is: "<<v.size()<<endl;
            for(int a=0;a<u.size();a++){									// Forming various combi. of extracted sums.
                for(int b=0;b<v.size();b++){
                    if(sign[i]=='+') res.push_back(u[a]+v[b]);
                    if(sign[i]=='-') res.push_back(u[a]-v[b]);
                    if(sign[i]=='*') res.push_back(u[a]*v[b]);
                }
            }
        }
        return res;
    }
    
    vector<int> diffWaysToCompute(string s) {
        vector<int> v;
        vector<int> num;
        vector<char> sign;
        int index=0;
        if(s[0]>=48 && s[0]<=57) index=-1;														// If the first index has a num(0 to 9).
        for(int i=0;i<s.length();i++){															// Scanning the array and extracting nums and signs.
            if(s[i]=='+' || s[i]== '-' || s[i]=='*'){
                if(i!=index)
                    num.push_back(stoi(s.substr(index+1,i-index)));								//Extracting the nums.
                sign.push_back((s[i]));															// Extracting the signs.
                index=i;
            }
        }
        num.push_back(stoi(s.substr(index+1,s.length()-index)));
        
        if(sign.size()==1 && s[0]=='-') return vector<int>(1,stoi(s.substr(0,s.length())));		// If we have only single sign in the beginning.
        v=findPossib(num,sign,0,sign.size()-1);													// Calling the fn. to get combinations of sums.
        //sort(v.begin(),v.end());																// Order isn't required.
        return v;																				// Returning vector contai. all possib. sum combi.
    }
};
