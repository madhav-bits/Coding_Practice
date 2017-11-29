/*

//**********************************************************456. 132 Pattern.********************************************************

Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. 
Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.

Note: n will be less than 15,000.

Example 1:
Input: [1, 2, 3, 4]

Output: False

Explanation: There is no 132 pattern in the sequence.
Example 2:
Input: [3, 1, 4, 2]

Output: True

Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:
Input: [-1, 3, 2, 0]

Output: True

Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].


//Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/

//****************************************************THIS IS TRICKY AND TOUGH QUESTION.**************************************

//Solution 1:
//This solution approaches the problem from the right side. In the question what is required n1<n3<n2. index of n1<n2<n3. So, we are just-
//- maintaining the largest two values from the right, So, that it covers all the possible numbers on the left satisfying the above two-
//- conditions.
   
class Solution {
public:
    bool find132pattern(vector<int>& v) {
        int n3=INT_MIN;// Stores the second larget number from the right till the index "i+1".
        stack<int> s;//We approach the 
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]<n3)// If the v[i] is less than n3, then the required sequence is obtained.
                return true;
            else while(!s.empty() && v[i]>s.top()){//If we encountered new largest value, then the n3 and n2 needs to be updated.
                n3=s.top();//n3 is updated to the n2, which is stored in the stack. Although we can maintain only one value i.e: n2-
                s.pop();//-but the code length reduc., all values are pushed.
            }
            s.push(v[i]);//All values are pushed, while updating n2 and n3 in case new largest( new n2) value encountered, new n2 is pushed-
        }//- into stack.
        return false;// If the iteration passed through all iterations, then there is no required sequence.
    }
};

//*********************************************************************************************************************************
//*********************************************************************************************************************************
//*********************************************************************************************************************************

//Solution 2:
//This solution is time consuming, throwing time limit exceeded warnings for the last 6 sixes(90-95 cases).

class Solution {
public:
    bool find132pattern(vector<int>& v) {
        if(v.size()==0)
            return false;
        unordered_map<int, int> m;
        int minm, maxm;
        
        minm=v[0]; maxm=v[0];
        for(int i=1;i<v.size();i++){
            //cout<<"index is: "<<i<<"and the min is: "<<minm<<" and maxm is: "<<maxm<<endl;
            while(i<v.size() && v[i]<minm){
                if(!m.empty() && m[v[i]]==1)
                    return true;
                //if(m.find(v[i])!=m.end())
                //    return true;
                minm=v[i];
                i++;
            }
            if(i>=v.size())
                return false;
            maxm=v[i];
            if(!m.empty() && m[v[i]]==1)
                    return true;
            //cout<<"Update maxm is: "<<maxm<<endl;
            i++;
            while(i<v.size() && v[i]>maxm){
                if(!m.empty() && m[v[i]]==1)
                    return true;
                maxm=v[i];
                i++;
            }
            if(i>=v.size())
                return false;

            //cout<<"min is: "<<minm<<"and the maxm is:"<<maxm<<endl;
            
            for(int j=minm+1; j<maxm;j++)
                m[j]=1;
            
            if(!m.empty() && m[v[i]]==1)
                    return true;
            minm=v[i]; maxm=v[i];
            //for(auto it=m.begin();it!=m.end();it++)
            //    cout<<"key is: "<<it->first<< " and value is: "<<it->second<<endl;
          
            
        }
        
        return false;
    }
};