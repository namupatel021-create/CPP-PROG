#include<iostream>
#include<string>
using namespace std;

class Train {
private:
    int trainNumber;
    string trainName;
    string source;
    string destination;
    string trainTime;
    static int trainCount;

public:
    Train() {
        trainNumber = 0;
        trainName = "";
        source = "";
        destination = "";
        trainTime = "";
        trainCount++;
    }

    ~Train() {
        trainCount--;
    }

    void setTrainNumber(int num) { trainNumber = num; }
    int getTrainNumber() { return trainNumber; }

    void setTrainName(string name) { trainName = name; }
    string getTrainName() { return trainName; }

    void setSource(string src) { source = src; }
    string getSource() { return source; }

    void setDestination(string dest) { destination = dest; }
    string getDestination() { return destination; }

    void setTrainTime(string time) { trainTime = time; }
    string getTrainTime() { return trainTime; }

    void inputTrainDetails() {
        cout << "\nEnter Train Number: ";
        cin >> trainNumber;
        cin.ignore();  
        cout << "Enter Train Name: ";
        getline(cin, trainName);
        cout << "Enter Source Station: ";
        getline(cin, source);
        cout << "Enter Destination Station: ";
        getline(cin, destination);
        cout << "Enter Departure Time: ";
        getline(cin, trainTime);
        cout << "\nTrain added successfully!\n";
    }

    
    void displayTrainDetails() {
        cout << "------------------------------\n";
        cout << "Train Number   : " << trainNumber << endl;
        cout << "Train Name     : " << trainName << endl;
        cout << "Source         : " << source << endl;
        cout << "Destination    : " << destination << endl;
        cout << "Departure Time : " << trainTime << endl;
        cout << "------------------------------\n";
    }

    static int getTrainCount() { return trainCount; }
};

int Train::trainCount = 0;

class RailwaySystem {
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() {
        totalTrains = 0;
    }

    void addTrain() {
        if (totalTrains >= 100) {
            cout << "Sorry, cannot add more trains. Maximum limit reached.\n";
            return;
        }
        trains[totalTrains].inputTrainDetails();
        totalTrains++;
    }

    void displayAllTrains() {
        if (totalTrains == 0) {
            cout << "\nNo train records found!\n";
            return;
        }
        cout << "\nDisplaying all train records:\n";
        for (int i = 0; i < totalTrains; i++) {
            cout << "\nTrain " << i + 1 << ":\n";
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number) {
        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTrainNumber() == number) {
                cout << "\nTrain found:\n";
                trains[i].displayTrainDetails();
                return;
            }
        }
        cout << "\nOops! Train with number " << number << " not found.\n";
    }
};

int main() {
    RailwaySystem system;
    int choice, searchNumber;

    cout << "Welcome to the Railway Reservation System!\n";
    cout << "Please enter details for 3 initial trains:\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nTrain " << i + 1 << ":" << endl;
        system.addTrain();
    }

    do {
        cout << "\n=== Railway Reservation System Menu ===\n";
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addTrain();
                break;
            case 2:
                system.displayAllTrains();
                break;
            case 3:
                cout << "Enter Train Number to search: ";
                cin >> searchNumber;
                system.searchTrainByNumber(searchNumber);
                break;
            case 4:
                cout << "Thank you for using the Railway Reservation System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
