#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N, 0);

    // Read N integers
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    // Sort vector
    sort(A.begin(), A.end());

    int ans = 0;

    // Iterate through vector
    for (int i = 0; i < N; i++)
    {
        // Two-pointer algorithm
        int start = 0, end = N - 1;
        while (start < end)
        {
            if (start == i)
            {
                start++;
                continue;
            }
            if (end == i)
            {
                end--;
                continue;
            }

            int tmp = A[start] + A[end];

            if (tmp > A[i]) end--;
            else if (tmp < A[i]) start++;
            else
            {
                ans++;
                break;
            }
        }
    }

    // Print answer
    cout << ans << '\n';
}