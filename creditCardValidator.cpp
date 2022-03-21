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

bool CreditCard::checkExpDate() {
    std::regex datepattern("^(0[1-9]|1[0-2])/([0-9][0-9])$");
    std::time_t now = std::time(nullptr);
    auto tm = *std::localtime(&now);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%m/%y");
    std::string today = oss.str();
    int todm = today[0] * 10 + today[1], expm = expDate_[0] * 10 + expDate_[1], tody = today[3] * 10 + today[4], expy = expDate_[3] * 10 + expDate_[4];

    return (std::regex_match(expDate_, datepattern) and (todm <= expm and tody <= expy));
}