/*

//*****************************************************646. Maximum Length of Pair Chain.****************************************************

You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select 
pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
Note:
The number of given pairs will be in the range [1, 1000].


//Time Complexity: O(n).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/

// Solution 1: 
//Time Complexity: O(n).
// Space Complexity: O(n).
//As we have to not include First and Last elements at the same time, we will make two vectors (v.begin(), v.end()-1) && (v.begin()+1, v.end())-.
//-Two vectors one excludes the first and the other vector excludes the last one.
//Two algorithms used to solve the question.
class Solution {
public:
    static bool comparator(vector<int> u, vector<int> v){
        if(u[0]<v[0])
            return 1;
        else if(u[0]==v[0] && u[1]<v[1])
            return 1;
        else
            return 0;
    }
    
    int findLongestChain(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), comparator);
        //for(const auto& num:v)
            //cout<<" Elem1 is: "<<num[0]<<" and num2 is: "<<num[1]<<endl;
        int arr[v.size()]={0};
        for(int i=0;i<v.size();i++)
            arr[i]=1;
        int max_len=INT_MIN;
        for(int i=1;i<v.size();i++){							// Scanning through all the elem.
            for(int j=0;j<i;j++){								//If the earlier's elem's end is smaller than curr's begin, then the curr.
                if(v[j][1]<v[i][0])								//- can be part of chain.
                    arr[i]=max(arr[i], arr[j]+1);				//As it can be part of chain, Chain length till here is updated.
                //cout<<"arr[i] value is: "<<arr[i]<<" with index i: "<<i<<endl;
                max_len=max(max_len, arr[i]);					//Max len of all possible Chain's possibles till now.
                //cout<<"Max length till index i: "<<i<<" is: "<<max_len<<endl;
            }
        }	
        return max_len;											//Returning the max. len of all possible Chains.
    }
};




//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
// Solution 2:
//Time Complexity: O(n).
// Space Complexity: O(1).
//This is other algorithm which uses O(1) space and lesser comparisions.


class Solution {
public:
    static bool comparator(vector<int> u, vector<int> v){					// Sorting the vector pairs in inc. order of their beginnings.
        if(u[1]<v[1])
            return 1;
        else if(u[1]==v[1] && u[0]<v[0])
            return 1;
        else
            return 0;
    }
    
    int findLongestChain(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), comparator);								// Sorting the vector pairs in inc. order of their beginnings.
        //for(const auto& num:v)
            //cout<<" Elem1 is: "<<num[0]<<" and num2 is: "<<num[1]<<endl;
        int arr[v.size()]={0};												//Saves the len.  value upto index "i".
        for(int i=0;i<v.size();i++)											// Initializing  the zero index  value.
            arr[i]=1;
        int max_len=1;
        vector<int> temp(v[0].begin(), v[0].end());							//Saves the chain's end upto an index "i".
        for(int i=1;i<v.size();i++){
            if(v[i][0]>temp[1]){											//If the curr. vec. pair[begin] is more than temp's end, then-
                temp[0]=v[i][0];											//- the curr. value is included in the chain.
                temp[1]=v[i][1];
                max_len+=1;													// Chain length is updated.
            }
        }
        return max_len;														// Returning the chain length.
    }
};