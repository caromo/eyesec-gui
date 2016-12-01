#ifndef EYE_SEC_USER_H
#define EYE_SEC_USER_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <string>

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

    void on_submit_button_clicked();

private:
    Ui::eye_sec_user *ui;
};

#endif // EYE_SEC_USER_H
