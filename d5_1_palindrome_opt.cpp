//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include<vector>

class Solution{
  public:
    
    Node* reverse(Node* head){
        Node* prev,*curr,*next;
        prev = NULL;
        next = NULL;
        curr = head;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
        
    }
    
    
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(head == NULL || head->next == NULL)
            return true;
            
        Node* slow = head;
        Node* fast = head;
        Node* dummy = head;
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //cout << slow->data << endl;
        slow->next = reverse(slow->next);
        //cout << slow->data << endl;
        slow = slow->next;
        
        
        while(slow != NULL){
            if(dummy->data != slow->data )
                return false;
            
            slow = slow->next;
            dummy = dummy->next;
        }
        
        return true;
        
        
        //Your code here
        // Node* start = head;
        // Node* end = head;
        
        // if(head->next == NULL)
        //     return 1;
        
        // while(end->next != NULL){
        //     end = end->next;
        // }
        
        // while(start != end){
        //     if(start->data != end->data)
        //         return 0;
            
        //     start = start->next;
        //     end = end-1;
        // }
        
        // if(start == end){
        //     if(start->data != end->data)
        //         return 0;
        // }
        
        // return 1;
        
    //     vector<int> arr;
    // while(head != NULL) {
    //     arr.push_back(head->data);
    //     head = head->next;
    // }
    // for(int i=0;i<arr.size()/2;i++) 
    //     if(arr[i] != arr[arr.size()-i-1]) return false;
    // return true;
    
    
    
    
        
        
     
        
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends