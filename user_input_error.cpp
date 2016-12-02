#include "user_input_error.h"
#include "ui_user_input_error.h"

user_input_error::user_input_error(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_input_error)
{
    ui->setupUi(this);
}

user_input_error::~user_input_error()
{
    delete ui;
}
