//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string decodedString(string s)
    {
        string res = recDecode(s, 0, s.length());

        return res;
    }

    int k = 0;

    string recDecode(string s, int i, int n)
    {

        if (i >= n)

            return "";

        int num = 0;

        string cur = "";

        while (s[i] != ']' && i < n)
        {

            if (isdigit(s[i]))
            {

                while (isdigit(s[i]) && i < n)
                {

                    num = num * 10 + (s[i] - '0');

                    i++;
                }
            }

            else if (s[i] == '[')
            {

                string temp = recDecode(s, i + 1, n);

                while (num--)
                {

                    cur += temp;
                }

                num = 0;

                i = k;
            }

            else
            {

                cur += s[i];

                i++;
            }
        }

        k = i + 1;

        return cur;
        // code here
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends