#ifndef SEEKVIEW_H
#define SEEKVIEW_H

#include <QDialog>
#include <QMovie>
namespace Ui {
class SeekView;
}

class SeekView : public QDialog
{
    Q_OBJECT

public:
    explicit SeekView(QWidget *parent = 0);
    ~SeekView();
    long int getwindowID();
    void setPosition(QString p);

private:
    Ui::SeekView *ui;
    QMovie *movie;
};

#endif // SEEKVIEW_H
