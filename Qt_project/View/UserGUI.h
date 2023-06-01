#ifndef QT_PROJECT_USERGUI_H
#define QT_PROJECT_USERGUI_H

#include <QWidget>
#include "../Service/User.h"
#include <windows.h>

template <typename Elem>
class UserGUI: public QWidget{
private:
    User<Elem>& user;

private:
    QListWidget* movies;
    QListWidget* watch_list;

    QWidget* parent;
    QHBoxLayout* hlayout;
    QVBoxLayout* vlayout_movies;
    QHBoxLayout* hlayout_search;
    QHBoxLayout* hlayout_scroll;
    QVBoxLayout* vlayout_watchlist;
    QPushButton* search_btn;
    QLineEdit* genre;
    QPushButton* add_btn;
    QPushButton* open_trailer_btn;

    QPushButton* open_btn;
    QPushButton* remove_btn;
    QPushButton* exit_btn;

    QWidget* popup;
    QGridLayout* glayout_popup;
    QLabel* text;
    QPushButton* yes_btn;
    QPushButton* no_btn;

    QErrorMessage* errorMessage;

    std::vector<Elem> movies_genre;

    void configure();

    void signal_slot();

    void populate_movie_list();

    int getSelectedIndex_movie_list();

    void populate_watch_list();

    int getSelectedIndex_watch_list();

    void add_movie();

    void remove_movie();

    void update_movie();

    void open_URL(const char* linkChar);

    void exit_user();

    void showEvent(QShowEvent *event) override;
public:
    explicit UserGUI(User<Elem>& user, QWidget* parent = nullptr);

    ~UserGUI() = default;

};

template<typename Elem>
UserGUI<Elem>::UserGUI(User<Elem> &user, QWidget *parent):user{user}, parent{parent} {
    this->configure();
    this->signal_slot();
}

template<typename Elem>
void UserGUI<Elem>::configure() {
    this->hlayout = new QHBoxLayout{this};

    this->search_btn = new QPushButton{"Search"};
    this->genre = new QLineEdit{};

    this->movies = new QListWidget{};;

    this->add_btn = new QPushButton{"Add movie"};
    this->open_trailer_btn = new QPushButton{"Open trailer"};

    this->vlayout_movies = new QVBoxLayout{};

    this->hlayout_search = new QHBoxLayout{};
    this->hlayout_search->addWidget(this->search_btn);
    this->hlayout_search->addWidget(this->genre);
    this->vlayout_movies->addLayout(this->hlayout_search);

    this->vlayout_movies->addWidget(this->movies);

    this->hlayout_scroll = new QHBoxLayout{};
    this->hlayout_scroll->addWidget(this->add_btn);
    this->hlayout_scroll->addWidget(this->open_trailer_btn);
    this->vlayout_movies->addLayout(this->hlayout_scroll);

    this->hlayout->addLayout(this->vlayout_movies);

    this->vlayout_watchlist = new QVBoxLayout{};

    this->watch_list = new QListWidget{};
    this->open_btn = new QPushButton{"Open watch list"};
    this->remove_btn = new QPushButton{"Remove movie"};
    this->exit_btn = new QPushButton{"Exit user"};

    this->vlayout_watchlist->addWidget(this->watch_list);
    this->vlayout_watchlist->addWidget(this->remove_btn);
    this->vlayout_watchlist->addWidget(this->open_btn);
    this->vlayout_watchlist->addWidget(this->exit_btn);

    this->hlayout->addLayout(this->vlayout_watchlist);

    this->popup = new QWidget{};
    this->glayout_popup = new QGridLayout{this->popup};
    this->text = new QLabel{"Did you like the movie?"};
    this->yes_btn = new QPushButton{"Yes"};
    this->no_btn = new QPushButton{"No"};
    this->glayout_popup->addWidget(this->text,0,1,1,2,Qt::AlignHCenter);
    this->glayout_popup->addWidget(this->yes_btn,1,0,1,2,Qt::AlignCenter);
    this->glayout_popup->addWidget(this->no_btn,1,2,1,2,Qt::AlignCenter);
}

template<typename Elem>
void UserGUI<Elem>::signal_slot() {
    QObject::connect(this->search_btn,&QPushButton::clicked, this, &UserGUI<Elem>::populate_movie_list);
    QObject::connect(this->add_btn,&QPushButton::clicked, this, &UserGUI<Elem>::add_movie);
    QObject::connect(this->open_trailer_btn,&QPushButton::clicked, [this](){
        int poz = this->getSelectedIndex_movie_list();
        if (poz < 0)
            return;
        Elem elem = this->movies_genre[poz];
        open_URL(elem.get_trailer().c_str());
    });
    QObject::connect(this->remove_btn,&QPushButton::clicked, this->popup, &QWidget::show);
    QObject::connect(this->yes_btn,&QPushButton::clicked, [this](){
        int poz = this->getSelectedIndex_watch_list();
        if (poz < 0)
            return;
        Elem elem = this->user.get_watch_list()[poz];
        this->update_movie();
        this->remove_movie();
        this->popup->close();
    });
    QObject::connect(this->no_btn,&QPushButton::clicked, [this](){
        this->remove_movie();
        this->popup->close();
    });
    QObject::connect(this->open_btn,&QPushButton::clicked, [this](){open_URL(this->user.return_File().c_str());});
    QObject::connect(this->exit_btn,&QPushButton::clicked, this, &UserGUI<Elem>::exit_user);
}


template<typename Elem>
void UserGUI<Elem>::populate_movie_list() {
    std::string selected_genre = this->genre->text().toStdString();

    this->movies->clear();
    this->movies_genre = this->user.get_movies_genre(selected_genre);
    for (Elem& elem: this->movies_genre)
        this->movies->addItem(QString::fromStdString(elem.toString()));

}

template<typename Elem>
int UserGUI<Elem>::getSelectedIndex_movie_list() {
    QModelIndexList selectedIndexes = this->movies->selectionModel()->selectedIndexes();
    if (selectedIndexes.empty())
        return -1;
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

template<typename Elem>
void UserGUI<Elem>::populate_watch_list() {
    this->watch_list->clear();
    for (Elem& elem: this->user.get_watch_list())
        this->watch_list->addItem(QString::fromStdString(elem.toString()));
}

template<typename Elem>
int UserGUI<Elem>::getSelectedIndex_watch_list() {
    QModelIndexList selectedIndexes = this->watch_list->selectionModel()->selectedIndexes();
    if (selectedIndexes.empty())
        return -1;
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}


template<typename Elem>
void UserGUI<Elem>::add_movie() {
    try {
        int poz = this->getSelectedIndex_movie_list();
        if (poz < 0)
            return;
        Elem elem = this->movies_genre[poz];
        this->user.add(elem);
    } catch (std::exception &e) {
        this->errorMessage->showMessage(QString::fromStdString(e.what()));
    }
    this->populate_watch_list();
}

template<typename Elem>
void UserGUI<Elem>::remove_movie() {
    try {
        int poz = this->getSelectedIndex_watch_list();
        if (poz < 0)
            return;
        Elem elem = this->user.get_watch_list()[poz];
        this->user.remove(elem.get_title(),elem.get_year());
    } catch (std::exception &e) {
        this->errorMessage->showMessage(e.what());
    }
    this->populate_watch_list();
}

template<typename Elem>
void UserGUI<Elem>::update_movie() {
    try {
        int poz = this->getSelectedIndex_watch_list();
        if (poz < 0)
            return;
        Elem elem = this->user.get_watch_list()[poz];
        this->user.update_repo(elem);
    } catch (std::exception &e) {
        this->errorMessage->showMessage(e.what());
    }
    this->populate_movie_list();
}


template<typename Elem>
void UserGUI<Elem>::open_URL(const char* linkChar) {
    ShellExecute(nullptr, nullptr,linkChar , nullptr, nullptr, SW_SHOWNORMAL);
}

template<typename Elem>
void UserGUI<Elem>::exit_user() {
    this->parent->show();
    this->close();
}

template<typename Elem>
void UserGUI<Elem>::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    this->populate_movie_list();
    this->populate_watch_list();
}

#endif //QT_PROJECT_USERGUI_H
