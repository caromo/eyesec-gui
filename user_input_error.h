#ifndef USER_INPUT_ERROR_H
#define USER_INPUT_ERROR_H

#include <QDialog>

namespace Ui {
class user_input_error;
}

class user_input_error : public QDialog
{
    Q_OBJECT

public:
    explicit user_input_error(QWidget *parent = 0);
    ~user_input_error();

private:
    Ui::user_input_error *ui;
};

#endif // USER_INPUT_ERROR_H
