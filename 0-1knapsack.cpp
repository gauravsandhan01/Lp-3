#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item with weight and value
struct Item 
{
    int value, weight;

    // Constructor for convenience
    Item(int value, int weight) : value(value), weight(weight) {}
};

// Function to solve the 0-1 knapsack problem using dynamic programming
int knapsack01(int W, vector<Item>& items) 
{
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the dp table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (items[i - 1].weight <= w) {
                // Include the item or exclude it, whichever gives higher value
                dp[i][w] = max(dp[i - 1][w], items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
            } else {
                // Cannot include the item, so carry forward the previous value
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value for the knapsack is stored in dp[n][W]
    return dp[n][W];
}

int main() 
{
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the maximum weight of the knapsack: ";
    cin >> W;

    vector<Item> items;
    cout << "Enter the value and weight of each item:\n";
    for (int i = 0; i < n; i++) 
    {
        int value, weight;
        cout << "Value and weight for item " << i + 1 << ": ";
        cin >> value >> weight;
        items.emplace_back(value, weight);
    }

    int maxValue = knapsack01(W, items);
    cout << "The maximum value in the knapsack is: " << maxValue << endl;

    return 0;
}
