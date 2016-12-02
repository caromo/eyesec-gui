#include "eye_sec_user.h"
#include <QApplication>

std::vector<QString> initialize_namelist(std::vector<QString> list) {
    std::vector<QString> result;
    for (int i = 0; i < list.size(); i++) {
        result.push_back(list[i]);
    }
    return result;
}
void save_changes(std::vector<QString> list) {
    std::ofstream file_out;
    file_out.open("test.txt", std::ios::out);
    for (int i = 0; i < list.size(); i++) {
        file_out << "'" << list[i].toUtf8().constData() << "'" << std::endl;
    }
}

int main(int argc, char *argv[])
{
    std::string input;
    std::vector<QString> name_list;
    initialize_namelist(name_list);
    QApplication a(argc, argv);
    eye_sec_user w;
    w.show();

    return a.exec();
}
