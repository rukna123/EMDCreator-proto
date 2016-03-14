#ifndef WINAMPSDIALOG_H
#define WINAMPSDIALOG_H

#include <QDialog>

namespace Ui {
class winampsdialog;
}

class winampsdialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit winampsdialog(QWidget *parent = 0);
    ~winampsdialog();
    
private:
    Ui::winampsdialog *ui;
};

#endif // WINAMPSDIALOG_H
