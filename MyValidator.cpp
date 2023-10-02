#include "MyValidator.hpp"

bool MyValidator::isMonth(unsigned int inputMonth) const {
    if (1 <= inputMonth && inputMonth <= 12) {
        return true;
    }
    return false;   
}

bool MyValidator::isOver(unsigned int targetAge) const {
    try {
        if (db->getMinAge() <= targetAge) {
            return true;
        }
        return false;
    } catch (const std::exception& e) {
        return false;            
    }
}

int MyValidator::privateAdd(int val1, int val2) const {
    return val1 + val2;
}
