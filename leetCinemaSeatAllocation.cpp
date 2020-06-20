/*
*
//************************************************1386. Cinema Seat Allocation.***********************************************

https://leetcode.com/problems/cinema-seat-allocation/description/


A cinema has n rows of seats, numbered from 1 to n and there are ten seats in each row, labelled from 1 to 10 as shown in the figure 
above.

Given the array reservedSeats containing the numbers of seats already reserved, for example, reservedSeats[i] = [3,8] means the seat 
located in row 3 and labelled with 8 is already reserved.

Return the maximum number of four-person groups you can assign on the cinema seats. A four-person group occupies four adjacent seats in 
one single row. Seats across an aisle (such as [3,3] and [3,4]) are not considered to be adjacent, but there is an exceptional case on 
which an aisle split a four-person group, in that case, the aisle split a four-person group in the middle, which means to have two people 
on each side.

 

Example 1:



Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
Output: 4
Explanation: The figure above shows the optimal allocation for four groups, where seats mark with blue are already reserved and 
contiguous seats mark with orange are for one group.
Example 2:

Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
Output: 2
Example 3:

Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
Output: 4
 

Constraints:

1 <= n <= 10^9
1 <= reservedSeats.length <= min(10*n, 10^4)
reservedSeats[i].length == 2
1 <= reservedSeats[i][0] <= n
1 <= reservedSeats[i][1] <= 10
All reservedSeats[i] are distinct.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


3
[[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
2
[[2,1],[1,8],[2,6]]
4
[[4,3],[1,4],[4,6],[1,7]]



// Time Complexity: O(m).													// m- #blocked seats, n- #rows in the cinema.
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m).													// m- #blocked seats, n- #rows in the cinema.
// Space Complexity: O(n).	
// This algorithm is Binary representation based. Here, we store the reserved seats in a map, where key is the row num., we mark the
// booked seats by setting their psn bit in the map key's val. We iter. over entire map, we extract which of the three desired sets
// are available, if far two are available, we can accomodate 2 four person group. If they are not free any of three sets is available, 
// we can accomodate 1 group. We add all those rows in which there are no reserved seats to the final cnt and we return final cnt.








class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& v) {
        unordered_map<int,int>booked;
        for(int i=0;i<v.size();i++){										// Iter. over reserved seats.
            int row=v[i][0], psn=v[i][1];
            booked[row]|=(1<<(psn-1));										// Storing booked seats in their binary rep.
        }
        int res=(n-booked.size())*2;										// Adding contri. from all rows with no reserved seats.
        // cout<<"res: "<<res<<endl;
        for(auto it:booked){												// Iter. over all rows with reserved seats.
            int row=it.first, rep=it.second;
            int psn1=0, psn2=0, psn3=0;										// Says whether three desired sets are avail. or not.
            psn1=(rep & (0b0111100000));									// Finding whether first set if avail. or not.
            psn2=(rep & (0b0001111000));
            psn3=(rep & (0b0000011110));
            if(psn1==0 && psn3==0) res+=2;									// If far sets are avail. we can accom. 2 groups.
            else if(psn1==0 || psn2==0 || psn3==0) res+=1;					// If far sets aren't avail and any set is avail, we set 1 group.
        }
        return res;															// Returning the total #groups accomodated.
    }
};

