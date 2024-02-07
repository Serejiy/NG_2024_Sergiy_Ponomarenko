#include <iostream>

using namespace std;

int main() {
    int size;
    cout << "Enter the size of an array: ";
    cin >> size;
    int arr[size];

    for (int a = 0; a < size; a++){
        cout << "Enter element " << a << ": ";
        cin >> arr[a];
    }

    int sum = 0;
    int even_sum = 0;
    int odd_sum = 0;

    for (int c = 0; c < size; c++){
        sum += arr[c];
        if (arr[c] % 2 == 0){
            even_sum += arr[c];
        } else {
            odd_sum += arr[c];
        }
    }

    cout << "The sum of all elements: " << sum << endl;
    cout << "The sum of all even elements: " << even_sum << endl;
    cout << "The sum of all odd elements: " << odd_sum << endl;

    return 0;
}
