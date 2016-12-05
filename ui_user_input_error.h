/********************************************************************************
** Form generated from reading UI file 'user_input_error.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_INPUT_ERROR_H
#define UI_USER_INPUT_ERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_user_input_error
{
public:

    void setupUi(QDialog *user_input_error)
    {
        if (user_input_error->objectName().isEmpty())
            user_input_error->setObjectName(QStringLiteral("user_input_error"));
        user_input_error->resize(320, 240);

        retranslateUi(user_input_error);

        QMetaObject::connectSlotsByName(user_input_error);
    } // setupUi

    void retranslateUi(QDialog *user_input_error)
    {
        user_input_error->setWindowTitle(QApplication::translate("user_input_error", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class user_input_error: public Ui_user_input_error {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_INPUT_ERROR_H
