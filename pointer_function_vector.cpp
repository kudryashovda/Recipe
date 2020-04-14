#include <iostream>
#include <vector>

using namespace std;

void fsqr(int &a)
{
    a = a*a;
}

void fline(int &a)
{
    a = a*2;
}

void map(vector<int>& v, void (*foo)(int &a))
{
    for(size_t i = 0, s = v.size(); i < s; ++i)
    {
        foo(v[i]);
    }
}

void showArray(const vector<int>& arr)
{
    for (auto it: arr)
        cout << it << " " ;
    cout << endl;
}

int main()
{
    vector<int> arr = {6,2,1,10,5};
    
    map(arr, fsqr); // array will be modified here

    showArray(arr);

    map(arr, fline);

    showArray(arr);
}
