/*
*
//****************************************************************Queen Attack.*********************************************************

https://www.interviewbit.com/problems/queen-attack/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


4 01010 01001 11001 00101




// Time Complexity: O(n*m).  
// Space Complexity: O(n+m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n+m).	
// This algorithm is Dynamic Programming and iteration based. The main issue is that a Knight can't attack by moving over a Knight.So, we iter. 
// over array take two ptrs, one moves towards the end of columns, other moves towards start of column. Later we iter. columns, one ptr moves
// towards end of row, other towards start of row. As diagonals are concerned, as each diagonal have a Unique prop. sum of indices/ row-clmn+first
// row size. We iter. from first row to last row, in this process TLBR, TRBL is covered. Next time, we iter. from last row to first row,
// now BLTR, BRTL is covered. In this process, if the Uniq. property sum is marked as one(A Queen is encount. in this diag.), then we inc. the 
// count of curr. index. Thus, at the end we get the No.of attacks possible at each index.








vector<vector<int> > Solution::queenAttack(vector<string> & v) {
    vector<int>diag1(v.size()+v[0].size()+1),diag2(v.size()+v[0].size()+1);	// Stores presence of Queens on each diagonal
    vector<vector<int>>res(v.size(), vector<int>(v[0].size(),0));			// Final result array.
    // cout<<"size: "<<v.size()<<" and res size: "<<res.size()<<endl;
    int len=v.size()+v[0].size();
    for(int i=0;i<v.size();i++){											// Iter. from first to last row.
        int pres1=0,pres2=0;
        for(int j=0,k=v[0].size()-1;j<v[0].size(); j++,k--){				// Traverse from both drns of coloumn.
            if(pres1==1) res[i][j]++;										// If Queen encount. inc. count of curr. index.
            if(pres2==1) res[i][k]++;
            if(v[i][j]=='1') pres1=1;										// If Queen encount. mark as present.(L->R).
            if(v[i][k]=='1') pres2=1;										// Trav. form (R->L).
        }
    }
    
    for(int j=0;j<v[0].size();j++){											// Iter. from first to last column.
        int pres1=0,pres2=0;
        for(int i=0,k=v.size()-1;i<v.size();i++,k--){						// Traverse from both drns of rows.
            if(pres1==1) res[i][j]++;
            if(pres2==1) res[k][j]++;
            if(v[i][j]=='1') pres1=1;
            if(v[k][j]=='1') pres2=1;
        }
    }
    
    for(int i=0;i<v.size();i++){											// Traverse from TL BR. Covers TLBR, TRBL drns of diagonals.
        for(int j=0;j<v[0].size();j++){
            if(diag1[i-j+v[i].size()]==1) res[i][j]++;
            if(diag2[i+j]==1) res[i][j]++;
            if(v[i][j]=='1'){
                diag1[i-j+v[i].size()]=1;
                diag2[i+j]=1;
            }
        }
    }
    
    
    diag1=vector<int>(v.size()+v[0].size()+1);
    diag2=vector<int>(v.size()+v[0].size()+1);
    for(int i=v.size()-1;i>=0;i--){											// Traverse from BL TR. Covers BLTR, BRTL drns of diagonals.
        for(int j=0;j<v[i].size();j++){
            if(diag1[i-j+v[i].size()]==1) res[i][j]++;						// If Queen already encount. on this diag. inc. curr. index's count.
            if(diag2[i+j]==1) res[i][j]++;
            if(v[i][j]=='1'){
                diag1[i-j+v[i].size()]=1;
                diag2[i+j]=1;
            }
        }
    }
    // for(auto nums:res){
    //     for(auto num:nums){
    //         cout<<num<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    return res;																// Return the final result vector.
    
}
