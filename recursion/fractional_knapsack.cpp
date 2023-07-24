#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
    double valuePerWeight;
};

bool compareItems(const Item& item1, const Item& item2) {
    return item1.valuePerWeight > item2.valuePerWeight;
}

double fractionalKnapsack(int capacity, std::vector<Item>& items) {
    // Sort items based on value per weight in descending order
    std::sort(items.begin(), items.end(), compareItems);
    double totalValue = 0.0;
    int remainingCapacity = capacity;

    for (const auto& item : items) {
        // Check if the item can be fully added to the knapsack
        if (remainingCapacity >= item.weight) {
            totalValue += item.value;
            remainingCapacity -= item.weight;
            std::cout << item.value << std::endl;
        } else {
            // Add a fraction of the item to the knapsack
            double fraction = static_cast<double>(remainingCapacity) / item.weight;
            totalValue += fraction * item.value;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;
    std::cout << "Enter the number of items: ";
    std::cin >> n;
    std::cout << "Enter the capacity of the knapsack: ";
    std::cin >> capacity;

    std::vector<Item> items(n);
    std::cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> items[i].weight >> items[i].value;
        items[i].valuePerWeight = static_cast<double>(items[i].value) / items[i].weight;
    }

    double maxTotalValue = fractionalKnapsack(capacity, items);

    std::cout << "Maximum value that can be obtained: " << maxTotalValue << std::endl;

    return 0;
}

//profit 12 weight 3 
//profit 7 weight 2 
//profit 18 weight 7 
//profit 5 wieght 2 
//profit 9 weight 3 
//profit 10 weight 5 
