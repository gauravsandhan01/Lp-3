#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item with weight and value
struct Item {
    int value, weight;

    // Constructor for convenience
    Item(int value, int weight) : value(value), weight(weight) {}
};

// Comparator function to sort items by value-to-weight ratio in descending order
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items based on value-to-weight ratio in descending order
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;  // Total value accumulated in the knapsack

    for (auto& item : items) {
        // If the item can fit in the knapsack, take it all
        if (W >= item.weight) {
            W -= item.weight;
            totalValue += item.value;
        }
        // If the item cannot fit, take the fractional part of it
        else {
            totalValue += item.value * ((double)W / item.weight);
            break;  // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the maximum weight of the knapsack: ";
    cin >> W;

    vector<Item> items;
    cout << "Enter the value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        int value, weight;
        cout << "Value and weight for item " << i + 1 << ": ";
        cin >> value >> weight;
        items.emplace_back(value, weight);
    }

    double maxValue = fractionalKnapsack(W, items);
    cout << "The maximum value in the knapsack is: " << maxValue << endl;

    return 0;
}