#ifndef A45_STEFAN_CODE_ENG1_CONTROLLER_H
#define A45_STEFAN_CODE_ENG1_CONTROLLER_H


#include "../Repo/Repo.h"
#include "../Validators/Validators.h"
#include "User.h"

template <typename Elem>
class Admin {
private:
    Repo<Elem>& repo;
    User<Elem>& user;
public:
    explicit Admin(Repo<Elem>& repo,User<Elem>& user);

    void add(Elem elem);

    void remove(const std::string& title, int year);

    void update(Elem elem);

    int get_size();

    std::vector<Elem> get_movies();

    bool watchlist_find_by_id(const std::string& title, int year);

    void remove_from_watchlist(const std::string& title, int year);

    void update_watchlist(Elem elem);
};

template <typename Elem>
Admin<Elem>::Admin(Repo<Elem> &repo,User<Elem>& user): repo(repo),user(user) {}

template <typename Elem>
void Admin<Elem>::add(Elem elem) {
    Validators::validate_genre(elem.get_genre());
    Validators::validate_year(elem.get_year());
    Validators::validate_trailer(elem.get_trailer());
    this->repo.add(std::move(elem));

}

template <typename Elem>
void Admin<Elem>::remove(const std::string &title, int year) {
    this->repo.remove(title,year);
}

template <typename Elem>
void Admin<Elem>::update(Elem elem) {
    this->repo.update(std::move(elem));
}

template <typename Elem>
int Admin<Elem>::get_size() {
    return this->repo.size();
}

template <typename Elem>
std::vector<Elem> Admin<Elem>::get_movies() {
    return this->repo.get_repo();
}

template<typename Elem>
bool Admin<Elem>::watchlist_find_by_id(const std::string& title, int year) {
    return this->user.find_id(title,year);;
}

template<typename Elem>
void Admin<Elem>::remove_from_watchlist(const std::string &title, int year) {
    this->user.remove(title,year);
}

template<typename Elem>
void Admin<Elem>::update_watchlist(Elem elem) {
    this->user.update(elem);
}

#endif //A45_STEFAN_CODE_ENG1_CONTROLLER_H
