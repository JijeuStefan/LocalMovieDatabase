#ifndef A45_STEFAN_CODE_ENG1_REPO_H
#define A45_STEFAN_CODE_ENG1_REPO_H

#include "iostream"
#include "vector"
#include "algorithm"
#include "../Domain/Movie.h"
#include "../Exceptions/RepoException.h"

template <typename Elem>
class Repo {

protected:
    std::vector<Elem> repo;

public:
    Repo();

    bool find_id(const std::string&, int year);

    virtual void add(Elem elem);

    virtual void remove(std::string title, int year);

    virtual void update(Elem elem);

    int size();

    std::vector<Elem> get_repo();

};

template<typename Elem>
Repo<Elem>::Repo() {
    this->repo = std::vector<Elem>();
}

template<typename Elem>
bool Repo<Elem>::find_id(const std::string& title, int year) {
    auto find = [&title,&year](Elem movie){return movie.get_title() == title && movie.get_year() == year;};
    return std::find_if(this->repo.begin(), this->repo.end(),find) != this->repo.end();
}

template<typename Elem>
void Repo<Elem>::add(Elem elem) {
    if (this->find_id(elem.get_title(), elem.get_year())) {
        throw RepoException("\nMovie already added!\n");
    }
    this->repo.push_back(elem);
}

template<typename Elem>
void Repo<Elem>::remove(std::string title, int year) {
    if (!this->find_id(title, year)) {
        throw RepoException("\nMovie doesn't exist!\n");
    }
    auto find = [&title, &year](Elem elem){return elem.get_title()==title && elem.get_year()==year;};
    auto iterator = std::remove_if(this->repo.begin(), this->repo.end(), find);
    this->repo.erase(iterator, this->repo.end());
}

template<typename Elem>
void Repo<Elem>::update(Elem elem) {
    if (!this->find_id(elem.get_title(), elem.get_year())) {
        throw RepoException("\nMovie doesn't exist!\n");
    }
    auto find = [&elem](Elem var){return var.get_title()==elem.get_title() && var.get_year()==elem.get_year();};
    auto iterator = std::remove_if(this->repo.begin(), this->repo.end(), find);
    this->repo.erase(iterator, this->repo.end());

    this->repo.push_back(elem);
}

template<typename Elem>
int Repo<Elem>::size() {
    return this->repo.size();
}

template<typename Elem>
std::vector<Elem> Repo<Elem>::get_repo() {
    return this->repo;
}


#endif //A45_STEFAN_CODE_ENG1_REPO_H
