#include <iostream>
#include "Deque.hpp"
using namespace std;

template <typename T>
void reverse(T* arr, int size) {
    bool more;
    int index_min = 0, index_max = 0, i;
    T max, min, temp;
    max = min = arr[0];
    for (i = 1; i < size; i++) {
        if (arr[i] > max) {
            index_max = i;
            max = arr[i];
        }
        else if (arr[i] < min) {
            index_min = i;
            min = arr[i];
        }
    }
    if (index_min < index_max) {
        more = true;
        index_min++;
        index_max--;
    }
    else {
        more = false;
        index_max++;
        index_min--;
    }
    if (more) {
        while (index_min < index_max) {
            temp = arr[index_min];
            arr[index_min] = arr[index_max];
            arr[index_max] = temp;
            ++index_min; --index_max;
        }
    }
    else {
        while (index_max < index_min) {
            temp = arr[index_max];
            arr[index_max] = arr[index_min];
            arr[index_min] = temp;
            ++index_max; --index_min;
        }
    }
}
#define N 6
int main(int argc, const char* argv[]) {
    int sig[N], i, numi;
    float fsig[N], numf;
    cout << "1.Int function" << endl;
    for (i = 0; i < N; i++) {
        cout << "Enter number: ";
        cin >> sig[i];
    }
    reverse(sig, N);
    for (i = 0; i < N; i++) {
        cout << sig[i] << " ";
    }
    cout << endl;
    cout << "1.Float function" << endl;
    for (i = 0; i < N; i++) {
        cout << "Enter number: ";
        cin >> fsig[i];
    }
    reverse(fsig, N);
    for (i = 0; i < N; i++) {
        cout << fsig[i] << " ";
    }
    cout << endl;
    Deque<int>* dequei = new List<int>;
    Deque<float>* dequef = new List<float>;
    cout << "2.Int deque list" << endl;
    for (i = 0; i < N; i++) {
        cout << "Enter number: ";
        cin >> numi;
        dequei->InLeft(numi);
    }
    for (i = 0; i < N / 2; i++) {
        cout << dequei->OutLeft() << " " << dequei->OutRight() << " ";
    }
    cout << endl;
    cout << "2.Float deque list" << endl;
    for (i = 0; i < N; i++) {
        cout << "Enter number: ";
        cin >> numf;
        dequef->InLeft(numf);
    }
    for (i = 0; i < N / 2; i++) {
        cout << dequef->OutLeft() << " " << dequef->OutRight() << " ";
    }
    cout << endl;
    dequei = new Array<int>;
    cout << "2.Int deque array" << endl;
    for (i = 0; i < N; i++) {
        cout << "Enter number: ";
        cin >> numi;
        dequei->InLeft(numi);
    }
    for (i = 0; i < N / 2; i++) {
        cout << dequei->OutLeft() << " " << dequei->OutRight() << " ";
    }
    cout << endl;
    dequef = new Array<float>;
    cout << "2.Float deque array" << endl;
    for (i = 0; i < N; i++) {
        cout << "Enter number: ";
        cin >> numf;
        dequef->InLeft(numf);
    }
    for (i = 0; i < N / 2; i++) {
        cout << dequef->OutLeft() << " " << dequef->OutRight() << " ";
    }
    cout << endl;
    return 0;
}