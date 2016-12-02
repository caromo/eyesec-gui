#ifndef EYE_SEC_USER_H
#define EYE_SEC_USER_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <string>
#include <vector>
#include <fstream>

namespace Ui {
class eye_sec_user;
}

class eye_sec_user : public QMainWindow
{
    Q_OBJECT

public:
    explicit eye_sec_user(QWidget *parent = 0);
    ~eye_sec_user();

private slots:

    void on_submit_clicked();

    void on_exit_button_clicked();


private:
    Ui::eye_sec_user *ui;
};

void check_valid(QString input);
std::vector<QString> initialize_namelist();
void set_username(std::vector<QString> namelist, QString name);
void import_picture();
void save_changes(QString name, QString filename);


#endif // EYE_SEC_USER_H
