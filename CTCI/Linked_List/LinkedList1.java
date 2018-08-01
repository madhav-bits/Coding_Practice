package CTCI.Linked_List;
import java.util.*;



/*
 * 
 * 2-1) Write code to remove duplicates from an unsorted linked list.
	FOLLOW UP
	How would you solve this problem if a temporary buffer is not allowed?
 * 
 * 
 * 
 * //Time Complexity: O(n).												
   //Space Complexity: O(1).
 *
 */
 


//Time Complexity: O(n).													
//Space Complexity: O(1).
// We iterate through the LL, if we encounter a value first time, we store it in map, if we have already encoun. value in the next node, we delete
// next node as long as we reach end of LL/val which hasn't been encountered till then.Once, we reach end of LL, we return the root of the new 
// modified LL.




public class LinkedList1 {

	
	static ListNode removeDup(ListNode root) {
		if(root==null || root.next==null ) return root;						// Cases where checking isn't required.
		HashMap<Integer,Integer> m= new HashMap<Integer,Integer>();			// Stores the unique visited nodes.
		ListNode fast=root;	
		m.put(root.val, 1);
		while(fast.next!=null) {											// As long as we have next node to check for duplicate.
			while(fast.next!=null && m.containsKey(fast.next.val)) 			// As long as next is duplicate.
				fast.next=fast.next.next;									// Removing the next node.
			
			if(fast.next==null) break;										// If end of LL is reached.
			m.put(fast.next.val, 1);										// Storing next unique val.
			fast=fast.next;													// Moving to next unique val.
		}
		
		return root;														// Returning the root of new modified LL.
		
	}
	
	static void printLL(ListNode root) {									// Prints the elements of the LL.
		while(root!=null) {
			System.out.println("The node val: "+ root.val);
			root=root.next;
		}
		
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ListNode root= new ListNode(1);
		root.next=new ListNode(2);
		root.next.next=new ListNode(1);
		root.next.next.next= new ListNode(4);
		root.next.next.next.next= new ListNode(5);
		root.next.next.next.next.next= new ListNode(6);
		root.next.next.next.next.next.next= new ListNode(4);
		root.next.next.next.next.next.next.next= new ListNode(9);
		ListNode res= removeDup(root);										// Calling fn. to remove dups in LL.
		printLL(res);														// Calling fn. to print contents of LL.
		
	}

}
