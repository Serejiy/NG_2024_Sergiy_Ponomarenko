#include <iostream>

using namespace std;

int main()
{
    float salarie = 0;
    string result;

    cout << "How much do you earn: ";
    cin >> salarie;
    if (salarie < 1000) {
        cout << "Work harder!" << endl;
        cout << "... but you did good mate" << endl;
    }
    if (salarie > 1000) {
        cout << "Do you make over 1 mil? Enter your salarie: ";
        float answer = 0;
        cin >> answer;
        result = (answer > 1000000) ? "You are a millionare!" : "Still good job.";
        cout << result << endl;
        cout << "... but you did good mate";
    }


    return 0;
}
