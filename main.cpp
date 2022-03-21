#include "creditCardValidator.hpp"

int main() {
    long cardNum = 0;
    std::string cvvNum, expDate;
    std::cout << "Write down your credit card number, please: ";
    std::cin >> cardNum;
    std::cout << "Now proceed to write down your CVV code: ";
    std::cin >> cvvNum;
    std::cout << "And lastly write down your expiration date in following format MM/YY: ";
    std::cin >> expDate;
    CreditCard card(cardNum, cvvNum, expDate);
    if(card.checkCardNumber()) {
        if(card.checkCVV()) {
            if(card.checkExpDate()) {
                std::cout << "Data you provided is valid credit card data.\n";
                return 0;
            }
            std::cout << "Your expiration date has passed.\n";
            return 0;
        }
        std::cout << "Your CVV code does not match CVV format.\n";
        return 0;
    }
    std::cout << "Your credit card's number is invalid.\n";
    return 0;
}