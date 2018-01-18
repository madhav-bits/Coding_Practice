/*
*
//**********************************************************189. Rotate Array.******************************************************

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Related problem: Reverse Words in a String II

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.





//Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
//Time Complexity: O(n).
// Space Complexity: O(n).


class Solution {
public:
    void rotate(vector<int>& v, int k) {
        if(v.size()==0)
            return ;
        int len=v.size();
        k=k%len;
        vector<int> u(len,0);
        for(int i=0;i<len;i++){							//Creating another vector with the rotated psns.
            u[i]=v[(i-k+len)%len];
        }
        v=u;											//Copying the newly created vector to the old vector.
        return;
    }
};




//************************************************************Solution 2:************************************************************
//Time Complexity: O(n^2) .
// Space Complexity: O(1).



class Solution {
public:
    void rotate(vector<int>& v, int k) {
        if(v.size()==0)
            return ;
        int len=v.size();
        k=k%len;
        for(int i=0;i<k;i++){								//Del. and pasting k no. of elements.
            int temp=v[len-1];
            v.erase(v.begin()+len-1);						//Remove an elem. from the end and inserting in the beginning.
            v.insert(v.begin(),temp);
        }
        
        return;
    }
};