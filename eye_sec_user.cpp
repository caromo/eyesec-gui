#include "eye_sec_user.h"
#include "ui_eye_sec_user.h"

//User client GUI for Eye Security - Carlo Romo

//User client is built with Qt 5.7 and Qt Creator.
//Users can attempt to add an eye to the library, but can be restricted by the
//compare functions.

eye_sec_user::eye_sec_user(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eye_sec_user){
    ui->setupUi(this);

}

eye_sec_user::~eye_sec_user() {
    delete ui;
}

//what happens when the submit button is clicked: searches people and eyelibrary for matching names
//and eye indices, outputs message if compare command is successful.
void eye_sec_user::on_submit_clicked(std::vector<Person> people, eyeLibrary lib) {
    QString filename = ui->filename_field->toPlainText();
    QString name = ui->name_field->toPlainText();
    int index = filename.toInt();
    Person to_add(name.toUtf8().constData());
    int indexOfPerson = getPerson(people, name.toUtf8().constData());
    Person to_compare = people[indexOfPerson];

    //first vector to compare
    vector<Pixel> iris1 = to_compare.getAverage(0);
    vector<vector<Pixel> > pic = lib.getPicture(index);

    Parser parse(pic);

    //second vector to compare
    vector<Pixel> iris2 = parse.getIrisArray();

    Compare compa(iris1, iris2);

    //comparison function
    if (compa.is_same_person()) {
        people.push_back(to_add);
        std::vector <std::vector <Pixel> > a = lib.getPicture(0);
        Parser pa(a);
        std::vector<Pixel> irisArray = pa.getIrisArray();
        people[0].addIrisInstance(irisArray);
        save_changes(name, filename);
    } else {

    }


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
        int index = filename.toInt();
        file_out << name.toUtf8().constData() << " - Index " << index << std::endl;
        file_out.close();
    }
}
