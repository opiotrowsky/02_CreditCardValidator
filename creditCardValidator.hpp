#pragma once
#include <string>
#include <vector>
#include <iostream>

class CreditCard {
    long intCardNumber_;
    std::string CVV_;
    std::string expDate_;

public:
    CreditCard() {}
    CreditCard(long intCardNumber, std::string CVV, std::string expDate)
        : intCardNumber_(intCardNumber)
        , CVV_(CVV)
        , expDate_(expDate)
        {}
    ~CreditCard() {}


    bool checkCardNumber();
    // bool checkCVV();
    // bool checkExpDate();
};