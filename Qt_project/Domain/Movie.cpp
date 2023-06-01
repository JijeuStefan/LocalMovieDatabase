#include "Movie.h"

Movie::Movie(){
    this->title = "default";
    this->genre = "default";
    this->year = 0;
    this->likes = 0;
    this->trailer = "default";
}

Movie::Movie(const std::string& title,const std::string& genre,int year,int likes,const std::string& trailer) {
    this->title = title;
    this->genre = genre;
    this->year = year;
    this->likes = likes;
    this->trailer = trailer;
}

void Movie::set_title(const std::string &title) {
    this->title = title;
}

void Movie::set_genre(const std::string &genre) {
    this->genre = genre;
}

void Movie::set_year(int year) {
    this->year = year;
}

void Movie::set_likes(int likes) {
    this->likes = likes;
}

void Movie::set_trailer(const std::string &trailer) {
    this->trailer = trailer;
}


