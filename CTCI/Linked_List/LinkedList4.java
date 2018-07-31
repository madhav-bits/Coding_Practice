package CTCI.Linked_List;
/*
 * 
 * 2-4) You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, 
 * such that the 1’s digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.
	EXAMPLE
	Input: (3 -> 1 -> 5) + (5 -> 9 -> 2)
	Output: 8 -> 0 -> 8
 * 
 * 
 * 
 * //Time Complexity: O(n).												
   //Space Complexity: O(n).
 *
 */
 


//Time Complexity: O(n).													
//Space Complexity: O(n).
// Here, we take two lists we add two nums in same psn,we add nums, add carry and shift the carry to next node in both LLs. If one of LLs dones't
// nodes there, just consider only one LL's value. After calc. the entire sum, we reverse the LL and print it.


public class LinkedList4 {
	
	
	static void printLL(ListNode root) {									// Print the contents in LL.
		while(root!=null) {
			System.out.println("The curr. node: "+root.val);
			root=root.next;
		}
		
	}
	
	static ListNode sumLL(ListNode r1,ListNode r2) {						// Extracts sum of two LLs and gives sum in reversed num format.
		ListNode res= new ListNode(-1);										// Dup. root node.
		ListNode fin=res;													// Temp. storing dup root node.
		int carry=0;
		while(r1!=null && r2!=null) {										// When two vals valid.
			System.out.println("The val1: "+r1.val+" and val2: "+r2.val);
			int sum=carry+r1.val+r2.val;									// Calc. the sum.
			System.out.println("The sum is: "+sum);
			res.next=new ListNode(sum%10);									// Creating node with curr. sum.
			carry=sum/10;													// Calc. carry to be passed to next node.
			r1=r1.next;														// Moving to next node.
			r2=r2.next;
			res=res.next;													// Moving to next node 
		}
		
		
		while(r1!=null) {													// When only one LL has valid node.
			int sum=carry+r1.val;
			res.next=new ListNode(sum%10);
			sum/=10;
			res=res.next;
			r1=r1.next;
		}
		
		
		while(r2!=null) {													// When only one LL has valid node.
			int sum=carry+r2.val;
			res.next=new ListNode(sum%10);
			sum/=10;
			res=res.next;
			r2=r2.next;
		}
		
		if(carry>0)															// When last carry is >0, create node for it.
			res.next=new ListNode(carry);
		
		
		
		return fin.next;													// Returning the root of sum LL. 
	}
	
	
	
	static ListNode sum2LL(ListNode r1,ListNode r2) {						// Extracts sum of two LLs in the default version of nums.
		ListNode prev= null;												// Dup. last node.
		int carry=0;
		while(r1!=null && r2!=null) {										// When two vals valid.
			System.out.println("The val1: "+r1.val+" and val2: "+r2.val);
			int sum=carry+r1.val+r2.val;									// Calc. the sum.
			System.out.println("The sum is: "+sum);
			ListNode res=new ListNode(sum%10);								// Creating node with curr. sum.
			res.next=prev;													// Making the prev. val as next of curr. val.
			prev=res;
			carry=sum/10;													// Calc. carry to be passed to next node.
			r1=r1.next;														// Moving to next node.
			r2=r2.next;
		}
		
		
		while(r1!=null) {													// When only one LL has valid node.
			int sum=carry+r1.val;
			ListNode res=new ListNode(sum%10);
			res.next=prev;
			prev=res;
			sum/=10;
			r1=r1.next;
		}
		
		
		while(r2!=null) {													// When only one LL has valid node.
			int sum=carry+r2.val;
			ListNode res=new ListNode(sum%10);
			res.next=prev;
			prev=res;
			sum/=10;
			r2=r2.next;
		}
		
		if(carry>0) {															// When last carry is >0, create node for it.
			ListNode res=new ListNode(carry);
			res.next=prev;
			prev=res;
		}
		
		
		return prev;														// Returning the root of sum LL. 
	}
	
	
	
	static ListNode reverseLL(ListNode node) {								// Reverses the LL.
		if(node==null || node.next==null) return node;						// Two base cases.
		ListNode prev=null;													// Init. prev. node.
		ListNode curr=node;													// Init. curr. node.
		ListNode fol;
		while(curr!=null) {
			fol=curr.next;													// Storing next node to curr. node.
			curr.next=prev;
			prev=curr;
			curr=fol;
		}
		return prev;														// Returning the root of the reversed LL.
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ListNode root= new ListNode(9);
		System.out.println("The node val: "+root.val);
		root.next= new ListNode(9);
		root.next.next=new ListNode(9);
//		root.next.next.next=new ListNode(4);
//		root.next.next.next.next=new ListNode(5);
//		root.next.next.next.next.next= new ListNode(6);
		ListNode root2= new ListNode(1);
//		System.out.println("The node val: "+root2.val);
		root2.next= new ListNode(1);
//		root2.next.next=new ListNode(9);
//		ListNode res=sumLL(root,root2);										// Calc. sum of two LLs and gives sum in reversed num format.
//		printLL(res);														// Printing the sum LL.
//		ListNode res2=reverseLL(res);										// Reverses the sum LL.
//		printLL(res2);														// Printing the reversed sum LL.

		
		
		ListNode res3=sum2LL(root,root2);									// Calc. sum of two LLs and gives sum in default version of nums.
		printLL(res3);
		
	}

}
