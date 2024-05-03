# Skip List Implementation in C++

## Overview

This Skip List implementation offers a way to manage stock price data. It enhances the traditional linked list by introducing "express lanes" for faster traversal, achieving logarithmic time complexity for operations like search, insertion, and deletion.


## Implementation Details

### Classes

- **Node**: Represents an individual node in the skip list. Each node holds a pair consisting of a string (ticker symbol) and an integer (stock price), and has multiple forward pointers (next) for various levels of the skip list. The maxData attribute stores the maximum stock price in the sublist starting from this node.
- **SkipList**: Manages the overall skip list data structure. It supports operations for inserting new stock prices, deleting existing ones, searching for stock prices by ticker symbol, and retrieving the highest stock price across all nodes.

### Key Methods

- `insert(std::pair<std::string, int> data)`: Inserts a new stock entry into the skip list. The entry includes a ticker symbol and a stock price. The new node is inserted at random levels to maintain skip list properties.

- `search(std::string ticker)`: Searches for a stock by its ticker symbol in the skip list. Returns true if the stock is found, and false otherwise. This method checks through the levels efficiently using the skip list's layered structure.

- `deleteNode(std::string ticker)`: Removes a stock entry from the skip list based on its ticker symbol. This method ensures the node is removed from all levels where it appears, maintaining the integrity of the skip list.

- `getHighestPrice()`: Retrieves the highest stock price currently stored in the skip list. This method traverses the top level of the skip list to find the maximum value efficiently.

## Compilation and Running

To run the program, use the following commands:

```
cd app

g++ -o main main.cpp ../SkipList.cpp ../Node.cpp

./main
```

## Example Usage

To interact with the Skip List, run main executable. It will display a menu with the following options:

1. **View highest stock price**: Displays the highest stock price currently stored in the Skip List.
2. **Enter a stock price**: Allows you to enter a new stock price to be added to the Skip List.
3. **Remove a stock price**: Enables deletion of a stock price from the Skip List.
4. **Print SkipList**: Prints the full Skip List.
5. **Search for a stock**: Identifies whether or not a stock is in the Skip List.
6. **Quit**: Exits the program.

Follow the prompts to select an option and interact with the Skip List accordingly.

Here is a simple iteration of the list:

```
********** TOP STOCKS *******
Welcome to High Stocks! Here are your choices:
1. View highest stock price
2. Enter a stock price
3. Remove a stock price
4. Print SkipList
5. Search for a stock
6. Quit
********** TOP STOCKS *******

Enter your choice: 2
Enter the ticker symbol: AAPL
Enter the stock price: 150

********** TOP STOCKS *******
Welcome to High Stocks! Here are your choices:
1. View highest stock price
2. Enter a stock price
3. Remove a stock price
4. Print SkipList
5. Search for a stock
6. Quit
********** TOP STOCKS *******

Enter your choice: 2
Enter the ticker symbol: MSFT
Enter the stock price: 280

********** TOP STOCKS *******
Welcome to High Stocks! Here are your choices:
1. View highest stock price
2. Enter a stock price
3. Remove a stock price
4. Print SkipList
5. Search for a stock
6. Quit
********** TOP STOCKS *******

Enter your choice: 2
Enter the ticker symbol: GOOG
Enter the stock price: 1200

********** TOP STOCKS *******
Welcome to High Stocks! Here are your choices:
1. View highest stock price
2. Enter a stock price
3. Remove a stock price
4. Print SkipList
5. Search for a stock
6. Quit
********** TOP STOCKS *******

Enter your choice: 2
Enter the ticker symbol: AMZN
Enter the stock price: 105

********** TOP STOCKS *******
Welcome to High Stocks! Here are your choices:
1. View highest stock price
2. Enter a stock price
3. Remove a stock price
4. Print SkipList
5. Search for a stock
6. Quit
********** TOP STOCKS *******

Enter your choice: 2
Enter the ticker symbol: TSLA
Enter the stock price: 800

********** TOP STOCKS *******
Welcome to High Stocks! Here are your choices:
1. View highest stock price
2. Enter a stock price
3. Remove a stock price
4. Print SkipList
5. Search for a stock
6. Quit
********** TOP STOCKS *******

Enter your choice: 1
Highest stock price: 1200

********** TOP STOCKS *******
Welcome to High Stocks! Here are your choices:
1. View highest stock price
2. Enter a stock price
3. Remove a stock price
4. Print SkipList
5. Search for a stock
6. Quit
********** TOP STOCKS *******

Enter your choice: 4
Printing SkipList...
Level 5: 
Level 4: 
Level 3: (AMZN, 105) 
Level 2: (AMZN, 105) 
Level 1: (AMZN, 105) (AAPL, 150) 
Level 0: (AMZN, 105) (AAPL, 150) (MSFT, 280) (TSLA, 800) (GOOG, 1200) 
```
