#ifndef A7_STEFAN_CODE_ENG1_REPOEXCEPTION_H
#define A7_STEFAN_CODE_ENG1_REPOEXCEPTION_H

#include <exception>

class RepoException: public std::exception{
public:
    const char* error;
    explicit RepoException(const char* error);

    const char*what() const noexcept override{return this->error;};
};


#endif //A7_STEFAN_CODE_ENG1_REPOEXCEPTION_H
