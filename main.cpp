#include "eye_sec_user.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    std::string input;
    QApplication a(argc, argv);
    eye_sec_user w;
    w.show();

    return a.exec();
}
