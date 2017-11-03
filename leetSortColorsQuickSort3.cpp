/*
75. Sort Colors

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, 
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

//*********************************************	THIS IS LEET ACCEPTED CODE.*****************************************************
// This code is basically extended version of Quick Sort for three variables.

*/
class Solution {
public:
    void sortColors(vector<int>& v) {
        int ptr1=-1, ptr2=-1, len=v.size();
        for(int i=0;i<len;i++){
            if(v[i]==0){
                swap(v[ptr1+1], v[i]);
                if(v[i]==1)
                    swap(v[ptr2+1], v[i]);
                ptr1+=1;
                ptr2+=1;
            }
            else if(v[i]==1){
                swap(v[ptr2+1], v[i]);
                ptr2+=1;
            }
            /*
            for(int i=0;i<len;i++)//********** Used to check the arrangement after every pass.
                cout<<v[i]<<" "; cout<<endl; 
            cout<<"After index: "<<i<<" ptr1 is: "<<ptr1<<" ptr2 is: "<<ptr2<<endl;
            */
        }
        //for(int i=0;i<len;i++)//************ Prints the given array sequence after the entire operation.
         //   cout<<v[i]<<endl;
    }
};