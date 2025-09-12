#include <iostream>
using namespace std;

int main()
{
    // disable sync with stdio for faster performance
    ios::sync_with_stdio(false);
    // untying buffers
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    int prefixSum[100001] = {0};
    int tmp1;
    for (int i = 1; i <= N; i++)
    {
        cin >> tmp1;
        prefixSum[i] = prefixSum[i - 1] + tmp1;
    }

    int tmp2;
    for (int i = 0; i < M; i++)
    {
        cin >> tmp1 >> tmp2;
        cout << prefixSum[tmp2] - prefixSum[tmp1 - 1] << '\n';
    }
}