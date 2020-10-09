/*
*
//******************************************************1603. Design Parking System.***************************************************

https://leetcode.com/problems/design-parking-system/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


Worked on the test cases provided with question.



// Time Complexity: O(1).													// Constant time and space.		  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).													// Constant time and space.	
// Space Complexity: O(1).	
// This algorithm is array based. Since, we have three types of slots, we init. a array of size 3, where in each index we store vacancies
// for each of the type of vehicles. On the arrival of a vehicle, if resp. size opening is available, we dec. the cnt, if not we return
// false.








class ParkingSystem {
public:
    vector<int>vacancies;
    ParkingSystem(int big, int medium, int small) {
        vacancies=vector<int>({big, medium, small});						// Init. array with available parking slots.
    }
    
    bool addCar(int carType) {
        if(vacancies[carType-1]==0) return false;							// If no openings in resp. size, we return false.
        vacancies[carType-1]--;												// Assign the vehicle a slot and dec. the cnt of avai. slots.
        return true;														// Return true indicating that parking slot was avaiable.
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */