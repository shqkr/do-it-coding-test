#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int start_index = 1, end_index = 1;
    int sum = 1;
    int count = 1;

    while (end_index < N)
    {
        if (sum > N)
        {
            sum -= start_index;
            start_index++;
        }
        else if (sum < N)
        {
            end_index++;
            sum += end_index;
        }
        else
        {
            count++;
            end_index++;
            sum += end_index;
        }
    }

    cout << count << '\n';
}