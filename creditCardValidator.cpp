#include "creditCardValidator.hpp"

bool CreditCard::checkCardNumber() {
    long cardNumCopy = intCardNumber_;
    int num = 0;
    while(cardNumCopy > 0) {
        cardNumCopy /= 10;
        num++;
    }
    if(num != 16) {
        return false;
    }

    std::vector<int> vecCardNumber;
    vecCardNumber.reserve(16);
    while(intCardNumber_ > 0) {
        vecCardNumber.push_back(intCardNumber_ % 10);
        intCardNumber_ /= 10;
    }
    
    long sum = 0;
    for(int i = 0; i < 15; ++i) {
        if(i % 2 == 0) {
            num = vecCardNumber[i];
        }
        if(i % 2 != 0) {
            num = vecCardNumber[i] * 2;
        }
        if(num > 9) {
            num -= 9;
        }
        sum += num;
    }
    sum += vecCardNumber[15];
    if(sum % 10 != 0) {
        return false;
    }
    return true;
}

// bool CreditCard::checkCVV() {
    
// }

// bool CreditCard::checkExpDate() {
    
// }