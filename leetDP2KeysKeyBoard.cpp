/*

//**********************************************************650. 2 Keys Keyboard.*******************************************************

Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the 
minimum number of steps to get n 'A'.

Example 1:
Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
Note:
The n will be in the range [1, 1000].


//Time Complexity: O(n^2).
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//*****************************************************************Solution 1:*************************************************************

//This is the algorithm, I had come up with but I couldn't make the observations regarding the multiples of a number.
//This algorithm had beat ~7.91% of the total submissions.
class Solution {
public:
    int minSteps(int n) {
        int arr[n+1];
        for(int i=0;i<=n;i++)				//Contains the no. of operations to form index number of A's.
            arr[i]=INT_MAX;					//Initializing the array contents to INT_MAX, as we need min. of operations for an index no. of A's.
        arr[1]=0;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){			
                //cout<<"Inside while loop with i: "<<i<<" and j: "<<j<<endl;
                if(i%j==0){					//Those multiples which can form "i" no. fo A's.
                    int rem=i-j;			//More how many A's needed to be created.
                    //int dupli=rem/j;
                    //cout<<"Dupli for j:"<<j<<" and i: "<<i<<" is: "<<dupli<<endl;
                    arr[i]=min(arr[i], arr[j]+1+rem/j);
                }
                    
            }
        }
        //for(auto num:arr)
        //    cout<<"The array elements are: "<<num<<endl;
        return arr[n];						//This contains the no. of operations for "n" no. of A's.
    }
};




//************************************************************Solution 2:************************************************************

//This algorithm is inspired by some other persons, which had observations regarding the multiples included.
//This algorithm exhibits better running time, beats ~35% of the total submissions.

class Solution {
public:
    int minSteps(int n) {
        int arr[n+1];
        arr[1]=0;
        for(int i=2;i<=n;i++){
            arr[i]=i;
            for(int j=i-1;j>0;j--){
                //cout<<"Inside while loop with i: "<<i<<" and j: "<<j<<endl;
                if(i%j==0){
                    arr[i]=min(arr[i], arr[j]+i/j);
                    break;
                }
                    
            }
        }
        //for(auto num:arr)
        //    cout<<"The array elements are: "<<num<<endl;
        return arr[n];
    }
};