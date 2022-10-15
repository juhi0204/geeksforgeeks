//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    ListNode *moveToFront(ListNode *head)
    {
        if (head->next == NULL)
            return head;
        ListNode *temp = head;
        while (head->next->next != NULL)
            head = head->next;
        ListNode *ans = new ListNode(head->next->val);
        head->next = NULL;
        ans->next = temp;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ListNode *> a(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a[i] = new ListNode(x);
            if (i != 0)
            {
                a[i - 1]->next = a[i];
            }
        }
        ListNode *head = a[0];
        Solution ob;
        head = ob.moveToFront(head);
        while (head != NULL)
        {
            cout << head->val;
            if (head->next != NULL)
            {
                cout << " ";
            }
            head = head->next;
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends