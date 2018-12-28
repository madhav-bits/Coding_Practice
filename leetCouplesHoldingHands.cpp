/*
*
//**********************************************************765. Couples Holding Hands.***************************************************

N couples sit in 2N seats arranged in a row and want to hold hands. We want to know the minimum number of swaps so that every couple is sitting 
side by side. A swap consists of choosing any two people, then they stand up and switch seats.

The people and seats are represented by an integer from 0 to 2N-1, the couples are numbered in order, the first couple being (0, 1), the second 
couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).

The couples' initial seating is given by row[i] being the value of the person who is initially sitting in the i-th seat.

Example 1:

Input: row = [0, 2, 1, 3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
Example 2:

Input: row = [3, 2, 0, 1]
Output: 0
Explanation: All couples are already seated side by side.
Note:

len(row) is even and in the range of [4, 60].
row is guaranteed to be a permutation of 0...len(row)-1.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[0,2,1, 3, 5]



[3,2,0,1,7,4,6,5]



[0,8,1,7,2,6,3,5,4,9]




// Time Complexity: O(n^2).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).	
// This algorithm is DFS based. Here, we set pairs from the left, swapping this way would be optimal as we are matching Unique pairs, there are 
// no other possibilities to match all pairs and also swapping doesn't effect it's adjacent pairs in any way. So, after every swap we give 
// recursive call to match later pairs of curr. index, we add that call's result and add curr. swap and return from this call. At the end,
// we return #moves to match all pairs.



// This can also be done in BFS way.






class Solution {
public:
    
    int findMoves(vector<int>&v, int index){
        if(index>=v.size()) return 0;
        int ind=index;	
        while(ind+1<v.size() && v[ind]==v[ind+1]) ind+=2;					// Skipping all matched pairs.
        // cout<<"Inside fn. with index: "<<index<<" and ind: "<<ind<<endl;
        // for(auto num:v) cout<<num<<" ";
        // cout<<endl;
        
        if(ind>=v.size()) return 0;
        for(int i=ind+1;i<v.size();i++){									// Iter. over indices.
            if(i%2==0 && i+1<v.size() && v[i]==v[i+1]) continue;			// If these indices are already matched.
            if(i%2==1 && v[i]==v[i-1]) continue;
            if(v[i]!=v[ind]) continue;										// If this isn't required value.
            swap(v[i], v[ind+1]);											// Swap to index 'ind'.
            return 1+findMoves(v,ind+2);									// Call to match later pairs.
            //swap(v[i], v[ind+1]);
        }
        return 0;
    }
    
    int minSwapsCouples(vector<int>& v) {
        
        vector<int>u;													// This can be skipped also by calculating req. value at every stage in DFS.
        for(auto num:v){													// Modified all odd num. is pairs to num-1(even) to process easily.
            if(num%2==1) u.push_back(num-1);
            else u.push_back(num);
        }
        // for(auto num:u) cout<<num<<" ";
        // cout<<endl;
        return findMoves(u,0);												// Call to find min. #moves.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).	
// This algorithm is Greedy approach based. Here, we set pairs from the left, once a pair is set, we inc. the index and move to next pair(i+=2) 
// and work on it. The Greedy works as swapping two matching vals. doesn't effect other matching in any way. 






class Solution {
public:
    
    int minSwapsCouples(vector<int>& v) {
        int moves=0;
        for(int i=0;i<v.size();i+=2){										// Iter. over all indices.
            int target=v[i]^1;												// Calc. partner/target value.
            if(v[i+1]==target) continue;									// If target is adjacent to curr. then skip the pair.
            moves++;														// Making a move to set curr. pair.
            for(int j=i+1;j<v.size();j++){									// Searching for curr. pair's partner index.
                if(v[j]!=target) continue;									// If. this val. doesn't match partner/target value.
                swap(v[i+1], v[j]);											// Swapping to match curr. pair.
            }
        }
        return moves;														// Return total #moves to match all pairs.
    }
};