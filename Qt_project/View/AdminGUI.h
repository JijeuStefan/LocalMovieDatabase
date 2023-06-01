#ifndef QT_PROJECT_ADMINGUI_H
#define QT_PROJECT_ADMINGUI_H


#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include <QErrorMessage>
#include "../Service/Admin.h"

template <typename Elem>
class AdminGUI : public QWidget{
private:
    Admin<Elem>& admin;

private:
    QWidget* parent;
    QHBoxLayout* hlayout;
    QVBoxLayout* vlayout;
    QFormLayout* flayout;
    QListWidget* elems;
    QLineEdit   *title, *genre, *year, *likes, *trailer;
    QPushButton *add_btn, *remove_btn, *update_btn;
    QPushButton* exit;
    QErrorMessage* errorMessage;

    void configure();
    void signal_slot();
    void populate();
    int getSelectedIndex();

    void add_elem();

    void remove_elem();

    void update_elem();

    void exit_admin();

    void showEvent(QShowEvent *event) override;
public:
    explicit AdminGUI(Admin<Elem>& admin, QWidget* parent = nullptr);

    ~AdminGUI() = default;
};

template<typename Elem>
AdminGUI<Elem>::AdminGUI(Admin<Elem>& admin, QWidget *parent):admin{admin}, parent{parent} {
    this->configure();
    this->signal_slot();
}

template<typename Elem>
void AdminGUI<Elem>::configure() {
    this->hlayout = new QHBoxLayout{this};
    this->elems = new QListWidget{};
    hlayout->addWidget(elems);

    this->vlayout = new QVBoxLayout{};

    this->flayout = new QFormLayout{};

    this->title = new QLineEdit{};
    this->genre = new QLineEdit{};
    this->year = new QLineEdit{};
    this->likes = new QLineEdit{};
    this->trailer = new QLineEdit{};

    flayout->addRow("Title", this->title);
    flayout->addRow("Genre", this->genre);
    flayout->addRow("Year", this->year);
    flayout->addRow("Likes", this->likes);
    flayout->addRow("Trailer", this->trailer);

    vlayout->addLayout(flayout);

    this->add_btn = new QPushButton{"Add"};
    this->update_btn = new QPushButton{"Update"};
    this->remove_btn = new QPushButton{"Remove"};
    this->exit = new QPushButton{"Exit admin"};

    vlayout->addWidget(add_btn);
    vlayout->addWidget(update_btn);
    vlayout->addWidget(remove_btn);
    vlayout->addWidget(exit);

    this->hlayout->addLayout(vlayout);

    this->errorMessage = new QErrorMessage{};

}

template<typename Elem>
void AdminGUI<Elem>::signal_slot() {


    QObject::connect(this->elems, &QListWidget::itemSelectionChanged, [this]() {
        int selectedIndex = this->getSelectedIndex();
        if (selectedIndex < 0)
            return;
        Elem elem = this->admin.get_movies()[selectedIndex];
        this->title->setText(QString::fromStdString(elem.get_title()));
        this->genre->setText(QString::fromStdString(elem.get_genre()));
        this->year->setText(QString::fromStdString(std::to_string(elem.get_year())));
        this->likes->setText(QString::fromStdString(std::to_string(elem.get_likes())));
        this->trailer->setText(QString::fromStdString(elem.get_trailer()));
    });
    QObject::connect(this->add_btn, &QPushButton::clicked, this, &AdminGUI<Elem>::add_elem);
    QObject::connect(this->update_btn, &QPushButton::clicked, this, &AdminGUI<Elem>::update_elem);
    QObject::connect(this->remove_btn, &QPushButton::clicked, this, &AdminGUI<Elem>::remove_elem);
    QObject::connect(this->exit, &QPushButton::clicked, this, &AdminGUI<Elem>::exit_admin);

}

template<typename Elem>
void AdminGUI<Elem>::populate() {
    this->elems->clear();
    std::vector<Elem> allDogs = this->admin.get_movies();
    for (Elem& elem: allDogs)
        this->elems->addItem(QString::fromStdString(elem.toString()));

}

template<typename Elem>
int AdminGUI<Elem>::getSelectedIndex() {
    QModelIndexList selectedIndexes = this->elems->selectionModel()->selectedIndexes();
    if (selectedIndexes.empty()) {
        this->title->clear();
        this->genre->clear();
        this->year->clear();
        this->likes->clear();
        this->trailer->clear();
        return -1;
    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

template<typename Elem>
void AdminGUI<Elem>::add_elem() {
    try {
        Elem elem = Elem(this->title->text().toStdString(),
                         this->genre->text().toStdString(),
                         this->year->text().toInt(),
                         this->likes->text().toInt(),
                         this->trailer->text().toStdString());
        this->admin.add(elem);
    }catch (std::exception &e){
        this->errorMessage->showMessage(QString::fromStdString(e.what()));
    }
    this->populate();
}

template<typename Elem>
void AdminGUI<Elem>::remove_elem() {
    try{
        this->admin.remove(this->title->text().toStdString(), this->year->text().toInt());
        if (this->admin.watchlist_find_by_id(this->title->text().toStdString(),this->year->text().toInt()))
            this->admin.remove_from_watchlist(this->title->text().toStdString(),this->year->text().toInt());
    }catch (std::exception &e) {
        this->errorMessage->showMessage(QString::fromStdString(e.what()));
    }
    this->populate();
}

template<typename Elem>
void AdminGUI<Elem>::update_elem() {
    try {
        Elem elem = Elem(this->title->text().toStdString(),
                         this->genre->text().toStdString(),
                         this->year->text().toInt(),
                         this->likes->text().toInt(),
                         this->trailer->text().toStdString());
        this->admin.update(elem);
        if (this->admin.watchlist_find_by_id(this->title->text().toStdString(),this->year->text().toInt()))
            this->admin.update_watchlist(elem);
    }catch (std::exception &e) {
        this->errorMessage->showMessage(QString::fromStdString(e.what()));
    }
    this->populate();
}

template<typename Elem>
void AdminGUI<Elem>::exit_admin() {
    this->parent->show();
    this->close();
}

template<typename Elem>
void AdminGUI<Elem>::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    this->populate();
}


#endif //QT_PROJECT_ADMINGUI_H
