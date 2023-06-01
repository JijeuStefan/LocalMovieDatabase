#ifndef A45_STEFAN_CODE_ENG1_USERREPO_H
#define A45_STEFAN_CODE_ENG1_USERREPO_H

#include "iostream"
#include "vector"
#include "algorithm"
#include "../Exceptions/RepoException.h"

template <typename Elem>
class UserRepo {
protected:
    std::vector<Elem> repo;

public:
    UserRepo();

    virtual ~UserRepo() = default;

    bool find_id(const std::string&, int year);

    Elem find_by_id(const std::string&, int year);

    virtual void add(Elem elem);

    virtual void remove(std::string title, int year);

    virtual void update(Elem elem);

    int size();

    std::vector<Elem> get_repo();

    virtual std::string return_file() = 0;

};

template<typename Elem>
UserRepo<Elem>::UserRepo() {
    this->repo = std::vector<Elem>();
}

template<typename Elem>
bool UserRepo<Elem>::find_id(const std::string& title, int year) {
    auto find = [&title,&year](Elem movie){return movie.get_title() == title && movie.get_year() == year;};
    return std::find_if(this->repo.begin(), this->repo.end(),find) != this->repo.end();
}

template<typename Elem>
Elem UserRepo<Elem>::find_by_id(const std::string &title, int year) {
    for(Elem movie: this->repo)
        if(movie.get_title() == title && movie.get_year() == year)
            return movie;
    return Elem();
}

template<typename Elem>
void UserRepo<Elem>::add(Elem elem) {
    if (this->find_id(elem.get_title(), elem.get_year())) {
        throw RepoException("Movie already added!\n");
    }
    this->repo.push_back(elem);
}

template<typename Elem>
void UserRepo<Elem>::remove(std::string title, int year) {
    if (!this->find_id(title, year)) {
        throw RepoException("\nMovie doesn't exist!\n");

    }
    auto find = [&title, &year](Elem elem){return elem.get_title()==title && elem.get_year()==year;};
    auto iterator = std::remove_if(this->repo.begin(), this->repo.end(), find);
    this->repo.erase(iterator, this->repo.end());
}

template<typename Elem>
void UserRepo<Elem>::update(Elem elem) {
    if (!this->find_id(elem.get_title(), elem.get_year())) {
        throw RepoException("\nMovie doesn't exist!\n");
    }
    auto find = [&elem](Elem var){return var.get_title()==elem.get_title() && var.get_year()==elem.get_year();};
    auto iterator = std::remove_if(this->repo.begin(), this->repo.end(), find);
    this->repo.erase(iterator, this->repo.end());

    this->repo.push_back(elem);
}

template<typename Elem>
int UserRepo<Elem>::size() {
    return this->repo.size();
}

template<typename Elem>
std::vector<Elem> UserRepo<Elem>::get_repo() {
    return this->repo;
}

#endif //A45_STEFAN_CODE_ENG1_USERREPO_H
