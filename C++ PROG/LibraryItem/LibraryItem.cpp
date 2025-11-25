#include <iostream>
#include <string>
using namespace std;

class LibraryItem
{
protected:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a, string d)
        : title(t), author(a), dueDate(d) {}

    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getDueDate() { return dueDate; }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    virtual ~LibraryItem() {}
};

// ------------------- BOOK -------------------------
class Book : public LibraryItem
{
private:
    string isbn;

public:
    Book(string t, string a, string d, string code)
        : LibraryItem(t, a, d)
    {
        if (code.size() < 5)
            throw runtime_error("Invalid ISBN");

        isbn = code;
    }

    void checkOut() override
    {
        cout << "\"" << title << "\" book issued.\n";
    }

    void returnItem() override
    {
        cout << "\"" << title << "\" book returned.\n";
    }

    void displayDetails() override
    {
        cout << "\n[Book]\n";
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "ISBN: " << isbn << endl;
    }
};

// ------------------- DVD -------------------------
class DVD : public LibraryItem
{
private:
    int duration;

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d)
    {
        if (dur <= 0)
            throw runtime_error("Invalid duration");

        duration = dur;
    }

    void checkOut() override
    {
        cout << "\"" << title << "\" DVD issued.\n";
    }

    void returnItem() override
    {
        cout << "\"" << title << "\" DVD returned.\n";
    }

    void displayDetails() override
    {
        cout << "\n[DVD]\n";
        cout << "Title: " << title << endl;
        cout << "Producer: " << author << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Duration: " << duration << " min\n";
    }
};

// ------------------- MAGAZINE -------------------------
class Magazine : public LibraryItem
{
private:
    int issue;

public:
    Magazine(string t, string a, string d, int num)
        : LibraryItem(t, a, d)
    {
        if (num <= 0)
            throw runtime_error("Invalid issue number");

        issue = num;
    }

    void checkOut() override
    {
        cout << "\"" << title << "\" magazine issued.\n";
    }

    void returnItem() override
    {
        cout << "\"" << title << "\" magazine returned.\n";
    }

    void displayDetails() override
    {
        cout << "\n[Magazine]\n";
        cout << "Title: " << title << endl;
        cout << "Publisher: " << author << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Issue No: " << issue << endl;
    }
};

// ------------------- GLOBALS -------------------------

#define MAX_ITEMS 50
LibraryItem *items[MAX_ITEMS];
int countItems = 0;

// Utility to get full input lines
void getLineInput(const string &msg, string &var)
{
    cout << msg;
    getline(cin, var);
}

// ------------------- ADD BOOK -------------------------

void addBook()
{
    if (countItems >= MAX_ITEMS)
    {
        cout << "Storage full.\n";
        return;
    }

    string t, a, d, isbn;

    cin.ignore();
    getLineInput("Title: ", t);
    getLineInput("Author: ", a);
    getLineInput("Due Date: ", d);
    getLineInput("ISBN: ", isbn);

    try
    {
        items[countItems++] = new Book(t, a, d, isbn);
        cout << "Book added.\n";
    }
    catch (exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }
}

// ------------------- ADD DVD -------------------------

void addDVD()
{
    if (countItems >= MAX_ITEMS)
    {
        cout << "Storage full.\n";
        return;
    }

    string t, a, d;
    int dur;

    cin.ignore();
    getLineInput("Title: ", t);
    getLineInput("Producer: ", a);
    getLineInput("Due Date: ", d);

    cout << "Duration (min): ";
    cin >> dur;

    try
    {
        items[countItems++] = new DVD(t, a, d, dur);
        cout << "DVD added.\n";
    }
    catch (exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }
}

// ------------------- ADD MAGAZINE -------------------------

void addMagazine()
{
    if (countItems >= MAX_ITEMS)
    {
        cout << "Storage full.\n";
        return;
    }

    string t, a, d;
    int num;

    cin.ignore();
    getLineInput("Title: ", t);
    getLineInput("Publisher: ", a);
    getLineInput("Due Date: ", d);

    cout << "Issue No: ";
    cin >> num;

    try
    {
        items[countItems++] = new Magazine(t, a, d, num);
        cout << "Magazine added.\n";
    }
    catch (exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }
}

// ------------------- SHOW ALL -------------------------

void showAll()
{
    if (countItems == 0)
    {
        cout << "No items available.\n";
        return;
    }

    for (int i = 0; i < countItems; i++)
    {
        items[i]->displayDetails();
    }
}

// ------------------- CHECK OUT -------------------------

void checkoutItem()
{
    int i;
    cout << "Enter index: ";
    cin >> i;

    if (i < 0 || i >= countItems)
    {
        cout << "Invalid index.\n";
        return;
    }

    items[i]->checkOut();
}

// ------------------- RETURN ITEM -------------------------

void returnItem()
{
    int i;
    cout << "Enter index: ";
    cin >> i;

    if (i < 0 || i >= countItems)
    {
        cout << "Invalid index.\n";
        return;
    }

    items[i]->returnItem();
}

// ------------------- MAIN -------------------------

int main()
{
    int choice;

    while (true)
    {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Show All Items\n";
        cout << "5. Checkout Item\n";
        cout << "6. Return Item\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            addDVD();
            break;
        case 3:
            addMagazine();
            break;
        case 4:
            showAll();
            break;
        case 5:
            checkoutItem();
            break;
        case 6:
            returnItem();
            break;

        case 7:
            cout << "Goodbye!\n";

            // free memory
            for (int i = 0; i < countItems; i++)
                delete items[i];

            return 0;

        default:
            cout << "Invalid option.\n";
        }
    }
}
