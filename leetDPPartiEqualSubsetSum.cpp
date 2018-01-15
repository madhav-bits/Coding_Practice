/*

//******************************************************416. Partition Equal Subset Sum.***************************************************

Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.



//Time Complexity: O(n^2).
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************


class Solution {
public:
    bool canPartition(vector<int>& v) {
        int sum=0, len=v.size();
        for(auto num:v)									//Calculating the sum of the array.
            sum+=num;
        if(sum%2!=0)									//If the sum of array values is odd, then return 0.
            return 0;
        int target=sum/2;
        vector<int>u(sum+1,0);							// Stores whether the sum indicated by index is attainable or not.
        u[0]=1;											// Initializing the zero value, as this sum is attained by default.
        //cout<<"The sum of vector is: "<<sum<<endl;
        for(int i=0;i<len;i++){
            for(int j=target;j>=0;j--){
                /*
                if(u[j]<=i && u[j]>0 && j+v[i]<=sum){	//I had used this logic, but it's using the values which are updated in this iteraiton.
                    //int temp=u[j+v[i]];				//Worked on recitifying error, but still it's not working don't know. 
                    (u[j+v[i]]>0)?u[j+v[i]]:i+1;//u[j+v[i]]=i+1;
                }
                */
                if(j-v[i]>=0 && u[j-v[i]]==1 )
                    u[j]=1;//u[j] || u[j-u[i]];
            }
            if(u[target]!=0)
                return 1;
        }
        
        return 0;
        
    }
};


//************************************************************Solution 2:************************************************************
//This algo. has the error it's using the values which are updated in the current iterations, rectified but still not workig don't know why??
//Time Complexity: O(n^2).
// Space Complexity: O(n^2).

class Solution {
public:
    bool canPartition(vector<int>& v) {
        int sum=0, len=v.size();
        for(auto num:v)
            sum+=num;
        if(sum%2!=0)									//If the sum of array values is odd, then return 0.
            return 0;
        int target=sum/2;
        vector<int>u(sum+1,0);							// Stores whether the sum indicated by index is attainable or not.
        u[0]=1;
        //cout<<"The sum of vector is: "<<sum<<endl;
        for(int i=0;i<len;i++){
            for(int j=0;j<=target;j++){
                
                if(u[j]<=i && u[j]>0 && j+v[i]<=sum){	//I had used this logic, but it's using the values which are updated in this iteraiton.
                    //int temp=u[j+v[i]];				//Worked on recitifying error, but still it's not working don't know. 
                    (u[j+v[i]]>0)?u[j+v[i]]:i+1;//u[j+v[i]]=i+1;
                }
                
            }
			u[v[i]]=i+1;
            if(u[target]!=0)
                return 1;
        }
        
        return 0;
        
    }
};