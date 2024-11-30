#include <iostream>
#include <cstring>
using namespace std;

typedef struct data {
    char type[16];
    int buy;
    int sell;
} Data;

class XMing_Garage {
private:
    Data carlist[6] = {
        {"BMW", 8000, 20000},
        {"Volkswagen", 7000, 18000},
        {"Ferrari", 12000, 35000},
        {"Proton", 4000, 50000},
        {"Audi", 10000, 30000},
        {"Lamborghini", 15000, 40000}
    };
    char Garage[10][16];
    int car;
    int sellprice;
    int totalcost;
    int earn;

public:
    XMing_Garage() { // Constructor
        Start_a_business();
    }

    void Start_a_business() {
        car = 0;
        sellprice = 0;
        totalcost = 0;
        earn = 0;
        memset(Garage, 0, sizeof(Garage));
    }

    void store(char x[16]) {
        if (car >= 10) {
            cout << "Garage FULL!\nCar not stored!\n";
            return;
        }

        int cost = 0;
        for (int i = 0; i < 6; i++) {
            if (strcmp(carlist[i].type, x) == 0) {
                cost = carlist[i].buy;
                totalcost += cost;
                // Profit decreases as we spend money to buy cars
                earn -= cost;
                sellprice += carlist[i].sell;
                break;
            }
        }

        strcpy(Garage[car], x);
        car++;
        cout << "Store in a car.\nType: " << x << "\nnumber car in garage: " << car << "\n";
    }

    void sell(char x[16]) {
        for (int i = 0; i < car; i++) {
            if (strcmp(Garage[i], x) == 0) {
                int salePrice = 0, cost = 0;
                for (int j = 0; j < 6; j++) {
                    if (strcmp(carlist[j].type, x) == 0) {
                        salePrice = carlist[j].sell;
                        cost = carlist[j].buy;
                        break;
                    }
                }

                earn += (salePrice - cost); // Update profit correctly
                sellprice -= salePrice;
                totalcost -= cost;

                for (int j = i; j < car - 1; j++) {
                    strcpy(Garage[j], Garage[j + 1]);
                }
                car--;

                cout << "You sell a car.\nType: " << x << "\nSell price: " << salePrice << "\nnumber car left in garage: " << car << "\n";
                return;
            }
        }
        cout << "Car not found!\n";
    }

    void displayi() {
        cout << "Sell price= " << sellprice << "\n";
    }

    void displaycost() {
        cout << "Total cost= " << totalcost << "\n";
    }

    void displayp() {
        cout << "Profit= " << earn << "\n";
    }
};

int main() {
    XMing_Garage garage;
    char command, carType[16];

    while (true) {
        cin >> command;
        switch (command) {
        case 'a': // Buy a car
            cin >> carType;
            garage.store(carType);
            garage.displaycost();
            break;
        case 's': // Sell a car
            cin >> carType;
            garage.sell(carType);
            garage.displaycost();
            break;
        case 'c': // Display total cost
            garage.displaycost();
            garage.displaycost();
            break;
        case 'i': // Display estimated selling price
            garage.displayi();
            garage.displaycost();
            break;
        case 'p': // Display total profit
            garage.displayp();
            garage.displaycost();
            break;
        case 'q': // Quit program
            cout << "Thank you for visiting XMing_Garage. Bye bye.\n";
            return 0;
        default:
            cout << "Invalid command.\n";
        }
    }
}