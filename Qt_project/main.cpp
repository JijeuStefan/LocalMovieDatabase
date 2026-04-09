#include <QApplication>

#include "StartApp.h"

typedef Movie Elem;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    // add your movies repo file path
    std::string path = R"(C:\Users\Lenovo\Documents\GitHub\LocalMovieDatabase\Qt_project\all_movies.txt)";
    FileRepo<Elem> repo{path};
    StartApp app = StartApp{repo,path};
    app.show();
    return QApplication::exec();
}