#include "RepoException.h"

RepoException::RepoException(const char* error) {
    this->error = error;
}
