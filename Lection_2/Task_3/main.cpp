#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers;
    int maxNumber = 0;

    cout << "Enter numbers (enter 0 to finish input):" << endl;

    int number;
    while (true) {
        cin >> number;

        if (number == 0) {
            break;
        }

        numbers.push_back(number);
        maxNumber = max(maxNumber, number);
    }

    cout << "You entered the numbers:" << endl;
    for (int num : numbers) {
        cout << num << endl;
    }

    cout << "Centered figure:" << endl;
    for (int num : numbers) {
        int spaces = (maxNumber - num) / 2;
        cout << string(spaces, ' ');
        cout << string(num, '*');
        cout << string(spaces, ' ');
        cout << endl;
    }

    return 0;
}

