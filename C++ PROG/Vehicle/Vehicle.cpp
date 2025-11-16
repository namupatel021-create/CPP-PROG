#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    int id;
    string brand;
    string model;
    int year;

public:
    void input()
    {
        cout << "Enter Vehicle ID: ";
        cin >> id;
        cout << "Enter Brand: ";
        cin >> brand;
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Year: ";
        cin >> year;
    }
    void show() { cout << "ID: " << id << " | " << brand << " " << model << " (" << year << ")" << endl; }
    int getId() { return id; }
};

class Car : public Vehicle
{
protected:
    string fuelType;

public:
    void inputCar()
    {
        input();
        cout << "Enter Fuel Type: ";
        cin >> fuelType;
    }
    void showCar()
    {
        show();
        cout << "Fuel: " << fuelType << endl;
    }
};

class ElectricCar : public Car
{
    int battery;

public:
    void inputElectric()
    {
        inputCar();
        cout << "Enter Battery Capacity (kWh): ";
        cin >> battery;
    }
    void showElectric()
    {
        showCar();
        cout << "Battery: " << battery << " kWh" << endl;
    }
};

class SUV : public Car
{
public:
    void inputSUV() { inputCar(); }
    void showSUV() { showCar(); }
};

class Registry
{
    Vehicle *list[10];
    int count = 0;

public:
    void addVehicle(Vehicle *v)
    {
        if (count < 10)
            list[count++] = v;
        cout << "✅ Vehicle added!\n";
    }
    void showAll()
    {
        if (count == 0)
        {
            cout << "No vehicles yet.\n";
            return;
        }
        cout << "\n--- All Vehicles ---\n";
        for (int i = 0; i < count; i++)
            list[i]->show();
    }
    void search(int id)
    {
        for (int i = 0; i < count; i++)
        {
            if (list[i]->getId() == id)
            {
                cout << "Vehicle found:\n";
                list[i]->show();
                return;
            }
        }
        cout << "❌ Vehicle not found!\n";
    }
};

int main()
{
    Registry reg;
    int choice;
    do
    {
        cout << "\n===== Vehicle Registry Menu =====\n";
        cout << "1. Add Car\n2. Add Electric Car\n3. Add SUV\n4. View All\n5. Search by ID\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Car *c = new Car();
            c->inputCar();
            reg.addVehicle(c);
        }
        else if (choice == 2)
        {
            ElectricCar *e = new ElectricCar();
            e->inputElectric();
            reg.addVehicle(e);
        }
        else if (choice == 3)
        {
            SUV *s = new SUV();
            s->inputSUV();
            reg.addVehicle(s);
        }
        else if (choice == 4)
            reg.showAll();
        else if (choice == 5)
        {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            reg.search(id);
        }
        else if (choice == 6)
            cout << "Exiting...\n";
        else
            cout << "Invalid choice!\n";
    } while (choice != 6);
    return 0;
}