/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
struct
<
>
###End banned keyword*/

#include <iostream>
using namespace std;
#include <time.h>


//###INSERT CODE HERE -

void my_sort(int a[], int n) {
    for (int base = 1; ; base *= 10) {
        int** A = new int *[10];
        int* C = new int[10];
        for (int i = 0; i != 10; i++) {
            A[i] = new int[n];
            C[i] = 0;
        }
        for (int i = 0; i != n; i++) {
            int digit = a[i] / base % 10;
            A[digit][C[digit]++] = a[i];
        }
        for (int i = 0, id = 0; i != 10; i++) {
            for (int j = 0; j != C[i]; j++)
                a[id++] = A[i][j];
        }
        for (int i = 0; i != 10; i++) {
            delete[] A[i];
        }
        delete[] A;
        delete[] C;
        if (base == 1000000000) break;
    }
}

int main(){
    int n;
    cin >> n;

    int *A = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        A[i] = -10000 + rand() % (20001);
    clock_t start, end;
    double time;
    start = clock();
    my_sort (A, n);
    end = clock();

    time = ((double)(end - start)) / CLOCKS_PER_SEC;

    //outputArray(a, n);
    cout << "Time: " << time << endl;
  /*  for(int i = 0; i < n; i++){
        cout << A[i] << " " ;
    }*/
}
