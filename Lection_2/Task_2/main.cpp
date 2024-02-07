#include <iostream>

using namespace std;

int main() {
    cout << "enter the size of an array: ";

    int size;
    cin >> size;
    int arr[size];

    for (int a = 0; a < size; a++){
        cout << "Enter " << a << ": ";
        cin >> arr[a];
    }

    int maxElement = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    cout << "Maximum element: " << maxElement << endl;

    int minElement = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }
    cout << "Minimum element: " << minElement << endl;

    return 0;
}
