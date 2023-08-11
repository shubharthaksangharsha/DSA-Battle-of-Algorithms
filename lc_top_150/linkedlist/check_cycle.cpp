
//Author - Shubharthak Sangharasha
/*
    Description: 
*/


#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

class ListNode{
	public:
	int data; 
	ListNode* next;
	//Default Constructor
	ListNode(){
		this -> data = 0; 
		this -> next = NULL;
	}
	//Paramtezied Constructor 
	ListNode(int data){
		this -> data = data; 
		this -> next = NULL;
	}
	~ListNode(){
		int value = this -> data; 
		if(this -> next != NULL){
			delete this -> next; 
			this -> next = NULL;
		}
		cout << "Memory free for node with data " << value << endl;
	}
};

void print(ListNode* head){
	while(head){
		cout << head -> data << "->";  
		head = head -> next;
	}
	cout << endl;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

private:
    bool check_cycle(ListNode* head){
        if(!head){
            return false;
        }
        ListNode* slow = head; 
        ListNode* fast = head; 
        while(fast && fast->next){
            slow = slow -> next; 
            fast = fast -> next -> next; 
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
public:
    bool hasCycle(ListNode *head) {
        return check_cycle(head);
    }
};
int main(){
	Solution sol; 
	ListNode* head = new ListNode(2);
	ListNode* node = new ListNode(3);
	ListNode* node2 = new ListNode(4);
	
	head -> next = node; 
	node -> next = node2; 
	node2 -> next = head; 
	// print(head);
	cout << sol.hasCycle(head) << endl;

	delete head; 
	delete node; 															
	delete node2;																													
 	
  	return 0; 					
}