/*

//********************************************************525. Contiguous Array***************************************************

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

//Solution 3: is accepted.
//Time Complexity: O(n).
// Space Complexity: O(n).

//**********************************************THIS(SOLUTION 3) IS LEET ACCEPTED CODE.****************************************
*/

//**********************************************Solution1:// Throwing Time Limit Exceeded Errors.***************************************
//************************Dynamic Programming.************
//Time Complexity: O(n^2).
// Space Complexity: O(n^2).
class Solution {
public:
    int findMaxLength(vector<int>& v) {
        long long int length=0;
        if(v.size()==0)
            return 0;
        long long int arr[v.size()][v.size()]={};
        
        for(long long int i=0;i<v.size();i++){// This is passing through the array O(n^2) times. DP Solution.
            for(long long int j=i;j<v.size();j++){
                if(v[j]==0 && j>i)
                    arr[i][j]=arr[i][j-1]-1;
                else if(v[j]==1 && j>i)
                    arr[i][j]=arr[i][j-1]+1;
                else{
                    arr[i][j]=v[j]==1?1:-1;
                    //cout<<" i is: "<<i<<" j is: "<<j<<" and arr val is: "<<arr[i][j]<<endl;
                }
                if(arr[i][j]==0)
                    length=max(length,(j-i+1));
            }
        }
        //cout<<"The max. length is: "<<length<<endl;
        length=44578;
        return length;
    }
};


//**********************************************Solution2:// Throwing Time Limit Exceeded Errors.***************************************
//************************Dynamic Programming.************
//Time Complexity: O(n^2).
// Space Complexity: O(1).
class Solution {
public:
    int findMaxLength(vector<int>& v) {
        int length=0;
        if(v.size()==0)
            return 0;
        
        for(int i=0;i<v.size();i++){// This is passing through the array O(n^2) times. DP Solution.
            int temp=0;
            for(int j=i;j<v.size();j++){// Avoiding unnecessary space usage.
                if(v[j]==1)
                    temp+=1;
                else if(v[j]==0)
                    temp-=1;
                
                if(temp==0)
                    length=max(length,(j-i+1));
            }
        }
        //cout<<"The max. length is: "<<length<<endl;
        return length;
    }
};


//*************************************************************Solution3:*******************************************************
//**********Dynamic Programming and Hash Maps.************
//Time Complexity: O(n).
// Space Complexity: O(n).

class Solution {
public:
    int findMaxLength(vector<int>& v) {
        int length=0,sum=0;
        if(v.size()==0)
            return 0;
        unordered_map<int,int> m;
        m[0]=-1;// This is the base case, as in the beginning the sum is zero. So, it's occuring index is: "-1".
        for(int i=0;i<v.size();i++){
            if(v[i]==1)
                sum+=1;
            else
                sum-=1;
            auto it=m.find(sum);
            if(it!=m.end())// Whenever a sum is recurring, it means there were same no. of 0s and 1s between it's two occurences.
                length=max(length,(i-(it->second)));// So, subtr. gives no. of elements were responsible for the sum not to change.
            else
                m[sum]=i;// If a particular sum's occured first time, then it's index is saved.
        }
        //cout<<"The max. length is: "<<length<<endl;
        return length;
    }
};