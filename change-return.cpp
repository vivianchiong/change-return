#include <iostream>
#include <iomanip>
#include <cfenv>

int getCoins(int& cents, const int coinValue) {
    int numCoins = static_cast<int>(cents / coinValue);
    cents = cents - numCoins * coinValue;
    return numCoins;
}

void print(double change,
        int dollars,
        int quarters,
        int dimes,
        int nickels,
        int pennies) {

    std::fesetround(FE_DOWNWARD);
    std::cout << std::fixed << std::setprecision(2) << std::endl;
    std::cout << "Change due: $" << change << std::endl;
    std::cout << "Dollars back: " << dollars << std::endl;
    std::cout << "Quarters back: " << quarters << std::endl;
    std::cout << "Dimes back: " << dimes << std::endl;
    std::cout << "Nickels back: " << nickels << std::endl;
    std::cout << "Pennies back: " << pennies << std::endl;
}