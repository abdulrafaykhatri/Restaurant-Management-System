#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <random>
#include <windows.h>
#include <conio.h>

void clearScreen();
void pauseScreen();
void loadingScreen();
std::string getPasswordInput();

class Account
{
public:
    const std::string &getName() const;
    const std::string &getPassword() const;
    const std::string &getAccountType() const;
    void setAccountType(const std::string &accountType);
    void setName(const std::string &newName);
    void setPassword(const std::string &newPassword);
    bool signUp(const std::string &enteredName, const std::string &enteredPassword);
    bool signIn(const std::string &enteredName, const std::string &enteredPassword);

protected:
    std::string name;
    std::string password;
    std::string accountType;
};

class Admin : public Account
{
public:
private:
};

class Customer : public Account
{
public:
    unsigned long getId() const;
    void setId(unsigned long newId);
    void print() const;

private:
    unsigned long id;
};

class Item
{
public:
    Item() = default;
    Item(const std::string &name, double price);
    unsigned long getId() const;
    const std::string &getName() const;
    double getPrice() const;
    void setId(unsigned long newId);
    void setName(const std::string &newName);
    void setPrice(double newPrice);
    virtual void print() const;

private:
    unsigned long id = 0;
    std::string name;
    double price = 0;
};

class OrderItem : public Item
{
public:
    OrderItem() = default;
    OrderItem(const std::string &name, double price);
    unsigned long getOrderForId() const;
    unsigned long getQuantity() const;
    bool getIsCompleted() const;
    void setOrderForId(unsigned long newOrderForId);
    void setQuantity(unsigned long newQuantity);
    void setIsCompleted(bool newIsCompleted);
    void print() const override;

private:
    unsigned long orderForId = 0;
    unsigned long quantity = 0;
    bool isCompleted = false;
};

class Menu
{
public:
    const std::vector<Item> &getItems() const;
    void addItem();
    void addItem(unsigned long id, const std::string &name, double price);
    void removeItem();
    void changeItem();
    void print();
    unsigned long getItemsCount();

private:
    std::vector<Item> items;
};

class Table
{
public:
    unsigned long getId() const;
    unsigned long getReservedForId() const;
    void setId(unsigned long newId);
    void setReservedForId(unsigned long newReservedForId);
    void print() const;

private:
    unsigned long id = 0;
    unsigned long reservedForId = 0;
};

class Restaurant
{
public:
    Restaurant();
    void open();
    void signUpAdmin();
    void signInAdmin();
    void signUpCustomer();
    void signInCustomer();
    void addTables();
    void addTables(int numOfTables);
    void removeTable();
    void addItemToMenu();
    void removeItemFromMenu();
    void changeItemInMenu();
    void printCustomers();
    void printTables();
    void printOrders();
    void changeAdminCredentials();
    void printMenu();
    void addItemToOrder();
    void removeItemFromOrder();
    void printOrderCart();
    void printOrderHistory();
    void payBill();
    void reserveTable();
    void freeTables();
    void changeCustomerCredentials();
    void manageRestaurantServices();
    void useRestaurantServices();
    void writeAdmin();
    void readAdmin();
    void writeCustomers();
    void readCustomers();
    void writeMenu();
    void readMenu();
    void writeOrders();
    void readOrders();
    void writeTables();
    void readTables();
    int luckyDraw();

private:
    Admin admin;
    std::vector<Customer> customers;
    Menu menu;
    std::vector<OrderItem> orders;
    std::vector<Table> tables;

    unsigned long customerLoggedInId = 0;
};

int main()
{
    Restaurant restaurant;
    restaurant.open();

    return 0;
}

const std::string &Account::getName() const
{
    return name;
}

const std::string &Account::getPassword() const
{
    return password;
}

void Account::setName(const std::string &newName)
{
    name = newName;
}

void Account::setPassword(const std::string &newPassword)
{
    password = newPassword;
}

bool Account::signUp(const std::string &enteredName, const std::string &enteredPassword)
{
    name = enteredName;
    password = enteredPassword;

    return signIn(enteredName, enteredPassword);
}

bool Account::signIn(const std::string &enteredName, const std::string &enteredPassword)
{
    if (enteredName == name && enteredPassword == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Account::setAccountType(const std::string &accountType)
{
    this->accountType = accountType;
}
const std::string &Account::getAccountType() const
{
    return accountType;
}

unsigned long Customer::getId() const
{
    return id;
}

void Customer::setId(unsigned long newId)
{
    id = newId;
}

void Customer::print() const
{
    std::cout << "ID                    :   " << id << std::endl;
    std::cout << "Name                  :   " << getName() << std::endl;
    std::cout << "Account Type:         :   " << getAccountType() << std::endl;
}

Item::Item(const std::string &name, double price)
{
    Item::name = name;
    Item::price = price;
}

unsigned long Item::getId() const
{
    return id;
}

const std::string &Item::getName() const
{
    return name;
}

double Item::getPrice() const
{
    return price;
}

void Item::setId(unsigned long newId)
{
    id = newId;
}

void Item::setName(const std::string &newName)
{
    name = newName;
}

void Item::setPrice(double newPrice)
{
    price = newPrice;
}

void Item::print() const
{
    std::cout << "ID                    :   " << id << std::endl;
    std::cout << "Name                  :   " << name << std::endl;
    std::cout << "Price                 :   " << price << std::endl;
}

OrderItem::OrderItem(const std::string &name, double price) : Item(name, price)
{
}

unsigned long OrderItem::getOrderForId() const
{
    return orderForId;
}

bool OrderItem::getIsCompleted() const
{
    return isCompleted;
}

unsigned long OrderItem::getQuantity() const
{
    return quantity;
}

void OrderItem::setQuantity(unsigned long newQuantity)
{
    quantity = newQuantity;
}

void OrderItem::setOrderForId(unsigned long newOrderForId)
{
    orderForId = newOrderForId;
}

void OrderItem::setIsCompleted(bool newIsCompleted)
{
    isCompleted = newIsCompleted;
}

void OrderItem::print() const
{
    Item::print();

    std::cout << "Order For ID          :   " << orderForId << std::endl;
    std::cout << "Quantity              :   " << quantity << std::endl;
}

const std::vector<Item> &Menu::getItems() const
{
    return items;
}

void Menu::addItem(unsigned long id, const std::string &name, double price)
{
    Item newItem(name, price);
    newItem.setId(id);
    items.push_back(newItem);
}

void Menu::addItem()
{
    std::cout << "Adding Item" << std::endl;
    bool doesAlreadyExist = false;

    std::string enteredName;
    double enteredPrice = 0;
    std::cout << "Enter Name            :   ";
    std::getline(std::cin, enteredName);
    std::cout << "Enter Price           :   ";
    std::cin >> enteredPrice;

    for (const Item &item : items)
    {
        if (enteredName == item.getName())
        {
            doesAlreadyExist = true;
            break;
        }
    }

    if (!doesAlreadyExist)
    {
        Item newItem(enteredName, enteredPrice);
        newItem.setId(items.size() + 1);
        items.push_back(newItem);

        std::cout << "Successful" << std::endl;
        Sleep(1500);
    }
    else
    {
        std::cout << "Name Already In Use" << std::endl;
        Sleep(1500);
    }
}

void Menu::removeItem()
{
    std::cout << "Removing Item" << std::endl;

    unsigned long enteredId = 0;
    std::cout << "Enter ID                  :   ";
    std::cin >> enteredId;

    items.erase(items.begin() + static_cast<long>(enteredId) - 1);

    std::cout << "Successful" << std::endl;
    Sleep(1500);
}

void Menu::changeItem()
{
    std::cout << "Changing Item" << std::endl;

    unsigned long enteredId = 0;
    std::cout << "Enter ID                  :   ";
    std::cin >> enteredId;

    for (Item &item : items)
    {
        if (item.getId() == enteredId)
        {

            std::string enteredName;
            std::cout << "Enter New Name            :   ";
            std::getline(std::cin, enteredName);

            double enteredPrice = 0;
            std::cout << "Enter New Price           :   ";
            std::cin >> enteredPrice;

            item.setName(enteredName);
            item.setPrice(enteredPrice);

            break;
        }
    }

    std::cout << "Successful" << std::endl;
    Sleep(1500);
}

void Menu::print()
{
    std::cout << "Printing Menu" << std::endl;
    std::cout << std::endl;

    for (const Item &item : items)
    {
        item.print();
        std::cout << std::endl;
    }
}

unsigned long Menu::getItemsCount()
{
    return items.size();
}

unsigned long Table::getId() const
{
    return id;
}

unsigned long Table::getReservedForId() const
{
    return reservedForId;
}

void Table::setId(unsigned long newId)
{
    id = newId;
}

void Table::setReservedForId(unsigned long newReservedForId)
{
    reservedForId = newReservedForId;
}

void Table::print() const
{
    std::cout << "ID                    :   " << id << std::endl;
    std::cout << "Reserved For ID       :   " << reservedForId << std::endl;
    Sleep(1500);
}

Restaurant::Restaurant()
{
    readAdmin();
    readCustomers();
    readMenu();
    readOrders();
    readTables();
}

void Restaurant::open()
{
    loadingScreen();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    char choice;
    do
    {
        std::cout << "1. Sign Up Admin" << std::endl;
        std::cout << "2. Sign In Admin" << std::endl;
        std::cout << "3. Sign Up Customer" << std::endl;
        std::cout << "4. Sign In Customer" << std::endl;

        std::cout << "0. Exit" << std::endl;

        std::cout << "Choose: ";
        std::cin >> choice;
        std::cin.ignore();

        clearScreen();

        switch (choice)
        {
        case '1':
            signUpAdmin();
            break;
        case '2':
            signInAdmin();
            break;
        case '3':
            signUpCustomer();
            break;
        case '4':
            signInCustomer();
            break;
        case '0':
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid Choice!" << std::endl;
            Sleep(1500);
            break;
        }
        clearScreen();
    } while (choice != '0');
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Restaurant::signUpAdmin()
{
    std::cout << "Signing Up as Admin" << std::endl;
    bool isSuccessful;

    if (admin.getAccountType() == "Admin")
    {
        std::string enteredName{};
        std::string enteredPassword{};
        std::cout << "Enter Name: ";
        std::getline(std::cin, enteredName);
        std::cout << "Enter Password: ";
        enteredPassword = getPasswordInput();

        Admin newAdmin{};
        isSuccessful = newAdmin.signUp(enteredName, enteredPassword);
        newAdmin.setAccountType("Admin");
        admin = newAdmin;

        if (isSuccessful)
        {
            std::cout << "Successful" << std::endl;
            Sleep(1500);

            writeAdmin();
            manageRestaurantServices();
        }
        else
        {
            std::cout << "Invalid Id or Password" << std::endl;
            Sleep(1500);
        }
    }
    else
    {
        std::cout << "Admin Already Exist" << std::endl;
        Sleep(1500);
    }
}

void Restaurant::signInAdmin()
{
    std::cout << "Signing In as Admin" << std::endl;
    bool isSuccessful;

    std::string enteredName;
    std::string enteredPassword;
    std::cout << "Enter Name: ";
    std::getline(std::cin, enteredName);
    std::cout << "Enter Password: ";
    enteredPassword = getPasswordInput();

    isSuccessful = admin.signIn(enteredName, enteredPassword);

    if (isSuccessful)
    {
        std::cout << "Successful" << std::endl;
        Sleep(1500);

        manageRestaurantServices();
    }
    else
    {
        std::cout << "Invalid Id or Password" << std::endl;
        Sleep(1500);
    }
}

void Restaurant::signUpCustomer()
{
    std::cout << "Signing Up as Customer" << std::endl;
    bool isSuccessful = false;
    bool doesAlreadyExist = false;

    std::string enteredName;
    std::string enteredPassword;
    std::cout << "Enter Name: ";
    std::getline(std::cin, enteredName);
    std::cout << "Enter Password: ";
    enteredPassword = getPasswordInput();

    for (const Customer &customer : customers)
    {
        if (enteredName == customer.getName())
        {
            doesAlreadyExist = true;
            break;
        }
    }

    if (!doesAlreadyExist)
    {
        Customer newCustomer;
        isSuccessful = newCustomer.signUp(enteredName, enteredPassword);
        if (isSuccessful)
        {
            newCustomer.setId(customers.size() + 1);
            newCustomer.setAccountType("Customer");
            customers.push_back(newCustomer);
            customerLoggedInId = newCustomer.getId();
            std::cout << "Successful" << std::endl;
            Sleep(1500);

            writeCustomers();
            useRestaurantServices();
        }
        else
        {
            std::cout << "Invalid Id or Password" << std::endl;
            Sleep(1500);
        }
    }
    else
    {
        std::cout << "Name Already In Use" << std::endl;
        Sleep(1500);
    }
}

void Restaurant::signInCustomer()
{
    std::cout << "Signing In as Customer" << std::endl;
    bool isSuccessful{};

    std::string enteredName{};
    std::string enteredPassword{};
    std::cout << "Enter Name: ";
    std::getline(std::cin, enteredName);
    std::cout << "Enter Password: ";
    enteredPassword = getPasswordInput();

    for (Customer customer : customers)
    {
        isSuccessful = customer.signIn(enteredName, enteredPassword);

        if (isSuccessful)
        {
            customerLoggedInId = customer.getId();
            std::cout << "Successful" << std::endl;
            Sleep(1500);

            useRestaurantServices();
            break;
        }
    }

    if (!isSuccessful)
    {
        std::cout << "Invalid Id or Password" << std::endl;
        Sleep(1500);
    }
}

void Restaurant::addTables(int numOfTables)
{
    for (int i = 0; i < numOfTables; ++i)
    {
        Table table{};
        table.setId(tables.size() + 1);
        tables.push_back(table);
    }
}

void Restaurant::addTables()
{
    std::cout << "Adding Tables" << std::endl;

    unsigned long enteredNumberOfTables{};
    std::cout << "Enter Number of Tables    :   ";
    std::cin >> enteredNumberOfTables;

    for (int i = 0; i < enteredNumberOfTables; ++i)
    {
        Table table{};
        table.setId(tables.size() + 1);
        tables.push_back(table);
    }

    writeTables();
    std::cout << "Successful" << std::endl;
    Sleep(1500);
}

void Restaurant::removeTable()
{
    std::cout << "Removing Table" << std::endl;

    unsigned long enteredId{};
    std::cout << "Enter ID                  :   ";
    std::cin >> enteredId;

    tables.erase(tables.begin() + static_cast<long>(enteredId) - 1);

    writeTables();
    std::cout << "Successful" << std::endl;
    Sleep(1500);
}

void Restaurant::addItemToMenu()
{
    menu.addItem();
    writeMenu();
}

void Restaurant::removeItemFromMenu()
{
    menu.removeItem();
    writeMenu();
}

void Restaurant::changeItemInMenu()
{
    menu.changeItem();
    writeMenu();
}

void Restaurant::printCustomers()
{
    std::cout << "Printing Customers" << std::endl;
    std::cout << std::endl;

    for (const Customer &customer : customers)
    {
        customer.print();
        std::cout << std::endl;
    }
    std::cout << "Total Customers       :   " << customers.size() << std::endl;
    pauseScreen();
}

void Restaurant::printTables()
{
    std::cout << "Printing Table" << std::endl;
    std::cout << std::endl;

    for (const Table &table : tables)
    {
        table.print();
        std::cout << std::endl;
    }
    std::cout << "Total Tables       :   " << tables.size() << std::endl;
    pauseScreen();
}

void Restaurant::printOrders()
{
    std::cout << "Printing All Orders" << std::endl;
    std::cout << std::endl;

    for (const OrderItem &orderItem : orders)
    {
        orderItem.print();
        std::cout << std::endl;
    }

    std::cout << "Total Orders       :   " << orders.size() << std::endl;
    pauseScreen();
}

void Restaurant::changeAdminCredentials()
{
    std::cout << "Changing Admin Credentials" << std::endl;

    std::string enteredName{};
    std::string enteredPassword{};

    std::cout << "Enter Name: ";
    std::getline(std::cin, enteredName);

    std::cout << "Enter Password: ";
    enteredPassword = getPasswordInput();

    admin.setName(enteredName);
    admin.setPassword(enteredPassword);

    writeAdmin();
    std::cout << "Successful" << std::endl;
    Sleep(1500);
}

void Restaurant::printMenu()
{
    menu.print();
}

void Restaurant::addItemToOrder()
{
    std::cout << "Adding Item" << std::endl;
    bool isAdded{};
    bool orderAlreadyExist{};
    OrderItem *oldOrder{};

    std::string enteredName{};
    std::cout << "Enter Name            :   ";
    std::getline(std::cin, enteredName);

    for (const Item &item : menu.getItems())
    {
        if (enteredName == item.getName())
        {
            for (OrderItem &orderItem : orders)
            {
                if (enteredName == orderItem.getName() && orderItem.getOrderForId() == customerLoggedInId &&
                    !orderItem.getIsCompleted())
                {
                    oldOrder = &orderItem;
                    orderAlreadyExist = true;
                }
            }

            if (orderAlreadyExist)
            {
                oldOrder->setQuantity(oldOrder->getQuantity() + 1);
            }
            else
            {
                OrderItem newOrder{item.getName(), item.getPrice()};
                newOrder.setId(orders.size() + 1);
                newOrder.setIsCompleted(false);
                newOrder.setQuantity(newOrder.getQuantity() + 1);
                newOrder.setOrderForId(customerLoggedInId);
                orders.push_back(newOrder);
            }

            isAdded = true;
            break;
        }
    }

    if (isAdded)
    {
        writeOrders();
        std::cout << "Successful" << std::endl;
        Sleep(1500);
    }
    else
    {
        std::cout << "Item Doesn't Exist" << std::endl;
        Sleep(1500);
    }
}

void Restaurant::removeItemFromOrder()
{
    std::cout << "Removing Item" << std::endl;
    bool isRemoved{};

    unsigned long enteredId{};
    std::cout << "Enter ID                  :   ";
    std::cin >> enteredId;

    for (OrderItem &orderItem : orders)
    {
        if (enteredId == orderItem.getId() && orderItem.getOrderForId() == customerLoggedInId &&
            !orderItem.getIsCompleted())
        {

            if (orderItem.getQuantity() > 1)
            {
                orderItem.setQuantity(orderItem.getQuantity() - 1);
            }
            else
            {
                orders.erase(orders.begin() + static_cast<long>(enteredId) - 1);
            }

            isRemoved = true;
            break;
        }
    }

    if (isRemoved)
    {
        writeOrders();
        std::cout << "Successful" << std::endl;
        Sleep(1500);
    }
    else
    {
        std::cout << "Item Doesn't Exist" << std::endl;
        Sleep(1500);
    }
}

void Restaurant::printOrderCart()
{
    std::cout << "Printing OrderItem" << std::endl;
    std::cout << std::endl;
    unsigned long areThereAny{};

    for (const OrderItem &orderItem : orders)
    {
        if (orderItem.getOrderForId() == customerLoggedInId && !orderItem.getIsCompleted())
        {
            orderItem.print();
            std::cout << std::endl;
            ++areThereAny;
        }
    }

    if (areThereAny > 0)
    {
        std::cout << std::endl;
        std::cout << "Is Completed          :   No" << std::endl;
    }
    else
    {
        std::cout << std::endl;
        std::cout << "No Item" << std::endl;
    }
    Sleep(1500);
}

void Restaurant::printOrderHistory()
{
    std::cout << "Printing Completed Orders" << std::endl;
    std::cout << std::endl;
    unsigned long areThereAny{};

    for (const OrderItem &orderItem : orders)
    {
        if (orderItem.getOrderForId() == customerLoggedInId && orderItem.getIsCompleted())
        {
            orderItem.print();
            std::cout << std::endl;
            ++areThereAny;
        }
    }

    if (areThereAny > 0)
    {
        std::cout << std::endl;
        std::cout << "Is Completed          :   Yes" << std::endl;
    }
    else
    {
        std::cout << std::endl;
        std::cout << "No Item" << std::endl;
    }
    Sleep(1500);
}

void Restaurant::payBill()
{
    std::cout << "Paying Bill" << std::endl;
    std::cout << std::endl;
    double totalBill{};

    for (OrderItem &orderItem : orders)
    {
        if (orderItem.getOrderForId() == customerLoggedInId && !orderItem.getIsCompleted())
        {
            orderItem.print();
            totalBill += orderItem.getPrice() * static_cast<double>(orderItem.getQuantity());
            orderItem.setIsCompleted(true);
            writeOrders();
            std::cout << std::endl;
        }
    }

    std::cout << "Total Bill           :   " << totalBill << std::endl;
    pauseScreen();
}

void Restaurant::reserveTable()
{
    std::cout << "Reserving Table" << std::endl;
    bool isSuccessful{};

    for (Table &table : tables)
    {
        if (table.getReservedForId() == 0)
        {
            table.setReservedForId(customerLoggedInId);
            isSuccessful = true;
            break;
        }
    }

    if (isSuccessful)
    {
        writeTables();
        std::cout << "Successful" << std::endl;
        Sleep(1500);
    }
    else
    {
        std::cout << "No Free Table Available" << std::endl;
        Sleep(1500);
    }
}

void Restaurant::freeTables()
{
    std::cout << "Freeing Tables" << std::endl;
    bool isSuccessful{};

    for (Table &table : tables)
    {
        if (table.getReservedForId() == customerLoggedInId)
        {
            table.setReservedForId(0);
            isSuccessful = true;
        }
    }

    if (isSuccessful)
    {
        writeTables();
        std::cout << "Successful" << std::endl;
        Sleep(1500);
    }
    else
    {
        std::cout << "No Table Reserved" << std::endl;
        Sleep(1500);
    }
}

void Restaurant::changeCustomerCredentials()
{
    std::cout << "Changing Customer Credentials" << std::endl;

    for (Customer &customer : customers)
    {
        if (customerLoggedInId == customer.getId())
        {
            std::string enteredName{};
            std::string enteredPassword{};

            std::cout << "Enter Name: ";
            std::getline(std::cin, enteredName);

            std::cout << "Enter Password: ";
            enteredPassword = getPasswordInput();

            customer.setName(enteredName);
            customer.setPassword(enteredPassword);

            break;
        }
    }

    writeCustomers();
    std::cout << "Successful" << std::endl;
    Sleep(1500);
}

void Restaurant::manageRestaurantServices()
{
    clearScreen();
    char choice;
    do
    {
        clearScreen();
        std::cout << "1. Add Tables" << std::endl;
        std::cout << "2. Remove Table" << std::endl;
        std::cout << "3. Add Item to Menu" << std::endl;
        std::cout << "4. Remove Item from Menu" << std::endl;
        std::cout << "5. Change Item in Menu" << std::endl;
        std::cout << "6. Print Customers" << std::endl;
        std::cout << "7. Print Tables" << std::endl;
        std::cout << "8. Print Orders" << std::endl;
        std::cout << "9. Change Credentials" << std::endl;
        std::cout << "L. lucky Draw" << std::endl;
        std::cout << "0. Sign Out" << std::endl;

        std::cout << "Choose: ";
        std::cin >> choice;
        std::cin.ignore();

        clearScreen();
        switch (choice)
        {
        case '1':
            addTables();
            break;
        case '2':
            removeTable();
            break;
        case '3':
            addItemToMenu();
            break;
        case '4':
            removeItemFromMenu();
            break;
        case '5':
            changeItemInMenu();
            break;
        case '6':
            printCustomers();
            break;
        case '7':
            printTables();
            break;
        case '8':
            printOrders();
            break;
        case '9':
            changeAdminCredentials();
            break;
        case 'L':
        case 'l':
            luckyDraw();
            break;
        case '0':
            std::cout << "Signing Out..." << std::endl;
            Sleep(1500);
            break;
        default:
            std::cout << "Invalid Choice!" << std::endl;
            Sleep(1500);
            break;
        }
    } while (choice != '0');
}

void Restaurant::useRestaurantServices()
{
    clearScreen();
    char choice;
    do
    {
        std::cout << "1. Print Menu" << std::endl;
        std::cout << "2. Add Item to Order" << std::endl;
        std::cout << "3. Remove Item from Order" << std::endl;
        std::cout << "4. Print Order Cart" << std::endl;
        std::cout << "5. Print Order History" << std::endl;
        std::cout << "6. Pay Bill" << std::endl;
        std::cout << "7. Reserve Table" << std::endl;
        std::cout << "8. Free Tables" << std::endl;
        std::cout << "9. Change Credentials" << std::endl;
        std::cout << "0. Sign Out" << std::endl;

        std::cout << "Choose: ";
        std::cin >> choice;
        std::cin.ignore();

        clearScreen();
        switch (choice)
        {
        case '1':
            printMenu();
            break;
        case '2':
            addItemToOrder();
            break;
        case '3':
            removeItemFromOrder();
            break;
        case '4':
            printOrderCart();
            break;
        case '5':
            printOrderHistory();
            break;
        case '6':
            payBill();
            break;
        case '7':
            reserveTable();
            break;
        case '8':
            freeTables();
            break;
        case '9':
            changeCustomerCredentials();
            break;
        case '0':
            std::cout << "Signing Out..." << std::endl;
            Sleep(1500);
            break;
        default:
            std::cout << "Invalid Choice!" << std::endl;
            Sleep(1500);
            break;
        }
    } while (choice != '0');
}

int Restaurant::luckyDraw()
{
    std::vector<int> participantsId;
    for (const auto &order : orders)
    {
        int tempId = order.getOrderForId();
        participantsId.push_back(tempId);
    }
    int winner;
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(0, participantsId.size() - 1);

    int randomIndex = dist(gen);

    std::cout << "Winning ID is " << participantsId[randomIndex] << std::endl;
    Sleep(2000);

    return winner;
}

void Restaurant::writeAdmin()
{
    std::ofstream output("admin.bin", std::ios::binary);
    if (!output.is_open())
    {
        std::cout << "Error: Unable to open file for writing admin." << std::endl;
    }

    const std::string &adminName = admin.getName();
    int nameLength = adminName.length();
    output.write(reinterpret_cast<const char *>(&nameLength), sizeof(int));
    output.write(adminName.c_str(), nameLength);

    const std::string &adminPassword = admin.getPassword();
    int passwordLength = adminPassword.length();
    output.write(reinterpret_cast<const char *>(&passwordLength), sizeof(int));
    output.write(adminPassword.c_str(), passwordLength);

    output.close();
}

void Restaurant::readAdmin()
{
    std::ifstream input("admin.bin", std::ios::binary);
    if (!input.is_open())
    {
        std::cout << "Error: Unable to open file for reading admin." << std::endl;
    }

    int nameLength;
    input.read(reinterpret_cast<char *>(&nameLength), sizeof(int));
    char *nameBuffer = new char[nameLength];
    input.read(nameBuffer, nameLength);
    std::string adminName(nameBuffer, nameLength);
    delete[] nameBuffer;
    admin.setName(adminName);

    int passwordLength;
    input.read(reinterpret_cast<char *>(&passwordLength), sizeof(int));
    char *passwordBuffer = new char[passwordLength];
    input.read(passwordBuffer, passwordLength);
    std::string adminPassword(passwordBuffer, passwordLength);
    delete[] passwordBuffer;
    admin.setPassword(adminPassword);
    admin.setAccountType("ADMIN");

    input.close();
}

void Restaurant::writeCustomers()
{
    std::ofstream output("customers.bin", std::ios::binary);
    if (output.is_open())
    {
        int numCustomers = customers.size();
        output.write(reinterpret_cast<const char *>(&numCustomers), sizeof(int));

        for (const auto &customer : customers)
        {
            unsigned long id = customer.getId();
            output.write(reinterpret_cast<const char *>(&id), sizeof(unsigned long));

            const std::string &name = customer.getName();
            int nameLength = name.length();
            output.write(reinterpret_cast<const char *>(&nameLength), sizeof(int));
            output.write(name.c_str(), nameLength);

            const std::string &password = customer.getPassword();
            int passwordLength = password.length();
            output.write(reinterpret_cast<const char *>(&passwordLength), sizeof(int));
            output.write(password.c_str(), passwordLength);
        }

        output.close();
    }
    else
    {
        std::cout << "Error: Unable to open file for writing customers." << std::endl;
    }
}

void Restaurant::readCustomers()
{
    std::ifstream input("customers.bin", std::ios::binary);
    if (input.is_open())
    {
        int numCustomers;
        input.read(reinterpret_cast<char *>(&numCustomers), sizeof(int));

        for (int i = 0; i < numCustomers; ++i)
        {
            unsigned long id;
            input.read(reinterpret_cast<char *>(&id), sizeof(unsigned long));

            int nameLength;
            input.read(reinterpret_cast<char *>(&nameLength), sizeof(int));
            char *nameBuffer = new char[nameLength];
            input.read(nameBuffer, nameLength);
            std::string name(nameBuffer, nameLength);
            delete[] nameBuffer;

            int passwordLength;
            input.read(reinterpret_cast<char *>(&passwordLength), sizeof(int));
            char *passwordBuffer = new char[passwordLength];
            input.read(passwordBuffer, passwordLength);
            std::string password(passwordBuffer, passwordLength);
            delete[] passwordBuffer;

            Customer customer;
            customer.setId(id);
            customer.setName(name);
            customer.setPassword(password);
            customer.setAccountType("Customer");
            customers.push_back(customer);
        }

        input.close();
    }
    else
    {
        std::cout << "Error: Unable to open file for reading customers." << std::endl;
    }
}

void Restaurant::writeMenu()
{
    std::ofstream output("menu.bin", std::ios::binary);
    if (!output.is_open())
    {
        std::cout << "Error: Unable to open file for writing menu." << std::endl;
    }

    int numItems = menu.getItemsCount();
    output.write(reinterpret_cast<const char *>(&numItems), sizeof(int));

    for (const auto &item : menu.getItems())
    {
        unsigned long itemId = item.getId();
        output.write(reinterpret_cast<const char *>(&itemId), sizeof(unsigned long));

        const std::string &itemName = item.getName();
        int nameLength = itemName.length();
        output.write(reinterpret_cast<const char *>(&nameLength), sizeof(int));
        output.write(itemName.c_str(), nameLength);

        double itemPrice = item.getPrice();
        output.write(reinterpret_cast<const char *>(&itemPrice), sizeof(double));
    }

    output.close();
}

void Restaurant::readMenu()
{
    std::ifstream input("menu.bin", std::ios::binary);
    if (!input.is_open())
    {
        std::cout << "Error: Unable to open file for reading menu." << std::endl;
    }

    int numItems;
    input.read(reinterpret_cast<char *>(&numItems), sizeof(int));

    for (int i = 0; i < numItems; ++i)
    {
        unsigned long itemId;
        input.read(reinterpret_cast<char *>(&itemId), sizeof(unsigned long));

        int nameLength;
        input.read(reinterpret_cast<char *>(&nameLength), sizeof(int));
        char *nameBuffer = new char[nameLength];
        input.read(nameBuffer, nameLength);
        std::string itemName(nameBuffer, nameLength);
        delete[] nameBuffer;

        double itemPrice;
        input.read(reinterpret_cast<char *>(&itemPrice), sizeof(double));

        menu.addItem(itemId, itemName, itemPrice);
    }

    input.close();
}

void Restaurant::writeOrders()
{
    std::ofstream output("orders.bin", std::ios::binary);
    if (output.is_open())
    {
        int numOrders = orders.size();
        output.write(reinterpret_cast<const char *>(&numOrders), sizeof(int));

        for (const auto &order : orders)
        {
            unsigned long id = order.getId();
            output.write(reinterpret_cast<const char *>(&id), sizeof(unsigned long));

            const std::string &name = order.getName();
            int nameLength = name.length();
            output.write(reinterpret_cast<const char *>(&nameLength), sizeof(int));
            output.write(name.c_str(), nameLength);

            double price = order.getPrice();
            output.write(reinterpret_cast<const char *>(&price), sizeof(double));

            unsigned long orderForId = order.getOrderForId();
            output.write(reinterpret_cast<const char *>(&orderForId), sizeof(unsigned long));

            unsigned long quantity = order.getQuantity();
            output.write(reinterpret_cast<const char *>(&quantity), sizeof(unsigned long));

            bool isCompleted = order.getIsCompleted();
            output.write(reinterpret_cast<const char *>(&isCompleted), sizeof(bool));
        }

        output.close();
    }
    else
    {
        std::cout << "Error: Unable to open file for writing orders." << std::endl;
    }
}

void Restaurant::readOrders()
{
    std::ifstream input("orders.bin", std::ios::binary);
    if (input.is_open())
    {
        int numOrders;
        input.read(reinterpret_cast<char *>(&numOrders), sizeof(int));

        for (int i = 0; i < numOrders; ++i)
        {
            unsigned long id;
            input.read(reinterpret_cast<char *>(&id), sizeof(unsigned long));

            int nameLength;
            input.read(reinterpret_cast<char *>(&nameLength), sizeof(int));
            char *nameBuffer = new char[nameLength];
            input.read(nameBuffer, nameLength);
            std::string name(nameBuffer, nameLength);
            delete[] nameBuffer;

            double price;
            input.read(reinterpret_cast<char *>(&price), sizeof(double));

            unsigned long orderForId;
            input.read(reinterpret_cast<char *>(&orderForId), sizeof(unsigned long));

            unsigned long quantity;
            input.read(reinterpret_cast<char *>(&quantity), sizeof(unsigned long));

            bool isCompleted;
            input.read(reinterpret_cast<char *>(&isCompleted), sizeof(bool));

            OrderItem order(name, price);
            order.setId(id);
            order.setOrderForId(orderForId);
            order.setQuantity(quantity);
            order.setIsCompleted(isCompleted);
            orders.push_back(order);
        }

        input.close();
    }
    else
    {
        std::cout << "Error: Unable to open file for reading orders." << std::endl;
    }
}

void Restaurant::writeTables()
{
    std::ofstream output("tables.bin", std::ios::binary);
    if (output.is_open())
    {
        int numTables = tables.size();
        output.write(reinterpret_cast<const char *>(&numTables), sizeof(int));

        for (const auto &table : tables)
        {
            unsigned long id = table.getId();
            output.write(reinterpret_cast<const char *>(&id), sizeof(unsigned long));

            unsigned long reservedForId = table.getReservedForId();
            output.write(reinterpret_cast<const char *>(&reservedForId), sizeof(unsigned long));
        }

        output.close();
    }
    else
    {
        std::cout << "Error: Unable to open file for writing tables." << std::endl;
    }
}
void Restaurant::readTables()
{
    std::ifstream input("tables.bin", std::ios::binary);
    if (input.is_open())
    {
        int numTables;
        input.read(reinterpret_cast<char *>(&numTables), sizeof(int));

        for (int i = 0; i < numTables; ++i)
        {
            unsigned long id;
            input.read(reinterpret_cast<char *>(&id), sizeof(unsigned long));

            unsigned long reservedForId;
            input.read(reinterpret_cast<char *>(&reservedForId), sizeof(unsigned long));

            Table table;
            table.setId(id);
            table.setReservedForId(reservedForId);
            tables.push_back(table);
        }

        input.close();
    }
    else
    {
        std::cout << "Error: Unable to open file for reading tables." << std::endl;
    }
}

std::string getPasswordInput()
{
    std::string password;
    char c;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD consoleMode;
    GetConsoleMode(hConsole, &consoleMode);
    SetConsoleMode(hConsole, consoleMode & (~ENABLE_ECHO_INPUT));

    while ((c = _getch()) != '\r')
    {
        if (c == '\b')
        {
            if (!password.empty())
            {
                password.pop_back();
                std::cout << "\b \b";
            }
        }
        else
        {
            password.push_back(c);
            std::cout << "*";
        }
    }

    SetConsoleMode(hConsole, consoleMode);
    std::cout << std::endl;
    return password;
}
void clearScreen()
{
    system("cls");
}
void pauseScreen()
{
    system("pause");
}
void loadingScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    char spinningCursor[] = {'|', '/', '-', '\\'};

    for (int i = 0; i <= 20; i++)
    {
        clearScreen();
        std::cout << "\n\n\t";
        std::cout << "Loading [ ";
        for (int j = 0; j < i; j++)
        {
            std::cout << "\xDB";
        }
        for (int j = 0; j <= 20 - i; j++)
        {
            std::cout << " ";
        }
        std::cout << "] " << spinningCursor[i % 4] << " " << i * 5 << "%" << std::endl;
    }
    std::cout << "\n\n\n\nLoading completed..." << std::endl;
    Sleep(300);
    pauseScreen();
    system("cls");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
