package CTCI;

import java.util.Arrays;

/*
 * 
 * 1-6) Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 
 * degrees. Can you do this in place?
 * 
 * 
 * 
 * //Time Complexity: O(n^2).
   //Space Complexity: O(1).
 *
 */
 


//Time Complexity: O(n^2).
//Space Complexity: O(1).


// We make the swap, 4 way along the different sides of the array. We store the first value in temp array. Then, do a series of copying. We do this
// until row<len/2. And clmn<len-1-row.



public class ArraysStrings6 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int len=4;
		int [][] v=new int[len][len];
		v[0][0]=1; v[0][2]=1; v[0][3]=1;v[1][0]=1; v[1][1]=1; v[1][2]=1;v[2][3]=1; v[3][0]=1; v[3][1]=1; v[2][1]=1; v[2][2]=1; v[3][3]=1;
		for(int[]row:v) 
			System.out.println(Arrays.toString(row));
		
		for(int i=0;i<len;i++) {
			if(i==len/2) break;
			System.out.println("The row: "+i);
			for(int j=i;j<len-i-1;j++) {
				int temp=v[i][j];							// Temp. storing val at psn 1.
				v[i][j]=v[len-1-j][i];						// 1 copying 4.
				v[len-1-j][i]=v[len-1-i][len-1-j];			// 4 copying 3.
				v[len-1-i][len-1-j]=v[j][len-1-i];			// 3 copying 2.
				v[j][len-1-i]=temp;					  		// 2 copying 1.
				
			}
		}
		System.out.println();
		for(int[]row:v) 
			System.out.println(Arrays.toString(row));
	}

}
