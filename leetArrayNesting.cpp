/*
*
//**************************************************************565. Array Nesting.******************************************************

A zero-indexed array A of length N contains all integers from 0 to N-1. Find and return the longest length of set 
S, where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.

Suppose the first element in S starts with the selection of element A[i] of index = i, the next element in S should be A[A[i]], and 
then A[A[A[i]]]… By that analogy, we stop adding right before a duplicate element occurs in S.

Example 1:
Input: A = [5,4,0,3,1,6,2]
Output: 6
Explanation: 
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

One of the longest S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
Note:
N is an integer within the range [1, 20,000].
The elements of A are all distinct.
Each element of A is an integer within the range [0, N-1].


//These are the examples I had created, tweaked and worked on.
[5,4,3,2,1,0,5]




// Time Complexity: O(n).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).			
// This iterates through the array, forms the sequence as mentioned in the question. My algorithm stores seq. starting from each index. And gets
// the value of sequence starting at an index using queue and arrays. Where as in real max. length is all is asked in the question. We can just
// get that using a vector and storing all the indices you had already iterated. ALL THE MEMBERS OF SEQUENCE ENDING WITH DUPLICATE ELEM. WILL
// HAVE THEIR OWN SEQUENCE LENGTH < THE CURRENT SEQ. THEY ARE IN. AS, THEY FOLLOW THE DUP. ELEM ENCOUNTERED NOW. 
// MY ALGORITHM IS GENERIC ONE. I had almost solved same as the given one in slns. But, one small observation and improvement is missing.


class Solution {
public:
    int arrayNesting(vector<int>& v) {
        vector<int>dp(v.size(),0);
        int maxm=INT_MIN;
        for(int i=0;i<v.size();i++){
            //cout<<"Index i: "<<i<<endl;
            map<int,int> m;
            int elem=v[i], length=0;
            queue<int> q;
            while(dp[i]==0 && m[elem]==0){
                m[elem]=1;
                q.push(elem);
                elem=v[elem];
                length++;
                if(m[elem]==1){
                    //cout<<"matched with index i: "<<i<<" and elem: "<<elem<<endl;
                    while(q.front()!=elem){
                        dp[q.front()]=length;
                        maxm=max(maxm,dp[q.front()]);
                        m.erase(q.front());
                        q.pop();
                        length--;
                    }
                    while(!q.empty()){
                        dp[q.front()]=length;
                        maxm=max(maxm,dp[q.front()]);
                        m.erase(q.front());
                        q.pop();
                    }
                    //m.clear();
                    break;
                }
                
                /*												//This handles when the index to be accessed is greater than v.size().
                else if(elem>=v.size()){
                    while(!q.empty()){
                        dp[q.front()]=length;
                        maxm=max(maxm,dp[q.front()]);
                        m.erase(q.front());
                        q.pop();
                        length--;
                    }
                    //m.clear();
                    break;
                }
                */
                
            }
            
        }
        
        
        return maxm;										// Return the length of max. sequence.
    }
};





//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).			
// This algorithm is same as the one I designed, but performs well execution wise, as it's not dealing with removing and placing elem. in map
// and queries.





class Solution {
public:
    int arrayNesting(vector<int>& v) {
        vector<int>dp(v.size(),0);
        int maxm=INT_MIN;
        vector<bool>res(v.size(),false);
        for(int i=0;i<v.size();i++){
            int elem=v[i], count=0;
            if(res[elem]) continue;
            while(!res[elem]){
                res[elem]=1;
                elem=v[elem];
                count++;
            }
            maxm=max(maxm,count);
        }
            
        return maxm;
    }
};