#ifndef A45_STEFAN_CODE_ENG1_MOVIE_H
#define A45_STEFAN_CODE_ENG1_MOVIE_H

#include "iostream"
#include "string"

class Movie {

private:
    std::string title;
    std::string genre;
    int year;
    int likes;
    std::string trailer;

public:
    Movie();

    Movie(const std::string& title,const std::string& genre,int year,int likes,const std::string& trailer);

    void set_title(const std::string& title);

    void set_genre(const std::string& genre);

    void set_year(int year);

    void set_likes(int likes);

    void set_trailer(const std::string& trailer);

    std::string get_title() const {return this->title;};

    std::string get_genre() const {return this->genre;};

    int get_year() const {return this->year;};

    int get_likes() const {return  this->likes;};

    std::string get_trailer() const {return this->trailer;};

    std::string toString(){
        return this->title + " | " + this->genre + " | " + std::to_string(this->year) + " | " + std::to_string(this->likes) + " | " +
                this->trailer;
    }

    friend std::istream& operator>>( std::istream& input, Movie &M) {
        input >> std::ws;
        std::getline(input,M.title);
        input >> M.genre >> M.year >> M.likes >> M.trailer;
        return input;
    }

    friend std::ostream& operator<<( std::ostream& output, const Movie& M ){
        output << M.get_title() << " | " << M.get_genre() << " | " << M.get_year() << " | " << M.get_likes() <<" | " << M.get_trailer() <<" | \n";
        return output;
    }

};


#endif //A45_STEFAN_CODE_ENG1_MOVIE_H
