#include "winampsdialog.h"
#include "ui_winampsdialog.h"

winampsdialog::winampsdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::winampsdialog)
{
    ui->setupUi(this);
}

winampsdialog::~winampsdialog()
{
    delete ui;
}
