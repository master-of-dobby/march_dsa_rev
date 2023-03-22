//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if ((*head_ref) != NULL) (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void printList(struct Node* head) {
    if (head == NULL) cout << -1;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


// } Driver Code Ends
// User function Template for C++


/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void reverse(struct Node **head_ref)
    {
        struct Node *temp = NULL;
        struct Node *current = *head_ref;

        /* swap next and prev for all nodes of
          doubly linked list */
        while (current != NULL)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        /* Before changing head, check for the cases like empty
           list and list with only one node */
        if (temp != NULL)
            *head_ref = temp->prev;
    }

    void deleteAllOccurOfX(struct Node **head, int x)
    {
    // Write your code here
        //X:
        struct Node *temp = *head;

        while (temp != NULL)
        {

            // cout << temp->data << " ";

            if (temp->data == x)
            {

                if (temp->next == NULL && temp->prev == NULL)
                {
                    free(temp);
                    *head = NULL;
                    break;
                }

                else if (temp->prev == NULL)
                {
                    *head = temp->next;
                    temp->next->prev = NULL;
                    free(temp);
                    deleteAllOccurOfX(&*head, x);
                    break;
                }

                else if (temp->next == NULL && temp->prev != NULL)
                {
                    temp->prev->next = NULL;
                    free(temp);
                    deleteAllOccurOfX(&*head, x);
                    break;
                }

                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;

                    free(temp);
                    deleteAllOccurOfX(&*head, x);
                    break;
                }
            }

            temp = temp->next;
        }

        //reverse(head);
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        Node* head = new Node();
        head = NULL;

        int n;
        cin >> n;

        vector<int> inp(n);

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            // push(&head,val);
            inp[i] = val;
        }
        for (int i = n - 1; i >= 0; i--) {
            push(&head, inp[i]);
        }
        int key;
        cin >> key;
        // printList(head);
        // cout << endl;

        Solution obj;

        obj.deleteAllOccurOfX(&head, key);
        printList(head);
        cout << endl;

        // cout << "\n~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends