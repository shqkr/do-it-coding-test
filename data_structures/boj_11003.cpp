#include <iostream>
#include <deque>
using namespace std;
typedef pair<int, int> Node;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;
    deque<Node> someDeque;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;

        // Delete larger number(s) than current number
        while (someDeque.size() && someDeque.back().second > tmp)
        {
            someDeque.pop_back();
        }

        // Save last number in the end of the deque
        someDeque.push_back(Node(i, tmp));

        // Delete a number that exceeded the range (i-L+1 ~ i)
        if (someDeque.front().first <= i - L)
        {
            someDeque.pop_front();
        }

        cout << someDeque.front().second << ' ';
    }
}