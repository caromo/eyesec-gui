#include "eye_sec_user.h"
#include "ui_eye_sec_user.h"

eye_sec_user::eye_sec_user(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eye_sec_user){
    ui->setupUi(this);
}

eye_sec_user::~eye_sec_user()
{
    delete ui;
}

void eye_sec_user::on_submit_clicked()
{
    QString filename = ui->filename_field->toPlainText();
    QString name = ui->name_field->toPlainText();


}
