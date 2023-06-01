#include "StartApp.h"


StartApp::StartApp(FileRepo<Elem>& repo,const std::string& path) : repo{repo} {
    this->path = path;
    this->configure();
    this->signal_slot();
}

void StartApp::configure() {
    this->hlayout = new QHBoxLayout{this};
    this->csv = new QPushButton{"CSV"};
    this->html = new QPushButton{"HTML"};

    this->hlayout->addWidget(this->csv);
    this->hlayout->addWidget(this->html);
}

void StartApp::signal_slot() {
    QObject::connect(this->csv,&QPushButton::clicked, this, &StartApp::csv_file);
    QObject::connect(this->html,&QPushButton::clicked, this, &StartApp::html_file);
}

void StartApp::csv_file() {
    this->user.add_user_repo(new CSVRepo<Elem>(path + "\\watch_list.csv"));
    this->gui.show();
    this->close();
}

void StartApp::html_file() {
    this->user.add_user_repo(new HTMLRepo<Elem>(path + "\\watch_list.html"));;
    this->gui.show();
    this->close();
}


