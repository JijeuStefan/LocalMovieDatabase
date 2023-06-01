#include "Validators.h"
#include "../Exceptions/ValidatorsException.h"

#include "vector"
#include "algorithm"

void Validators::validate_year(int year) {
    if (year < 1900 || year > 2023)
        throw ValidatorsException("Invalid year!\n");
}

void Validators::validate_genre(const std::string &genre) {
    std::vector<std::string> genres = {"Action","Comedy","Drama","Romance","Horror","Adventure","Fantasy","Documentary"};
    if (find(genres.begin(),genres.end(),genre) == genres.end())
        throw ValidatorsException("Invalid genre!\n");
}

void Validators::validate_trailer(const std::string &trailer) {
    if (trailer.substr(0,8) != "https://")
        throw ValidatorsException("Invalid web-site!\n");
}
