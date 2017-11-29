/*

//******************************************************503. Next Greater Element II.**************************************************

Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for 
every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which 
means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
Note: The length of given array won't exceed 10000.


//Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/


//Solution 1:
//As each elem. in stack encountered once, in the worst case(assing. -1) twice. So, time complexity is O(n).
//As stack of size equal to vector "v" might be required. So, space complexity is O(n).
   
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        vector<int> u;
        if(v.size()==0)
            return u;
        for(int i=0;i<v.size();i++)
            u.push_back(INT_MIN);
        stack<int> s,t;//s maintains the v's values and t contains s's index values whose next greater elem. needed to be assigned.
        s.push(v[0]); t.push(0);//Initializing both stacks.
        for(int i=0;i<v.size();i++){
            //cout<<"insdie for with index i: "<<i<<endl;
            while(!s.empty() && i<v.size() && v[i]<=s.top()){//Pushing elem. which are not next great of those in stack.
                //cout<<"insdie first while with index i: "<<i<<endl;
                s.push(v[i]);
                t.push(i);//Noting down indices of all elem. in stack "s".
                i++;
            }
            while(!s.empty() && i<v.size() && v[i]>s.top()){//When next great elem. is found assigning it to those in stack it's next graet.
                //cout<<"insdie second while with index i: "<<i<<" and psn is: "<<t.top()<<endl;
                u[t.top()]=v[i];
                s.pop();//As next great is assigned removing it from stack.
                t.pop();//Parallely removing it's index.
            }
            if(i<v.size()){
                s.push(v[i]);//Pushing newly encountered as it's next great is not enocuntered yet.
                t.push(i);
            }
            
        }
        
        int i=0;
        while(i<v.size()){//Searching for next great. in indices behind the elem's index in "v", searching circular array.
            if(v[i]>s.top()){// When next great is encountered assigning value to it.
                u[t.top()]=v[i];
                t.pop();
                s.pop();
                i--;
            }
            i++;
        }
        
        while(!s.empty()){//Those elem. whose next great is not present in the given vector. So, assigning -1 to them.
            u[t.top()]=-1;
            t.pop();
            s.pop();
        }
        return u;//Returning vector which contains next great to all elem. in the vector "v".
    }
};