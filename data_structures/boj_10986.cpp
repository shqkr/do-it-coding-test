#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<long> S(N + 1, 0);
    vector<long> C(M, 0);
    long count = 0;

    for (int i = 1; i < N + 1; i++)
    {
        int tmp;
        cin >> tmp;
        S[i] = S[i - 1] + tmp;

        int remainder = S[i] % M;

        if (remainder == 0) count++;
        C[remainder]++;
    }

    for (int i = 0; i < M; i++)
    {
        if (C[i] > 1)
        {
            count += (C[i] * (C[i] - 1) / 2);
        }
    }

    cout << count << "\n";
}