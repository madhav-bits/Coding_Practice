/*
*
//******************************************************************Scores.*********************************************************

https://www.interviewbit.com/problems/scores/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



5 6 7 8 9 10
5 1 2 3 4 5



6 1 5 9 12 29 30
4 2 8 14 29



6 5 8 9 12 29 30
4 2 8 14 29



3 1 2 3
3 1 2 3



4 2 5 3 2
4 1 5 6 2




// Time Complexity: O(nlogn+mlogm).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+mlogm).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we iterate through the throw distances and mark it as Bonus Dist. Now, we calcualte scores for 
// both teams and try to udpate the max. score diff var, similarly also udpate each team's scores that contribute to maxm score diff. The main
// issue in this problem is that, there are lot of edge cases to watch out for. Those edge cases are specifically pointed out in the below
// code's comments.








vector<int> Solution::solve(vector<int> &u, vector<int> &v) {
    vector<int>ans;															// Result vector.
    sort(u.begin(), u.end());												// Sorting distances of both the teams.
    sort(v.begin(), v.end());
    int score1=3*u.size();													// Scores of both teams if Bonus Dist. is at -1.
    int score2=3*v.size();
    int res=score1-score2;													// Tracks the max. dist. diff.
    ans.push_back(score1);
    ans.push_back(score2);
    int ind1=0, ind2=0;														// Init. indices for both arrays for iteration.
    while(ind2<v.size() && u[0]>v[ind2]){									// This covers case, min. dist of Team2 is smaller than Team1 min dist.
        score1=2*(ind1)+3*(u.size()-ind1);									// Bonus dist. is on the Team2's dist. which are < Team1's min. dist.
        score2=2*(ind2+1)+3*(v.size()-ind2-1);
        // cout<<"Updating here. score1: "<<score1<<" and score2: "<<score2<<endl;
        if(score1-score2>res){
            ans[0]=score1;
            ans[1]=score2;
            res=score1-score2;
        }
        ind2++;
    }
    while(ind2<v.size()){													// This covers case, where Bonus Dist. is in b/w Team1 scores.
        // score2=2*(ind2+1)+3*(v.size()-ind2-1)+1;
        score2=2*(ind2)+3*(v.size()-ind2);
        // cout<<"Current ind2: "<<ind2<<" and score2: "<<score2<<endl;
        while(ind1<u.size() && u[ind1]<=v[ind2]){							// Iter. over Team1 scores, until it's score is >Team2 index's score.
            score1=2*(ind1)+3*(u.size()-ind1);
            if(score1-score2>res){											// Calc. scores at each point and update the  max. diff. dist.
                ans[0]=score1;
                ans[1]=score2;
                res=score1-score2;
            }
            // cout<<"ind1: "<<ind1<<" score1: "<<score1<<" and score2; "<<score2<<endl;
            ind1++;															// Iter. over Team1's scores.
        }
        ind2++;																// Iter. over Team2's scores.
    }
    // cout<<"ind1: "<<ind1<<" and ind2: "<<ind2<<endl;
    if(ind1<u.size() && u[ind1]>v.back()){									// This Covers case, where few dist. of Team1 are >Max. Team2 dist.
        score1=2*(ind1)+3*(u.size()-ind1);
        score2=2*v.size();
        if(score1-score2>res){
            ans[0]=score1;
            ans[1]=score2;
            res=score1-score2;
        }
    }
    if(2*u.size()-2*v.size()>res){											// This covers case, where Bonus Dist. is beyond both Teams dist.
        ans[0]=2*u.size();
        ans[1]=2*v.size();
    }
    // cout<<"max. diff: "<<res<<endl;
    return ans;																// Returning the max. possible diff. in scores.
}
