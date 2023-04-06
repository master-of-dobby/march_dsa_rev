//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


// } Driver Code Ends
//User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        Node* h = head;
        Node* t = head;
        
        vector<pair<int,int>> res;
        
        if(h == NULL || h->next == NULL)
            return res;
        
        while(t->next != NULL){
            t = t->next;
        }
        
        while(h->data < t->data){
            
            
            if(h->data + t->data == target){
                res.push_back(make_pair(h->data, t->data));
                h = h->next;
                t = t->prev;
            }
            
            else if(h->data + t->data < target)
                h = h->next;
            
            else
                t = t->prev;
            
        }
        
        
        
        
        
        // while(h->next != NULL){
            
        //     int k = target - h->data;
            
        //     t = h->next;
            
        //     if((t->data + h->data) > target)
        //         return res;
            
        //     while(t != NULL ){
    
        //         if(t->data == k){
        //             res.push_back(make_pair(h->data, t->data));
        //             break;
        //         }
                
        //         t = t->next;
        //     }
            
        //     h = h->next;
            
        // }
        
        
        
        // map<int,int> mp;
        
        // while(h != NULL){
            
            
        //     if(h->data < target)
        //         mp[h->data] = target - h->data;
            
        //     h = h->next;
        // }
        
        // for(auto it = mp.begin(); it != mp.end(); it++){
            
        //     if(it->first + it->second == target)
        //         res.push_back(make_pair(it->second, it->first));
                
        // }
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends