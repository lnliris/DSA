/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

int main(){
    int *a, n; cin >> n;
    a = new int [n];



    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    sort(a, n);

    for(int i = 0; i < n; i ++){
        cout << a[i] << " ";
    }
}
