/*
*
//**************************************************************Gas Station.*************************************************************

https://www.interviewbit.com/problems/gas-station/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



2 1 2
2 2 1



6 3 5 2 9 2 3
6 4 3 6 1 4 6






// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Greedy based. Here, we iter. over indices, add up fuel, dist. travelled in the process. Also track the max. deficiency in 
// dist. to fuel in the process. We store the index, where max. deficiency is obtained. So, we start from the next index as a result, as a result
// we get all those deficiency as extra fuel and we can cover all the indices if started from here. We also check if totalFuel< totalCost, then we
// return -1. If no deficiency is observed at any index, we return 0. If not we return (index+1) as result.








int Solution::canCompleteCircuit(const vector<int> &fuel, const vector<int> &cost) {
    int totalFuel=0, totalCost=0;											// Total Dist. need to be covered.
    
    int maxDef=INT_MIN;														// Tracks Max. Diff. in dist to fuel collected from the start.
    int vol=0, dist=0, index=0;												// Sums up vol, dist. collected in the journey.
    for(int i=0;i<fuel.size();i++){											// Iter. over all indices.
        totalFuel+=fuel[i];													// Adding up fuel collected.
        totalCost+=cost[i];
        vol+=fuel[i];														// Tracking the diff. in dist and fuel collected.
        dist+=cost[i];
        if(dist-vol>maxDef){												// If the dist. is too much > fuel, update the deficiency of fuel.
            maxDef=dist-vol;
            index=i;														// Store the index.
        }
    }
    if(totalCost>totalFuel) return -1;										// If totalFuel<totalDist, then we return -1.
    // cout<<"size: "<<fuel.size()<<" and index: "<<index<<endl;	
    if(maxDef<=0) return 0;													// If deficiency wasn't observed at any index.
	return (index+1);														// We start from next to the index, where max. diff. had occured.
}

