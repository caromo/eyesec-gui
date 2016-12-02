#ifndef EYE_SEC_ADMIN_H
#define EYE_SEC_ADMIN_H

#include <QMainWindow>

namespace Ui {
class eye_sec_admin;
}

class eye_sec_admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit eye_sec_admin(QWidget *parent = 0);
    ~eye_sec_admin();

private:
    Ui::eye_sec_admin *ui;
};

#endif // EYE_SEC_ADMIN_H
