#ifndef A7_STEFAN_CODE_ENG1_CSVREPO_H
#define A7_STEFAN_CODE_ENG1_CSVREPO_H

#include "iostream"
#include "fstream"
#include "../UserRepo.h"

template <typename Elem>
class CSVRepo: public UserRepo<Elem>{
private:
    std::string file_name;
    void write_to_file();
public:
    explicit CSVRepo(const std::string& file_name);

    void add(Elem elem) override;

    void remove(std::string title, int year) override;

    void update(Elem elem) override;

    std::string return_file() override;
};

template<typename Elem>
CSVRepo<Elem>::CSVRepo(const std::string &file_name) {
    this->repo = std::vector<Elem>();
    this->file_name = file_name;
    write_to_file();
}

template<typename Elem>
void CSVRepo<Elem>::add(Elem elem) {
    UserRepo<Elem>::add(elem);
    write_to_file();
}

template<typename Elem>
void CSVRepo<Elem>::remove(std::string title, int year) {
    UserRepo<Elem>::remove(title, year);
    write_to_file();
}

template<typename Elem>
void CSVRepo<Elem>::update(Elem elem) {
    UserRepo<Elem>::update(elem);
    write_to_file();
}

template<typename Elem>
void CSVRepo<Elem>::write_to_file() {
    std::ofstream output(this->file_name);
    for (auto entity: this->repo) {
        output << entity.get_title() << "," << entity.get_genre() << "," << entity.get_year() << ","
               << entity.get_likes() << "," << entity.get_trailer() <<"\n";
    }
    output.close();
}

template<typename Elem>
std::string CSVRepo<Elem>::return_file() {
    return this->file_name;
}


#endif //A7_STEFAN_CODE_ENG1_CSVREPO_H
