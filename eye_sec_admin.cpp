#include "eye_sec_admin.h"
#include "ui_eye_sec_admin.h"

eye_sec_admin::eye_sec_admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eye_sec_admin)
{
    ui->setupUi(this);
}

eye_sec_admin::~eye_sec_admin()
{
    delete ui;
}

void unduplicate() {

}
