#ifndef QT_PROJECT_GUI_H
#define QT_PROJECT_GUI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "../Service/User.h"
#include "../Service/Admin.h"
#include "AdminGUI.h"
#include "UserGUI.h"

template <typename Elem>
class GUI: public QWidget{
private:
    AdminGUI<Elem>* admin_widget;
    UserGUI<Elem>* user_widget;

private:
    QHBoxLayout* hlayout;
    QPushButton* admin_btn;
    QPushButton* user_btn;
    void configure();
    void signal_slot();

public:
    explicit GUI(Admin<Elem>& admin, User<Elem>& user);

    void show_Admin();

    void show_User();

    ~GUI() = default;
};


template<typename Elem>
GUI<Elem>::GUI(Admin<Elem> &admin, User<Elem> &user) {
    this->admin_widget = new AdminGUI<Elem>{admin, this};
    this->user_widget = new UserGUI<Elem>{user, this};
    this->configure();
    this->signal_slot();
}


template<typename Elem>
void GUI<Elem>::configure() {
    auto* main_layout = new QVBoxLayout{this};


    this->hlayout = new QHBoxLayout{};

    this->admin_btn = new QPushButton{"Admin"};
    this->user_btn = new QPushButton{"User"};


    this->admin_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->user_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    this->hlayout->addWidget(this->admin_btn);
    this->hlayout->addWidget(this->user_btn);

    main_layout->addLayout(this->hlayout);

    main_layout->setStretch(0, 1);
    this->hlayout->setStretch(0, 1);
    this->hlayout->setStretch(1, 1);
}

template<typename Elem>
void GUI<Elem>::signal_slot() {
    QObject::connect(this->admin_btn,&QPushButton::clicked, this, &GUI<Elem>::show_Admin);
    QObject::connect(this->user_btn,&QPushButton::clicked, this, &GUI<Elem>::show_User);
}

template<typename Elem>
void GUI<Elem>::show_Admin() {
    this->admin_widget->show();
    this->close();
}

template<typename Elem>
void GUI<Elem>::show_User() {
    this->user_widget->show();
    this->close();
}

#endif //QT_PROJECT_GUI_H
