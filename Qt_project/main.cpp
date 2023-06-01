#include <QApplication>

#include "StartApp.h"

typedef Movie Elem;


std::string find_path(){
    char buff[PATH_MAX];
    getcwd(buff, PATH_MAX );
    std::string current_working_dir(buff);
    auto pos = current_working_dir.find_last_of('\\');
    return current_working_dir.substr(0,pos);
}

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    FileRepo<Elem> repo{find_path() + "\\all_movies.txt"};
    StartApp app = StartApp{repo,find_path()};
    app.show();
    return QApplication::exec();
}