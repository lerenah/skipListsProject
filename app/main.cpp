#include "../SkipList.h"
#include <iostream>

using namespace std;

void displayMenu(){
    cout << endl;
    cout << "********** TOP STOCKS *******" << endl;
    cout << "Welcome to High Stocks! Here are your choices:" << endl;
    cout << "1. View highest stock price" << endl;
    cout << "2. Enter a stock price" << endl;
    cout << "3. Remove a stock price" << endl;
    cout << "4. Print SkipList" << endl;
    cout << "5. Search for a stock" << endl;
    cout << "6. Quit" << endl;
    cout << "********** TOP STOCKS *******" << endl;
    cout << endl;
    cout << "Enter your choice: ";
}

int main() {
    SkipList list;
    
    int choice;
    bool quit = false;

    while (!quit) {
        displayMenu();
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(choice) {
            case 1: {
                int highestPrice = list.getHighestPrice();
                if (highestPrice != -1) {
                    cout << "Highest stock price: " << highestPrice << endl;
                } else {
                    cout << "No data available." << endl;
                }
                break;
            } 
            case 2: {
                string ticker;
                int price;
                cout << "Enter the ticker symbol: ";
                getline(cin, ticker);
                cout << "Enter the stock price: ";
                cin >> price;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                list.insert(std::make_pair(ticker, price));
                break;
            }
            case 3: {
                string ticker;
                cout << "Enter ticker symbol to delete: ";
                getline(cin, ticker);
                if (list.deleteNode(ticker)) {
                    cout << "Stock price for " << ticker << " deleted." << endl;
                } else {
                    cout << "Stock price for " << ticker << " not found." << endl;
                }
                break;
            }
            case 4: {
                cout << "Printing SkipList..." << endl;
                list.print();
                break;
            }
            case 5: {
                string ticker;
                cout << "Enter ticker symbol to search: ";
                getline(cin, ticker);
                if (list.search(ticker)) {
                    cout << "Stock " << ticker << " is available in the SkipList." << endl;
                } else {
                    cout << "Stock " << ticker << " is not found." << endl;
                }
                break;
            }
            case 6: {
                cout << "Exiting..." << endl;
                quit = true;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}
