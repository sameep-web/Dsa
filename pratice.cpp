#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Course
{
    string name;
    int credits;
    float gradePoints;
};

void displayCourses(const vector<Course> &courses)
{
    cout << "\nCOURSE DETAILS:" << endl;
    cout << left << setw(20) << "Course Name" << setw(10) << "Credits" << "Grade Points" << endl;
    for (const auto &course : courses)
    {
        cout << left << setw(20) << course.name << setw(10) << course.credits << course.gradePoints << endl;
    }
}

float calculateGPA(const vector<Course> &courses)
{
    float totalGradePoints = 0;
    int totalCredits = 0;
    for (const auto &course : courses)
    {
        totalGradePoints += course.gradePoints * course.credits;
        totalCredits += course.credits;
    }
    return (totalCredits > 0) ? totalGradePoints / totalCredits : 0;
}

int main()
{
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);
    for (int i = 0; i < numCourses; ++i)
    {
        cout << "\nEnter details for course " << i + 1 << ":" << endl;
        cout << "Course Name: ";
        cin >> ws; // Clear input buffer
        getline(cin, courses[i].name);
        cout << "Credits: ";
        cin >> courses[i].credits;
        cout << "Grade Points (0-10): ";
        cin >> courses[i].gradePoints;
    }

    displayCourses(courses);
    float cgpa = calculateGPA(courses);
    cout << fixed << setprecision(2);
    cout << "\nYour CGPA is: " << cgpa << endl;

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isUserRegistered(const string& username) {
    ifstream file(username + ".txt");
    return file.good();
}

void registerUser() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;

    if (isUserRegistered(username)) {
        cout << "User already exists!" << endl;
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    ofstream file(username + ".txt");
    file << username << endl << password;
    file.close();
    cout << "Registration successful!" << endl;
}

bool loginUser() {
    string username, password, storedUsername, storedPassword;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file(username + ".txt");
    if (!file.is_open()) {
        cout << "User not found!" << endl;
        return false;
    }

    getline(file, storedUsername);
    getline(file, storedPassword);
    file.close();

    if (username == storedUsername && password == storedPassword) {
        cout << "Login successful!" << endl;
        return true;
    } else {
        cout << "Invalid credentials!" << endl;
        return false;
    }
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nChoose an option: ";
    cin >> choice;

    switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            if (loginUser()) {
                cout << "Welcome to the system!" << endl;
            }
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

class Account {
public:
    string accountNumber;
    string accountHolder;
    double balance;

    Account(string accNum, string accHolder, double initialBalance = 0.0) {
        accountNumber = accNum;
        accountHolder = accHolder;
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited Rs." << amount << ". New balance: Rs." << balance << endl;
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
            return false;
        }
        balance -= amount;
        cout << "Withdrew Rs." << amount << ". New balance: Rs." << balance << endl;
        return true;
    }

    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: Rs." << fixed << setprecision(2) << balance << endl;
    }
};

class Bank {
private:
    map<string, Account> accounts;

public:
    void createAccount(const string& accNum, const string& accHolder, double initialBalance = 0.0) {
        if (accounts.find(accNum) != accounts.end()) {
            cout << "Account already exists!" << endl;
            return;
        }
        accounts[accNum] = Account(accNum, accHolder, initialBalance);
        cout << "Account created successfully!" << endl;
    }

    void performDeposit(const string& accNum, double amount) {
        if (accounts.find(accNum) != accounts.end()) {
            accounts[accNum].deposit(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void performWithdrawal(const string& accNum, double amount) {
        if (accounts.find(accNum) != accounts.end()) {
            accounts[accNum].withdraw(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void displayAccount(const string& accNum) const {
        if (accounts.find(accNum) != accounts.end()) {
            accounts.at(accNum).display();
        } else {
            cout << "Account not found!" << endl;
        }
    }
};

int main() {
    Bank bank;
    int choice;
    string accNum, accHolder;
    double amount;

    while (true) {
        cout << "\n1. Create Account\n2. Deposit\n3. Withdraw\n4. View Account\n5. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Account Holder Name: ";
                cin >> ws;
                getline(cin, accHolder);
                bank.createAccount(accNum, accHolder);
                break;
            case 2:
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Amount to Deposit: Rs.";
                cin >> amount;
                bank.performDeposit(accNum, amount);
                break;
            case 3:
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Amount to Withdraw: Rs.";
                cin >> amount;
                bank.performWithdrawal(accNum, amount);
                break;
            case 4:
                cout << "Enter Account Number: ";
                cin >> accNum;
                bank.displayAccount(accNum);
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
