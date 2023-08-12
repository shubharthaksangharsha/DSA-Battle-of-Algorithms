
//Author - Shubharthak Sangharasha
/*
    Description: 
*/


#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

class Node{
	int data; 
	Node* next;
	//Default Constructor
	Node(){
		this -> data = 0; 
		this -> next = NULL;
	}
	//Paramtezied Constructor 
	Node(int data){
		this -> data = data; 
		this -> next = NULL;
	}
	~Node(){
		int value = this -> data; 
		if(this -> next != NULL){
			delete next; 
			this -> next = NULL;
		}
		cout << "Memory free for node with data " << value << endl;
	}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode*  merge(ListNode* a, ListNode* b){
        ListNode* dummy = new ListNode(); 
        ListNode* temp = dummy; 
        while(a && b){
            if(a->val <= b->val){
                temp -> next = new ListNode(a->val); 
                a = a->next; 
                temp = temp -> next; 
            } else{
                temp -> next = new ListNode(b->val); 
                b = b -> next; 
                temp = temp -> next; 
            }
        }
        while(a){
            temp -> next = new ListNode(a->val); 
            a = a->next;
            temp = temp -> next;
        }
        while(b){
            temp -> next = new ListNode(b->val);
            b = b -> next;
            temp = temp -> next; 
        }
        return dummy -> next;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merge(list1, list2);
    }
};

int main(){
 
 	
  	return 0; 
}