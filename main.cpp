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
bool is_equal(std::string s1, std::string s2) {
    if (0 == std::strcmp(s1.c_str(),s2.c_str())) {
        return true;
    } else return false;
}

int main(int argc, char *argv[]) {
    std::string input;
    std::cout << "Please specify which client to run: 'admin' or 'user'.\n Entry: ";
    std::cin >> input;
    if (is_equal(input, "admin")) {

    } else if (is_equal(input, "user")) {
        QApplication a(argc, argv);
        eye_sec_user w;
        w.show();

        return a.exec();
    } else {
        std::cout << "Invalid entry. Ending program.";
        return 0;
    }
    std::vector<QString> initial_name_list;
    initial_name_list = initialize_namelist();
}
