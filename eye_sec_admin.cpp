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

void load_eyelist() {
    std::string line;
    std::ifstream my_file;
    my_file.open("test.txt");
    while (std::getline(file_in, line)) {
    }
    my_file.close();

}

void unduplicate() {

}
