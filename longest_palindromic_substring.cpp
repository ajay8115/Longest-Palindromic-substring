// CODE BY :- AJAY PAL IIT (BHU) VARANASI
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        // table[i][j] will be false , if substring str[i..j] is not palindrome.
        // Else table[i][j] will be true
        bool t[n][n];

        memset(t, 0, sizeof(t));

        // All substrings of length 1 are palindromes that is all diagonal
        for (int i = 0; i < n; i++)
        {
            t[i][i] = true;
        }

        int maxlen = 1; // at least one length is palin
        int start = 0;

        // check for sub-string of length 2.
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                t[i][i + 1] = true;
                start = i;  // Update the start
                maxlen = 2; // maxlen become 2
            }
        }

        // Check for lengths greater than 2. (k) is length of substring

        for (int k = 3; k <= n; k++)
        {
            for (int i = 0; i < n - k + 1; i++)
            {
                int j = k + i - 1; // Get the ending index of substring from starting index i and length k
                                   // checking for sub-string from ith index to jth index iff str[i+1] to str[j-1] is a palindrome
                if (t[i + 1][j - 1] and s[i] == s[j])
                {
                    t[i][j] = true;
                    if (k > maxlen) // Update the maxlen
                    {
                        start = i;
                        maxlen = k;
                    }
                }
            }
        }

        int end = start + maxlen - 1;

        string g = "";
        for (int i = start; i <= end; i++)
        {
            g += s[i];
        }

        return g; // and maxlen can be find   if required
    }
};
