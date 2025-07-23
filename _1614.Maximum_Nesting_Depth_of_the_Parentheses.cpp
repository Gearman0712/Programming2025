// Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

// Example 1:

// Input: s = "(1+(2*3)+((8)/4))+1"

// Output: 3

// Explanation:

// Digit 8 is inside of 3 nested parentheses in the string.

// Example 2:

// Input: s = "(1)+((2))+(((3)))"

// Output: 3

// Explanation:

// Digit 3 is inside of 3 nested parentheses in the string.

// Example 3:

// Input: s = "()(())((()()))"

// Output: 3

class Solution
{
public:
    // Need to keep track of opening and closing brackets
    // Time : O(n)
    int maxDepth(string s)
    {
        int ans = 0;

        int level = 0;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                level++;
                if (level > ans)
                    ans = level;
            }
            else if (s[i] == ')')
            {
                level--;
            }
        }

        return ans;
    }
};