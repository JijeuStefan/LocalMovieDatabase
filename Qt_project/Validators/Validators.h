#ifndef A7_STEFAN_CODE_ENG1_VALIDATORS_H
#define A7_STEFAN_CODE_ENG1_VALIDATORS_H


#include <string>

class Validators {
public:
    static void validate_year(int year);

    static void validate_genre(const std::string& genre);

    static void validate_trailer(const std::string& trailer);
};


#endif //A7_STEFAN_CODE_ENG1_VALIDATORS_H
