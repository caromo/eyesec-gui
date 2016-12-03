#include "eye_sec_user.h"
#include "ui_eye_sec_user.h"


eye_sec_user::eye_sec_user(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eye_sec_user){
    ui->setupUi(this);

}

eye_sec_user::~eye_sec_user() {
    delete ui;
}


void eye_sec_user::on_submit_clicked() {
    QString filename = ui->filename_field->toPlainText();
    QString name = ui->name_field->toPlainText();
    save_changes(name, filename);
    //if statement for compare methods: if true, add item to eye library
}

void eye_sec_user::on_exit_button_clicked() {
    close();
}

void save_changes(QString name, QString filename) {
    bool hasname;
    std::ofstream file_out;
    file_out.open("test.txt", std::ios_base::app);
    if (name.isEmpty() || filename.isEmpty()) {
    } else {
        file_out << name.toUtf8().constData() << " - " << filename.toUtf8().constData() << std::endl;
        file_out.close();
    }
}
