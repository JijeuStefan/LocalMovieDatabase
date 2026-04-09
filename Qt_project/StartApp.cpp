#include "StartApp.h"


StartApp::StartApp(FileRepo<Elem>& repo,const std::string& path) :user(repo), admin(repo, user), gui(admin,user) {
    this->path = path;
    this->configure();
    this->signal_slot();

    this->resize(200, 200);

    QScreen* screen = QGuiApplication::primaryScreen();
    if (screen) {
        QRect screenGeometry = screen->geometry();
        int x = (screenGeometry.width() - width()) / 2;
        int y = (screenGeometry.height() - height()) / 2;
        this->move(x, y);
    }
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
    this->user.add_user_repo(new CSVRepo<Elem>(R"(C:\Users\Lenovo\Documents\GitHub\LocalMovieDatabase\Qt_project\watch_list.csv)"));//add your watch list csv file path
    this->gui.show();
    this->close();
}

void StartApp::html_file() {
    this->user.add_user_repo(new HTMLRepo<Elem>(R"(C:\Users\Lenovo\Documents\GitHub\LocalMovieDatabase\Qt_project\watch_list.html)"));//add your watch list html file path
    this->gui.show();
    this->close();
}


