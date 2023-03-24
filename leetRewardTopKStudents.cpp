/*
*
//******************************************************2512. Reward Top K Students.******************************************************

https://leetcode.com/problems/reward-top-k-students/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["smart","brilliant","studious"]
["not"]
["this student is studious","the student is smart"]
[1,2]
2
["smart","brilliant","studious"]
["not"]
["this student is not studious","the student is smart"]
[1,2]
2



// Time Complexity: O(n+m+l+k*logn).																	// m-#pos.feedback, l-#neg.feedback, n-#reports.
// Space Complexity: O(n+m+l).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m+l+k*logn).																	// m-#pos.feedback, l-#neg.feedback, n-#reports.
// Space Complexity: O(n+m+l).	
// This algorithm is Priority Queue+Map based. We store the positive, negative feedback words in map to search in constant time. We iter. over all reports and calc. scores for each of them and append
// scores, indices as a pair into PQ. We extract the top K elements and add them to res array and return it.





class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& ids, int k) {
        unordered_set<string>positive, negative;
        for(string&s:positive_feedback) positive.insert(s);
        for(string&s:negative_feedback) negative.insert(s);
        
        auto comp=[](pair<int,int>& lt, pair<int,int>& rt) {											// PQ definition where it keeps the entries with higher score on top, lesser ids(if equal scores).
            if(lt.first!=rt.first) return lt.first<rt.first;
            return lt.second>rt.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)>pq(comp);					// Defining PQ.
        
        for(int i=0;i<report.size();i++) {
            stringstream ss(report[i]);
            string temp="";
            int score=0;
            while(ss>>temp) {
                if(positive.count(temp)==1) score+=3;
                else if(negative.count(temp)==1) score-=1;
            }
            // cout<<"score: "<<score<<endl;
            pq.push({score, ids[i]});																	// Pushing {score, id} to PQ.
        }
        vector<int>res;
        while(k) {																						
            res.push_back(pq.top().second);																// Adding top K entries's ids to PQ.
            pq.pop();
            k--;
        }
        return res;
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m+l+n*logn).																	// m-#pos.feedback, l-#neg.feedback, n-#reports.
// Space Complexity: O(n+m+l).	
// This algorithm is Sorting based. We store the positive, negative feedback words in map to search in constant time. We iter. over all reports and calc. scores for each of them and append
// scores to array. We take the indices in another array, sort it based on the requirement(non-decreasing scores, increasing ids in case of equal scores of corresponding indices). We take the 
// first K entries/indices from the array and push it's corresponding index to res array and return it.

// Here, instead of taking of an id array, we could have taken {scores, ids} in an array and sort it as per requirement and taken first k entries's id values. Which is applied in the first sln.







class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& ids, int k) {
        unordered_set<string>positive, negative;
        for(string&s:positive_feedback) positive.insert(s);
        for(string&s:negative_feedback) negative.insert(s);
        
        vector<int>scores;
        for(string&s:report) {
            stringstream ss(s);
            string temp="";
            int score=0;
            while(ss>>temp) {
                if(positive.count(temp)==1) score+=3;
                else if(negative.count(temp)==1) score-=1;
            }
            // cout<<"score: "<<score<<endl;
            scores.push_back(score);
        }
        vector<int>indices,res;
        for(int i=0;i<scores.size();i++) indices.push_back(i);
        auto comp=[&scores, &ids](int lt, int rt) {														// Sort the indices array based on it's corresponding scores, ids.
            if(scores[lt]!=scores[rt]) return scores[lt]>scores[rt];
            return ids[lt]<ids[rt];
        };
        sort(indices.begin(), indices.end(), comp);
        for(int i=0;i<indices.size() && k;i++, k--) {
            res.push_back(ids[indices[i]]);																// We take the ids corresponding to curr. index and add it to res array.
        }
        return res;																						// Returning the top K ids as per the given requirement.
    }
};



