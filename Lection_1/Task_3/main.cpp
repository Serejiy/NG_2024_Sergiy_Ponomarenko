#include <iostream>

using namespace std;

int main() {
    int height;
    cout << "Enter the height: ";
    cin >> height;

    for (int current_row = 0; current_row < height; ++current_row) {
        for (int spaces = 0; spaces < height - current_row - 1; ++spaces)
            cout << " ";

        for (int stars = 0; stars < 2 * current_row + 1; ++stars)
            cout << "*";

        cout << std::endl;
    }

    for (int trunk_spaces = 0; trunk_spaces < height - 1; ++trunk_spaces)
        cout << " ";
    cout << "*" << std::endl;

    return 0;
}

