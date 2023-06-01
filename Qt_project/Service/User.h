#ifndef A45_STEFAN_CODE_ENG1_USER_H
#define A45_STEFAN_CODE_ENG1_USER_H

#include "../Repo/Repo.h"
#include "../Repo/UserRepo.h"
#include "../Validators/Validators.h"

template <typename Elem>
class User {
private:
    Repo<Elem>& repo;
    UserRepo<Elem>* user_repo;
public:

    explicit User(Repo<Elem>& repo, UserRepo<Elem>* user_repo);

    void add_user_repo(UserRepo<Elem>* userRepo);

    Elem find_by_id(const std::string& title, int year);

    bool find_id(const std::string &title, int year);

    void add(Elem elem);

    void remove(const std::string& title, int year);

    void update(Elem elem);

    int get_size();

    std::vector<Elem> get_movies_genre(const std::string& genre);

    std::vector<Elem> get_watch_list();

    void update_repo(Elem elem);

    std::string return_File();

    ~User();
};

template <typename Elem>
User<Elem>::User(Repo<Elem> &repo,UserRepo<Elem>* user_repo):repo(repo) {
    this->user_repo = user_repo;
}

template<typename Elem>
void User<Elem>::add_user_repo(UserRepo<Elem>* userRepo) {
    this->user_repo = userRepo;
}

template<typename Elem>
Elem User<Elem>::find_by_id(const std::string &title, int year) {
    return this->user_repo->find_by_id(title,year);
}

template<typename Elem>
bool User<Elem>::find_id(const std::string &title, int year) {
    return this->user_repo->find_id(title,year);
}

template<typename Elem>
void User<Elem>::add(Elem elem) {
    this->user_repo->add(elem);
}

template<typename Elem>
void User<Elem>::remove(const std::string& title, int year) {
    this->user_repo->remove(title,year);
}

template<typename Elem>
void User<Elem>::update(Elem elem) {
    this->user_repo->update(elem);
}

template<typename Elem>
int User<Elem>::get_size() {
    return this->user_repo->size();
}

template<typename Elem>
std::vector<Elem> User<Elem>::get_movies_genre(const std::string& genre) {
    std::vector<Elem> movies = this->repo.get_repo();
    std::vector<Elem> movie_list(this->repo.size());

    if (genre == "all")
        return this->repo.get_repo();

    auto it = std::copy_if(movies.begin(),movies.end(),movie_list.begin(),[&genre](Elem elem){return elem.get_genre() == genre;});
    movie_list.resize(std::distance(movie_list.begin(),it));

    return movie_list;
}

template <typename Elem>
std::vector<Elem> User<Elem>::get_watch_list() {
    return this->user_repo->get_repo();
}

template<typename Elem>
void User<Elem>::update_repo(Elem elem) {
    elem.set_likes(elem.get_likes()+1);
    this->repo.update(elem);
}

template<typename Elem>
std::string User<Elem>::return_File() {
    return this->user_repo->return_file();
}

template<typename Elem>
User<Elem>::~User() {
    delete this->user_repo;
}

#endif //A45_STEFAN_CODE_ENG1_USER_H
