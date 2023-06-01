#ifndef QT_PROJECT_STARTAPP_H
#define QT_PROJECT_STARTAPP_H

#include <iostream>
#include <string>
#include <filesystem>
#include <unistd.h>

#include "Repo/Repo.h"
#include "Repo/FileRepo/FileRepo.h"
#include "Repo/FileRepo/CSVRepo.h"
#include "Repo/FileRepo/HTMLRepo.h"
#include "Service/Admin.h"
#include "Service/User.h"
#include "View/GUI.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

typedef Movie Elem;

class StartApp: public QWidget{
private:
    FileRepo<Elem>& repo;
    UserRepo<Elem>* user_repo = nullptr;
    User<Elem> user = User<Elem>(repo,user_repo);
    Admin<Elem> admin = Admin<Elem>(repo,user);
    GUI<Elem> gui = GUI<Elem>(admin,user);

    std::string path;

private:
    QHBoxLayout* hlayout;
    QPushButton* csv;
    QPushButton* html;
    void configure();
    void signal_slot();

public:
    explicit StartApp(FileRepo<Elem>& repo,const std::string& path);

    void csv_file();

    void html_file();

    ~StartApp() = default;
};


#endif //QT_PROJECT_STARTAPP_H
