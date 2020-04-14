#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int a, int b)
{
    return (a < b); // 1,2,3,4,5 | if (b <a) then 5,4,3,2,1
}

int main()
{
    vector<int> arr = {6,2,1,10,5};
    
    sort(arr.begin(), arr.end(), cmp);

    for (auto it: arr)
        cout << it << " " ;
    cout << endl;
}
