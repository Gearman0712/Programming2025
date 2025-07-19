#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// https://www.geeksforgeeks.org/dsa/kth-smallest-element-in-the-array-using-constant-space-when-array-cant-be-modified/
// Kth smallest element in the array using constant space when array can't be modified
//  Given an array arr[] of size N having no duplicates and an integer K,
//  the task is to find the Kth smallest element from the array in constant extra space and the array can't be modified.

// Input: arr[] = {7, 10, 4, 3, 20, 15}, K = 3
// Output: 7
// Given array in sorted is {3, 4, 7, 10, 15, 20}
// where 7 is the third smallest element.

// Input: arr[] = {12, 3, 5, 7, 19}, K = 2
// Output: 5

int main()
{
    vector<int> arr = {12, 3, 5, 7, 19};
    int k = 1;
    int n = arr.size();
    // suppose we randomy take 5 as our answer , no of elements less than 5  will be 1 ,
    // we can say answer will be the no ,which has count of smaller no in the array  == k-1;
    // but for 4 also , no of element less than 4 is also k-1 =1
    // we also need to check whether we have current element " 5 ,4" in the array

    // Minimum and maximum element from the array
    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());

    // Modified binary search
    while (low <= high)
    {

        int mid = low + (high - low) / 2; // for interger overflow

        // To store the count of elements from the array
        // which are less than mid and
        // the elements which are equal to mid

        int countLess = 0, countEqual = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == mid)
                countEqual++;
            else if (arr[i] < mid)
                countLess++;
        }

        // If mid is the kth smallest

        if (countLess == k - 1 && countEqual > 0)
        {
            cout << mid;
            break;
        }
        // If the required element is greater than mid
        else if (countLess == k - 1 && countEqual == 0 || countLess < k - 1)
        {
            low = mid + 1;
        }
        // If the required element is less than mid
        else //(countLess >k-1)
        {
            high = mid - 1;
        }
    }

    return 1;
}