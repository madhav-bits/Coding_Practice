/*

//*******************************************************560. Subarray Sum Equals K.*****************************************************

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].



//Time Complexity: O(n).
// Space Complexity: O(n).

//****************************************************THIS IS LEET ACCEPTED CODE.**********************************************
*/
//Done using Hash Maps.


class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        vector<int> u;
        map<int, int> m;
		m[0]=1;
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            u.push_back(sum);
        }
        
        int count =0;
        for(int i=0;i<u.size();i++){
            //cout<<"Inside main in conditon with index value: "<<i<<" with count is: "<<count<<endl;
            //if(u[i]==k)//As I am including m[0]=1 in the 29th line, we can ignore this case.
             //   count+=1;//Case when sum starting from index 0 equals k, as there is no occurence of zero recorded by then.
            //cout<<"value of m[u[i]-k] is: "<<m[u[i]-k]<<endl;
            if(m[u[i]-k]>=1 ){
                //cout<<"Inside if with index: "<<i<<"count is: "<<count<<endl;
                count+=m[u[i]-k];//ADDING NO. OF OCCURENCES OF (u[i]-k),AS THOSE ARE THE NO. OF SEQUENCES SUMMING TO K BY INDEX "I".
            }
            m[u[i]]+=1;// No. of occurences of a particular sum.
        }
        return count;
    }
};