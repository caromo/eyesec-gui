#include "eye_sec_user.h"
#include "user_input_error.h"
#include <QApplication>

std::vector<QString> initialize_namelist() {
    std::vector<QString> result;
    std::string line;
    std::ifstream file_in;
    file_in.open("test.txt", std::ios::in);
    while (std::getline(file_in, line)) {
        result.push_back(QString::fromStdString(line));
    }
    file_in.close();
    return result;
}

int main(int argc, char *argv[])
{
    std::string input;
    std::vector<QString> initial_name_list;
    initial_name_list = initialize_namelist();

    QApplication a(argc, argv);
    eye_sec_user w;
    w.show();

    return a.exec();
}
