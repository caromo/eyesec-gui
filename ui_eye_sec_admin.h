/********************************************************************************
** Form generated from reading UI file 'eye_sec_admin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EYE_SEC_ADMIN_H
#define UI_EYE_SEC_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_eye_sec_admin
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *eye_sec_admin)
    {
        if (eye_sec_admin->objectName().isEmpty())
            eye_sec_admin->setObjectName(QStringLiteral("eye_sec_admin"));
        eye_sec_admin->resize(640, 480);
        centralwidget = new QWidget(eye_sec_admin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(60, 120, 113, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 30, 201, 21));
        eye_sec_admin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(eye_sec_admin);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 21));
        eye_sec_admin->setMenuBar(menubar);
        statusbar = new QStatusBar(eye_sec_admin);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        eye_sec_admin->setStatusBar(statusbar);

        retranslateUi(eye_sec_admin);

        QMetaObject::connectSlotsByName(eye_sec_admin);
    } // setupUi

    void retranslateUi(QMainWindow *eye_sec_admin)
    {
        eye_sec_admin->setWindowTitle(QApplication::translate("eye_sec_admin", "MainWindow", 0));
        label->setText(QApplication::translate("eye_sec_admin", "Eye Security - Admin Access", 0));
    } // retranslateUi

};

namespace Ui {
    class eye_sec_admin: public Ui_eye_sec_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EYE_SEC_ADMIN_H
