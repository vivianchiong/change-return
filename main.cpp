#include <iostream>

#include "change-return.cpp"

template <typename T>
void enterInput(const std::string& str, T& arg)  {
    do {
        if (std::cout << str && std::cin >> arg) break;
        std::cout << "Invalid input, please re-enter ... " << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main(int argc, char* const argv[]) {
    double cost = 0.0;
    double moneyGiven = 0.0;
    double change = 0.0;
    int dollars = 0;
    int currCents = 0;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;

    enterInput<double>("Cost: $", cost);

    while (true) {
        enterInput<double>("Cash given: $", moneyGiven);
        if (moneyGiven < cost) {
            std::cout << "Not enough cash! Please re-enter ... " << std::endl;
        } else {
            break;
        }
    }

    change = moneyGiven - cost;
    dollars = static_cast<int>(change);
    currCents = static_cast<int>((change - dollars) * 100);
    quarters = getCoins(currCents, 25);
    dimes = getCoins(currCents, 10);
    nickels = getCoins(currCents, 5);

    print(change, dollars, quarters, dimes, nickels, currCents);
}