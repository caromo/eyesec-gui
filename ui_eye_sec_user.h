/********************************************************************************
** Form generated from reading UI file 'eye_sec_user.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EYE_SEC_USER_H
#define UI_EYE_SEC_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_eye_sec_user
{
public:
    QWidget *centralWidget;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *file_submit_info;
    QHBoxLayout *filename_layout;
    QLabel *file_name;
    QTextEdit *filename_field;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *name_layout;
    QLabel *file_name_3;
    QTextEdit *name_field;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *submit;
    QPushButton *exit_button;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *eye_sec_user)
    {
        if (eye_sec_user->objectName().isEmpty())
            eye_sec_user->setObjectName(QStringLiteral("eye_sec_user"));
        eye_sec_user->resize(550, 240);
        eye_sec_user->setMinimumSize(QSize(550, 240));
        eye_sec_user->setMaximumSize(QSize(600, 240));
        centralWidget = new QWidget(eye_sec_user);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 30, 191, 21));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 60, 500, 106));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        file_submit_info = new QLabel(layoutWidget);
        file_submit_info->setObjectName(QStringLiteral("file_submit_info"));
        file_submit_info->setWordWrap(true);

        verticalLayout->addWidget(file_submit_info);

        filename_layout = new QHBoxLayout();
        filename_layout->setSpacing(6);
        filename_layout->setObjectName(QStringLiteral("filename_layout"));
        file_name = new QLabel(layoutWidget);
        file_name->setObjectName(QStringLiteral("file_name"));
        file_name->setMinimumSize(QSize(46, 28));
        file_name->setMaximumSize(QSize(46, 28));

        filename_layout->addWidget(file_name);

        filename_field = new QTextEdit(layoutWidget);
        filename_field->setObjectName(QStringLiteral("filename_field"));
        filename_field->setMinimumSize(QSize(350, 0));
        filename_field->setMaximumSize(QSize(350, 28));

        filename_layout->addWidget(filename_field);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        filename_layout->addItem(horizontalSpacer);


        verticalLayout->addLayout(filename_layout);

        name_layout = new QHBoxLayout();
        name_layout->setSpacing(6);
        name_layout->setObjectName(QStringLiteral("name_layout"));
        file_name_3 = new QLabel(layoutWidget);
        file_name_3->setObjectName(QStringLiteral("file_name_3"));
        file_name_3->setMinimumSize(QSize(46, 28));
        file_name_3->setMaximumSize(QSize(46, 28));

        name_layout->addWidget(file_name_3);

        name_field = new QTextEdit(layoutWidget);
        name_field->setObjectName(QStringLiteral("name_field"));
        name_field->setMinimumSize(QSize(350, 28));
        name_field->setMaximumSize(QSize(350, 28));

        name_layout->addWidget(name_field);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        name_layout->addItem(horizontalSpacer_2);

        submit = new QPushButton(layoutWidget);
        submit->setObjectName(QStringLiteral("submit"));
        submit->setMinimumSize(QSize(75, 23));
        submit->setMaximumSize(QSize(75, 23));

        name_layout->addWidget(submit);


        verticalLayout->addLayout(name_layout);

        exit_button = new QPushButton(centralWidget);
        exit_button->setObjectName(QStringLiteral("exit_button"));
        exit_button->setGeometry(QRect(460, 170, 75, 23));
        eye_sec_user->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(eye_sec_user);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        eye_sec_user->setStatusBar(statusBar);
        menuBar = new QMenuBar(eye_sec_user);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 550, 22));
        eye_sec_user->setMenuBar(menuBar);

        retranslateUi(eye_sec_user);

        QMetaObject::connectSlotsByName(eye_sec_user);
    } // setupUi

    void retranslateUi(QMainWindow *eye_sec_user)
    {
        eye_sec_user->setWindowTitle(QApplication::translate("eye_sec_user", "eye_sec_user", 0));
        label_2->setText(QApplication::translate("eye_sec_user", "Eye Security - User Access", 0));
        file_submit_info->setText(QApplication::translate("eye_sec_user", "Ensure that your eye file is located in the directory, type in the file index, your name, and hit Submit.", 0));
        file_name->setText(QApplication::translate("eye_sec_user", "Index", 0));
        file_name_3->setText(QApplication::translate("eye_sec_user", "Name", 0));
        submit->setText(QApplication::translate("eye_sec_user", "Submit", 0));
        exit_button->setText(QApplication::translate("eye_sec_user", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class eye_sec_user: public Ui_eye_sec_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EYE_SEC_USER_H
