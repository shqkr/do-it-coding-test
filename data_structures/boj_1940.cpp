#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int start = 0, end = N - 1;
    int ans = 0;

    while (start < end)
    {
        int sum = A[start] + A[end];
        if (sum < M)
            start++;
        else if (sum > M)
            end--;
        else
        {
            ans++;
            start++;
            end--;
        }
    }

    cout << ans << '\n';
}