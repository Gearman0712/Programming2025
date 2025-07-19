// User function Template for C++
// TI
class Solution
{

    int maximunCowsThatCanBePlaced(int distance, vector<int> &stalls)
    {
        int n = stalls.size();
        int cnt = 1;
        int lastPostion = stalls[0];

        for (int i = 1; i < n; i++)
        {
            if (stalls[i] - lastPostion >= distance)
            {
                cnt++;
                lastPostion = stalls[i];
            }
        }

        return cnt;
    }

public:
    int aggressiveCows(vector<int> &stalls, int k)
    {

        // Time : o(log(10^8)*n)

        // [2, 3, 7, 11,12, 26]

        // l=1
        // h = 2
        // mid = 1(3)

        // low and high are minimum distnces between two cows , n can be very small but postions can be big
        int n = stalls.size();
        int low = 1, high = 100000000;
        int ans = -1;
        sort(stalls.begin(), stalls.end());

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (maximunCowsThatCanBePlaced(mid, stalls) >= k)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};

//[1, 2, 4, 8, 9]

// 1 2   3 4 5 6 7 8 9
// ^ ^     ^       ^ ^

// c   3    c  4     c      =>3
// c   3    c   5       c   =>3
// c       7        c1 c    => 1
