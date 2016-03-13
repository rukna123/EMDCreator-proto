#include "seekview.h"
#include "ui_seekview.h"
#include <QBitmap>
SeekView::SeekView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SeekView)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    this->setAttribute(Qt::WA_TranslucentBackground ,true );
    #ifdef Q_OS_WIN32

    movie = new QMovie(":/images/loader.gif");

    ui->frameView->setMovie(movie);
    movie->start();
    #endif
}

SeekView::~SeekView()
{
    delete ui;
}
long int SeekView::getwindowID()
{
return (long int)ui->frameView->winId();
}
void SeekView::setPosition(QString p)
{
  ui->timedisp->setText(p);
}
