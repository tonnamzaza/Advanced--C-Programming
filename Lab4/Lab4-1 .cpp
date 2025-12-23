#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A[10] = {0,1,2,3,4,5,6,7,8,9}, x;

    for (const auto &x : A){
        cout << x << " ";
    };
    sort(A, A + 10, greater<int>());
    sort(A, A + 10);
    cout << "\nAfter sorting (Ascending): \n";
    for (const auto &x : A){
        cout << x << " ";
    };
}