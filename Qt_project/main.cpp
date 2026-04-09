#include <QApplication>

#include "StartApp.h"

typedef Movie Elem;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    // add your file path with the repo movie file
    std::string path = "";
    FileRepo<Elem> repo{path};
    StartApp app = StartApp{repo,path};
    app.show();
    return QApplication::exec();
}