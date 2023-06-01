#ifndef A7_STEFAN_CODE_ENG1_HTMLREPO_H
#define A7_STEFAN_CODE_ENG1_HTMLREPO_H


#include "iostream"
#include "fstream"
#include "../UserRepo.h"

template <typename Elem>
class HTMLRepo: public UserRepo<Elem>{
private:
std::string file_name;
void write_to_file();
public:
    explicit HTMLRepo(const std::string& file_name);

    void add(Elem elem) override;

    void remove(std::string title, int year) override;

    void update(Elem elem) override;

    std::string return_file() override;
};

template<typename Elem>
HTMLRepo<Elem>::HTMLRepo(const std::string &file_name) {
    this->repo = std::vector<Elem>();
    this->file_name = file_name;
    write_to_file();
}

template<typename Elem>
void HTMLRepo<Elem>::add(Elem elem) {
    UserRepo<Elem>::add(elem);
    write_to_file();
}

template<typename Elem>
void HTMLRepo<Elem>::remove(std::string title, int year) {
    UserRepo<Elem>::remove(title, year);
    write_to_file();
}

template<typename Elem>
void HTMLRepo<Elem>::update(Elem elem) {
    UserRepo<Elem>::update(elem);
    write_to_file();
}

template<typename Elem>
void HTMLRepo<Elem>::write_to_file() {
    std::ofstream output(this->file_name);
    output << "<!DOCTYPE html>\n"
              "<html>\n"
              "<head>\n"
              "    <title>WatchList</title>\n"
              "</head>\n"
              "<body> <!-- write this exactly as it is here -->\n"
              "<table border=\"1\">"
              "<tr>\n"
              "        <td>Title</td>\n"
              "        <td>Genre</td>\n"
              "        <td>Year</td>\n"
              "        <td>Likes</td>\n"
              "        <td>Trailer</td>\n"
              "</tr>";
    for (auto entity: this->repo) {
        output << "<tr>\n"
                  "<td>" << entity.get_title() << "</td>\n"
                  "<td>" << entity.get_genre() << "</td>\n"
                  "<td>" << entity.get_year() << "</td>\n"
                  "<td>" << entity.get_likes() << "</td>\n"
                  "<td><a href=" << entity.get_trailer() << ">Link</a></td>\n"
                  "</tr>";

    }
    output << "</table>\n"
              "</body>\n"
              "</html>";
    output.close();
}


template<typename Elem>
std::string HTMLRepo<Elem>::return_file() {
    return this->file_name;
}

#endif //A7_STEFAN_CODE_ENG1_HTMLREPO_H
