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
#include <QScreen>
#include <QGuiApplication>

typedef Movie Elem;

class StartApp: public QWidget{
private:
    User<Elem> user;
    Admin<Elem> admin;
    GUI<Elem> gui;

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
