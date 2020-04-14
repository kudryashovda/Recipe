#include <iostream>

using namespace std;

int cmp(const void *a, const void *b)
{
    int l = *(int*)a; // here we need tp cast void to int (as in the array) and to depoint it :)
    int r = *(int*)b;
    
    return l - r; // in this case cout will be 1 2 5 6 10; if (r-l) then opposit order
}

int main()
{
    int arr[] {6,2,1,10,5};
    
    qsort(arr, 5, sizeof(int), cmp); // here cmp - is a pointer to special fuction (see upper)

    for (auto it: arr)
        cout << it << " " ;
    cout << endl;
}
