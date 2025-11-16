#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct CompareByLengthThenLexico
{
    bool operator()(const string &a, const string &b) const
    {
        if (a.length() != b.length())
            return a.length() < b.length(); // Dài hơn → ưu tiên cao hơn
        else
            return a > b; // Cùng độ dài → theo thứ tự từ điển ngược
    }
};

int main()
{
    priority_queue<string, vector<string>, CompareByLengthThenLexico> pq;

    pq.push("apple");
    pq.push("zebra");
    pq.push("banana");
    pq.push("cat");
    pq.push("dog");

    cout << "Ưu tiên theo độ dài, rồi theo từ điển:" << endl;
    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}