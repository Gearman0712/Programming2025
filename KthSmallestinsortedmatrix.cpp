class Solution
{
public:
    // [1 ,5, 9]
    // [10,11,13]
    // [12,13,15]
    // We can traverse row wise but after 13 of 2nd row we get 12 in third row.
    // lets pick one element say 11 , no of element less than 11 = no of element less than 11 = 4
    // so its 5 smallest number
    // increase no to 13 , no of element less than 13 = 6 and including 13 total element = 8
    // so less + countEqual
    // its monotnic in nature
    //  we can apply binary serach on Answer concept
    // dicuss cases:
    //  https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/solutions/1322101/c-java-python-maxheap-minheap-binary-search-picture-explain-clean-concise
    //
    // 1)why countLessThanEqual>= k  not  countLessThanEqual>= k  : searching for 13
    // 2) Even after countLessThanEqual>= k ,still looking for less , for 14(not answr) and 13 , function will return same value

    // Time : O(log(high-low)*nlog(n))
    // space: O(1)
    int countLessThanEqual(vector<vector<int>> &matrix, int mid)
    {
        int count = 0;
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        return count;
    }
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        int ans = -1;
        while (low <= high)
        {

            int mid = low + (high - low) / 2;
            //    cout<<low <<" "<<high <<" "<<mid<<" "<<  countLessThanEqual(matrix ,mid) <<"\n";
            if (countLessThanEqual(matrix, mid) >= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};