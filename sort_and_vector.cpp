#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {6,2,1,10,5};
    
    sort(arr.begin(), arr.end(), [](const int& a, const int& b) {return (a < b); } );
    
    for (auto it: arr)
        cout << it << " " ;
    cout << endl;
}
