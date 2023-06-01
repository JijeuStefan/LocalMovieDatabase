#include <iostream>
#include <fstream>
#include "../Repo.h"

#ifndef A7_STEFAN_CODE_ENG1_FILEREPO_H
#define A7_STEFAN_CODE_ENG1_FILEREPO_H

template <typename Elem>
class FileRepo: public Repo<Elem>{

private:
    std::string file_name;
    void read_from_file();
    void write_to_file();

public:
    explicit FileRepo(const std::string& file_name);

    void add(Elem elem) override;

    void remove(std::string title, int year) override;

    void update(Elem elem) override;

};

template<typename Elem>
FileRepo<Elem>::FileRepo(const std::string &file_name) {
    this->file_name = file_name;
    read_from_file();
}

template<typename Elem>
void FileRepo<Elem>::add(Elem elem) {
    Repo<Elem>::add(elem);
    this->write_to_file();
}

template<typename Elem>
void FileRepo<Elem>::remove(std::string title, int year) {
    Repo<Elem>::remove(title, year);
    this->write_to_file();
}

template<typename Elem>
void FileRepo<Elem>::update(Elem elem) {
    Repo<Elem>::update(elem);
    this->write_to_file();
}

template<typename Elem>
void FileRepo<Elem>::read_from_file() {
    std::ifstream input(this->file_name);
    std::string line;
    while (std::getline(input,line))
    {
        Elem elem;
        auto poz = line.find(" | ");
        elem.set_title(line.substr(0,poz));

        line = line.substr(poz+3,line.size() - poz-3);
        poz = line.find(" | ");
        elem.set_genre(line.substr(0,poz));

        line = line.substr(poz+3,line.size()-poz-3);
        poz = line.find(" | ");
        elem.set_year(stoi(line.substr(0,poz)));

        line = line.substr(poz+3,line.size()-poz-3);
        poz = line.find(" | ");
        elem.set_likes(stoi(line.substr(0,poz)));

        line = line.substr(poz+3,line.size()-poz-3);
        poz = line.find(" | ");
        elem.set_trailer(line.substr(0,poz));

        this->repo.push_back(elem);
    }

}

template<typename Elem>
void FileRepo<Elem>::write_to_file() {
    std::ofstream output(this->file_name);

    for (auto elem: this->repo)
        output << elem;

    output.close();
}


#endif //A7_STEFAN_CODE_ENG1_FILEREPO_H
