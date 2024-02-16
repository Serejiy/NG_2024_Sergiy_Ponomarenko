#include <iostream>
#include <limits> // Для использования numeric_limits

using namespace std;

const int MAX_CLIENTS = 10;

struct DB {
    string name;
    int balance;
    int clientID; // Changed field name
};

DB clients[MAX_CLIENTS];
int numClients = 0;

void new_customer() {
    if (numClients < MAX_CLIENTS) {
        cout << "Enter your name: ";
        cin >> clients[numClients].name;

        int balance;
        while (true) {
            cout << "Enter your balance: ";
            if (cin >> balance && balance >= 0) {
                clients[numClients].balance = balance;
                break; // Выход из цикла, если ввод корректный
            } else {
                cout << "Invalid input. Please enter a non-negative number." << endl;
                cin.clear(); // Очистка флага ошибки
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода
            }
        }

        clients[numClients].clientID = numClients; // Assigning client ID as index
        numClients++;
        cout << endl;
    }
}

void Account_Info(int input_clientID) {
    if (input_clientID >= 0 && input_clientID < MAX_CLIENTS) {
        cout << "Client id: " << input_clientID << endl <<"Name: " << clients[input_clientID].name << endl << "Balance: " << clients[input_clientID].balance << endl;
        for (int i = 0; i < MAX_CLIENTS; ++i) {
            if (i == input_clientID) {
                cout << clients[i].balance << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    } else {
        cout << "Invalid client ID!" << endl;
        cout << endl;
    }
}


void deposit(int input_clientID, int amount) {
    for (int i = 0; i < numClients; ++i) {
        if (clients[i].clientID == input_clientID) {
            clients[i].balance += amount;
            cout << "Deposit successful. New balance: " << clients[i].balance << endl;
            cout << endl;
            return;
        }
    }
    cout << "Client not found!" << endl;
    cout << endl;
}

void withdraw(int input_clientID, int amount) {
    for (int i = 0; i < numClients; ++i) {
        if (clients[i].clientID == input_clientID) {
            if (clients[i].balance >= amount) {
                clients[i].balance -= amount;
                cout << "Withdrawal successful. New balance: " << clients[i].balance << endl;
                cout << endl;
            } else {
                cout << "Insufficient funds." << endl;
                cout << endl;
            }
            return;
        }
    }
    cout << "Client not found!" << endl;
}

void existing_customer() {
    int input_clientID;
    cout << "Enter your client ID: ";
    cin >> input_clientID;
    cout << endl;
    Account_Info(input_clientID);
    cout << endl;
    cout << "Do you want to deposit (D) or withdraw (W)?" << endl;
    char choice;
    cout << "Choice: ";
    cin >> choice;
    if (choice == 'D') {
        int amount;
        while (true) {
            cout << "Enter deposit amount: ";
            if (cin >> amount && amount >= 0) {
                deposit(input_clientID, amount);
                break; // Выход из цикла, если ввод корректный
            } else {
                cout << "Invalid input. Please enter a non-negative number." << endl;
                cin.clear(); // Очистка флага ошибки
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода
            }
        }
    } else if (choice == 'W') {
        int amount;
        while (true) {
            cout << "Enter withdrawal amount: ";
            if (cin >> amount && amount >= 0) {
                withdraw(input_clientID, amount);
                break; // Выход из цикла, если ввод корректный
            } else {
                cout << "Invalid input. Please enter a non-negative number." << endl;
                cin.clear(); // Очистка флага ошибки
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода
            }
        }
    } else {
        cout << "Invalid choice." << endl;
        cout << endl;
    }
}

void greeting() {
    cout << "You are a new client? (Type N)" << endl;
    cout << "You are already a customer? (Type C)" << endl;
    string answer;
    cout << "Answer: ";
    cin >> answer;
    cout << endl;

    if (answer == "N") {
        new_customer();
    } else if (answer == "C") {
        existing_customer();
    } else {
        cout << "Invalid input..." << endl;
        cout << endl;
    }
}

int main() {
    while (true) {
        greeting();
    }
    return 0;
}
