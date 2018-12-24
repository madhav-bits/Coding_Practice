/*
*
//********************************************************Smallest Multiple With 0 and 1.*************************************************

https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



67


101010


112


0


3



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is BFS based. Here, we start from digit '1', on to it's remainder we add '0' and '1', we calculate their remainder and 
// keep on adding until the remainder is 1. If we get remainder 'x' as remainder, then we take '(x*10)%num'/'((x*10)%num+1)%num' into next 
// round, instead of forwarding whole number that we had used till now, as that would redundant information, we just need remainder after 
// dividing ints used till this stage. During the process, we store the digit 1/0 used in the curr. stage of BFS to get curr. remainder, we also
// track relation b/w consecutive remainders, as they are unique and used while backtracking whole digit. 
// Once, remainder of 0 is obtained, we start backtracking process.



// Time Complexity is O(n) as we face only remainders from 0 to num-1, if we face already encountered values, then we don't push them into queue. 
// So, we encounter atmost (2*num) values.





string extractStr(vector<int>&parent, int num1, vector<char>&val){			// Traces ditits back to start-the dividing digit.
    string temp="";															// Stores the digit.
    while(num1!=1){															// Until first digit is found.
        // cout<<"curr. num: "<<num1<<" and val: "<<val[num1]<<endl;
        temp+=val[num1];													// The 0/1 digit used in this stage of BFS.
        num1=parent[num1];													// Finding the parent remainder to curr. stage of BFS.
    }
    temp+=to_string(1);														// Adding the first digit '1'.
    reverse(temp.begin(), temp.end());
    return temp;
}


string Solution::multiple(int num) {
    if(num==1) return "1";
    vector<int>parent(num, -1);												// Tracks rln b/w remainders of consecutive stages of BFS.
    vector<char>val(num, '-1');												// Tracks rln b/w remainder and digit(0/1) used for that num in the stage.
    queue<long int>q;														// Stores nums whose rem. need to be calc. and which forms new nums and
    q.push(1l);																// forwards to next stage.
    while(!q.empty()){
        int curr=q.front();													// Extracting curr. remainder.
        q.pop();
        // if(curr==0) return extractStr(parent, curr, val);				// Can be used here also.But it brings in unnecc. calc. into scene.
        long int num1=(curr*10)%num;										// Calc. next stage values.
        long int num2=(num1+1)%num;//(curr*10)%num
        // cout<<"curr: "<<curr<<" and num1: "<<num1<<" and num2: "<<num2<<endl;
        if(parent[num1]==-1){												// If next stage are observed first time, push to queue.
          q.push(num1);
          parent[num1]=curr;												// Link it to curr. remainder/num.
          val[num1]=0+'0';													// Store the rln b/w new remainder and digit 0/1 used for it.
          // cout<<"num1: "<<num1<<endl;
        } 
        if(parent[num2]==-1){
          q.push(num2);
          parent[num2]=curr;
          val[num2]=1+'0';
          // cout<<"num2: "<<num2<<endl;
        } 
        if(num1==0) return extractStr(parent,num1, val);					// If remainder '0' found, backtrack path to first BFS stage.
        if(num2==0) return extractStr(parent,num2, val);					// If remainder '0' found, backtrack path to first BFS stage.
    }
    return "";																
}
