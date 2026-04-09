#include "StartApp.h"


StartApp::StartApp(FileRepo<Elem>& repo,const std::string& path) :user(repo), admin(repo, user), gui(admin,user) {
    this->path = path;
    this->configure();
    this->signal_slot();
}

void StartApp::configure() {
    auto* main_layout = new QVBoxLayout{this};

    this->hlayout = new QHBoxLayout{};

    this->csv = new QPushButton{"CSV"};
    this->html = new QPushButton{"HTML"};

    this->csv->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->html->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->hlayout->addWidget(this->csv);
    this->hlayout->addWidget(this->html);

    main_layout->addLayout(this->hlayout);

    main_layout->setStretch(0, 1);
    this->hlayout->setStretch(0, 1);
    this->hlayout->setStretch(1, 1);
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


