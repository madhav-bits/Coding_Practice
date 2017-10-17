/*
Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, 
where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:

Input:
[1,2,3]

Output:
2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

//******************************************************THIS IS LEET ACCEPTED CODE.***********************************************
//************************************************ GOT THE LOGIC FROM EXTERNAL SOURCE.********************************************
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&MEDIAN IS THE VALUE WHICH IS AT MINIMUM DISTANCE FROM ALL THE VALUES IN AN ARRAY.&&&&&&&&&&&&&&&&&
*/
class Solution {
public:
    int minMoves2(vector<int>& v) {
        float size=v.size();
        //vector<int> ::iterator it;
        //auto it=v.begin()+size/2;// This stores the address to the mid location.
        nth_element(v.begin(),v.begin()+size/2, v.end());// This partially sorts the array and makes sure that elem. with index<size/2
        int median=v[size/2]; int result=0;// are less then value at size/2 and elem.with index >size/2 more than val at size/2.
        for(int i=0;i<v.size();i++)
            result+=abs(v[i]-median);// Summing up the distance to all the valus from median.
        return result;
    }
};