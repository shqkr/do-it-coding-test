// The book uses arrays to solve the problem, but
// this solution avoids using arrays for enhanced performance

#include <iostream>
using namespace std;

int main()
{
    int N = 0;
    cin >> N;

    int sum = 0;
    int highest = -1;
    int tmp = -1;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        sum += tmp;
        if (highest < tmp) highest = tmp;
    }

    cout << (sum * 100.0 / N / highest) << '\n';
}