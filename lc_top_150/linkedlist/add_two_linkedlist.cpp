
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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy; 
        int carry = 0; 
        ListNode* res; 
        while(l1 || l2 || carry){
            int sum = 0;
            if(l1){
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2){
                sum += l2 -> val; 
                l2 = l2 -> next;
            }
            sum += carry; 
            carry = sum / 10; 
            ListNode* new_node = new ListNode(sum % 10); 
            temp -> next = new_node; 
            temp = temp -> next; 
        }
        return dummy -> next;
    }
};

int main(){
    
}