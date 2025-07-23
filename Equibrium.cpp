// Equilibrium Point
// Difficulty: EasyAccuracy: 28.13%Submissions: 650K+Points: 2Average Time: 15m
// Given an array of integers arr[], the task is to find the first equilibrium point in the array.

// The equilibrium point in an array is an index (0-based indexing) such that the sum of all elements before that index is the same as the sum of elements after it. Return -1 if no such point exists.

// Examples:

// Input: arr[] = [1, 2, 0, 3]
// Output: 2
// Explanation: The sum of left of index 2 is 1 + 2 = 3 and sum on right of index 2 is 3.
// Input: arr[] = [1, 1, 1, 1]
// Output: -1
// Explanation: There is no equilibrium index in the array.
// Input: arr[] = [-7, 1, 5, 2, -4, 3, 0]
// Output: 3
// Explanation: The sum of left of index 3 is -7 + 1 + 5 = -1 and sum on right of index 3 is -4 + 3 + 0 = -1.
// Constraints:
// 3 <= arr.size() <= 105
// -104 <= arr[i] <= 104

class Solution
{
public:
    // Function to find equilibrium point in the array.
    // Approach one(Time :O(n) , Space O(1) : pick 1 element do sum of all element on both sides then compare.
    // if equal  the return
    // Approach 2 : Take two array to precompute sum of element ffrom both side
    // Time : O(n)  , space O(n)

    int findEquilibrium(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> sumFromLeft(n, 0);
        vector<int> sumFromRight(n, 0);
        // code here
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                sumFromLeft[i] = arr[i];
            else

                sumFromLeft[i] = sumFromLeft[i - 1] + arr[i];
        }
        // for(int item : sumFromLeft)
        // {
        //     cout<<item<<" left"<<"\n";
        // }
        for (int i = n - 1; i >= 0; --i)
        {
            if (i == n - 1)
                sumFromRight[i] = arr[i];
            else

                sumFromRight[i] = sumFromRight[i + 1] + arr[i];
        }
        //  for(int item : sumFromRight)
        // {
        //     cout<<item<<"right"<<"\n";
        // }

        for (int i = 0; i < n; i++)
        {
            int leftSum = (i != 0) ? sumFromLeft[i - 1] : 0;
            int rightSum = (i != n - 1) ? sumFromRight[i + 1] : 0;

            //  cout<<leftSum <<" "<<rightSum <<"\n";
            if (leftSum == rightSum)
                return i;
        }

        return -1;
    }
};