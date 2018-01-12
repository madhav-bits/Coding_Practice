/*

//**********************************************************376. Wiggle Subsequence.*******************************************************

A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive 
and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is 
trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. 
In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and 
the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by 
deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

Examples:
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2

Credits:
Special thanks to @agave and @StefanPochmann for adding this problem and creating all test cases.


//Time Complexity: O(n).
// Space Complexity: O(n).
//These are the example cases I had worked on.
//[1,7,4,9,2,5,3,5,3,5,2,1,2,1,4]
//[2,37,5,3,4]

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//Follow up:
//Can you do it in O(n) time?


//*****************************************************************Solution 1:*************************************************************
//Time Complexity: O(n^2).
// Space Complexity: O(n^2).

class Solution {
public:
    int wiggleMaxLength(vector<int>& v) {
        int len=v.size();
        if(len==0)
            return 0;
        int arr[len]={0};
        for(int i=0;i<len;i++)						//Initializing to 1, cause every number is part of wiggle sequence of length 1.
            arr[i]=1;
        
        int sign[len]={0};							//Sign 1 indicates that the curr. value is greater than prev. vaalue in wiggle sequence.
        int maxm=1;									//Sign -1 indicates that the curr. value is smaller than prev. vaalue in wiggle sequence.
        for(int i=0;i<len;i++){
            for(int j=0;j<i;j++){					
                if(sign[j]==0){						//If the prev. value is first value of wiggle sequence.
                    if(v[i]>v[j]){
                        arr[i]=max(arr[i], 1+arr[j]);
                        sign[i]=1;
                    }
                    else if(v[i]<v[j]){
                        arr[i]=max(arr[i], 1+arr[j]);
                        sign[i]=-1;
                    }
                }
                
                else if(sign[j]==-1 && v[i]>v[j]){	//If the curr. value is inc. part of wiggle sequence and prev. value is dec. part of-
                   arr[i]=max(arr[i], 1+arr[j]);	//- wiggle sequence.
                    sign[i]=1; 
                }
                else if(sign[j]==1 && v[i]<v[j]){	//If the curr. value is dec. part of wiggle sequence and prev. value is inc. part of-
                   arr[i]=max(arr[i], 1+arr[j]);	//- wiggle sequence.
                    sign[i]=-1; 
                }
                maxm=max(maxm, arr[i]);				//Storing the max. wiggle sequence till then.
            }
        }
        //cout<<"the max. length is: "<<maxm<<endl;
        return maxm;								// Returning the max. length of wiggle subsequence possible in this array.
    }
};


//Follow up:
//Can you do it in O(n) time?
//Yes, we can do by the following algorithm.

//*****************************************************************Solution 2:*************************************************************
//Time Complexity: O(n).
// Space Complexity: O(n).


class Solution {
public:
    int wiggleMaxLength(vector<int>& v) {
        int len=v.size();
        if(len==0)
            return 0;
        int arr[len]={0};
        for(int i=0;i<len;i++)						//Contains the length of wiggle sequence till that index.
            arr[i]=1;
        int sign[len]={0};
        for(int i=1;i<len;i++){
            if(sign[i-1]==0){						//If the prev. value is first value of wiggle sequence.
                if(v[i]>v[i-1]){
                    arr[i]=1+arr[i-1];
                    sign[i]=1;
                }
                else if(v[i]<v[i-1]){				
                    arr[i]=1+arr[i-1];
                    sign[i]=-1;
                }
            }
            else if(sign[i-1]==-1 && v[i]>v[i-1]){	//If the curr. value is inc. part of wiggle sequence and prev. value is dec. part of-
               arr[i]=1+arr[i-1];					//- wiggle sequence.
                sign[i]=1; 
            }
            else if(sign[i-1]==1 && v[i]<v[i-1]){	//If the curr. value is dec. part of wiggle sequence and prev. value is inc. part of-
               arr[i]=1+arr[i-1];					//- wiggle sequence.
                sign[i]=-1; 
            }
            else{
                arr[i]=arr[i-1];
                sign[i]=sign[i-1];
            }    
        }
        //for(const auto& num:arr)
        //    cout<<"The array elements are: "<<num<<endl;
        //cout<<"the max. length is: "<<maxm<<endl;
        return arr[len-1];							// Returning the max. length of wiggle subsequence possible in this array. As it's stored-
    }												//- in the last index of the array.
};