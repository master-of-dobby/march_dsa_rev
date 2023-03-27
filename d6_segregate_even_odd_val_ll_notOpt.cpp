//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* delete_node(Node* head, int val){
        
        Node* temp = head;
        Node* prev;
        
        while(temp != NULL){
            
            if(temp->data == val){
                
                if(temp == head)
                    head = head->next;
               
                else
                    prev->next = temp->next;
                
                   
                free(temp);
                    break;
                
            
            }
            else{
                prev = temp;
                temp = temp->next;
            }
            
            
        }
        
        return head;
        
    }
    
    Node* add_at_begin(Node* head, int val){
        
        if(head == NULL){
            Node* r = new Node(val);
            r->next = NULL;
            head = r;
        }
        else{
            Node* r = new Node(val);
            r->next = head;
            head = r;
        }
        
        return head;
    }
    
    Node* divide(int N, Node *head){
        // code here
        stack<int> st;
        stack<int> st0;
        
        Node* temp = head;
        Node* prev = head;
        
        
        while(temp != NULL){
            if(temp->data % 2 == 0){
                st.push(temp->data);
                temp = temp->next;
                head = temp;
            }
            else
                break;
        }
        
        while(temp != NULL){
            
            if(temp->data % 2 == 0){
                st.push(temp->data);
                delete_node(head, temp->data);
            }
            
            temp = temp->next;
            
        }
        
        while(!st.empty()){
            head = add_at_begin(head, st.top());
            st.pop();
        }
        
        // while(!st0.empty()){
        //     head = add_at_begin(head, st0.top());
        //     st0.pop();
        // }
        
        
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends