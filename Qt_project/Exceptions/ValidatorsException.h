#ifndef A7_STEFAN_CODE_ENG1_VALIDATORSEXCEPTION_H
#define A7_STEFAN_CODE_ENG1_VALIDATORSEXCEPTION_H

#include "exception"

class ValidatorsException: public std::exception{
public:
    const char* error;
    explicit ValidatorsException(const char* error);

    const char*what() const noexcept override{return this->error;};
};


#endif //A7_STEFAN_CODE_ENG1_VALIDATORSEXCEPTION_H
