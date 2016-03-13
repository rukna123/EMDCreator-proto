#include "mainwindow.h"
#include "ui_mainwindow.h"

QDesktopWidget *desktop;
QDesktopServices *mycomputer;

//Setup Mainwindow
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    mpseekView = new SeekView(this);

    QObject::connect(ui->sliderSeek,SIGNAL(hoverValue(QString,QPoint*)),this,SLOT(showSeekpos(QString,QPoint*)));
    QObject::connect(ui->sliderSeek, SIGNAL(sliderPressed(QString,QPoint*)), this, SLOT(onSliderClick(QString, QPoint*)));


    connect(ui->sliderSeek,SIGNAL(hidetooltip()),this,SLOT(hideframe()));

}

void MainWindow::pauseSeekView()
{
    if (fr)
    {
        fr->pause();
    }
}
//Enqueue the time in time_queue on click on slider
void MainWindow::onSliderClick(QString pos, QPoint *pt){
    float p=(pos.toInt()/100.0)*fr->duration();
    QTime time(0,0,0,0);
    time = time.addSecs(p);
    int seconds = QTime(0, 0, 0).secsTo(time);
    time_queue.enqueue(seconds);

}
//delete fr and make it null
void MainWindow::restartSeekView(int ec,bool stop)
{
    if (fr)
    {
        qDebug()<<"Handle !!!!";
        fr->stop();
        fr=NULL;
    }
}

void MainWindow::startingPlaybackframe()
{ if (fr)
    {
        fr->pause();
    }
}
//Hidning thumbnail View
void MainWindow::hideframe()
{
    if (lab)
    {  lab->resize(1,1);
        lab->hide();

        mpseekView->resize(1,1);
        mpseekView->hide();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
//show the thumbnail view
void MainWindow::showSeekpos(QString pos, QPoint *pt)
{
    if(currentFile != ""){
        float p=(pos.toInt()/100.0)*fr->duration();
        QTime _duration(0,0,0,0);
        _duration=_duration.addSecs(p);

        mpseekView->resize(128,105);
        mpseekView->move(pt->x()-64+ui->sliderSeek->x(),ui->sliderSeek->y()-105);
        mpseekView->show();


            if(pos.toInt()<100)
                {
                    fr->pause();
                    fr->seek(pos.toInt());
                }
        mpseekView->setPosition(_duration.toString());
    }


}

//Load the file and initialize fr
void MainWindow::on_pushButton_2_clicked()
{

    QString file = QFileDialog::getOpenFileName(this,
                                             tr("Open media file(s)"),
                                             mycomputer->storageLocation( mycomputer->MoviesLocation),
                                             tr("Any File (*.*)")
                                                );
    if(fr != NULL)
        delete fr;
    fr=new mplayerfe(this,this);

    QObject::connect(fr,SIGNAL(startingplayback()),this,SLOT(startingPlaybackframe()));
    QObject::connect(fr,SIGNAL(processFinished(int,bool)),this,SLOT(restartSeekView(int,bool)));
    QObject::connect(fr,SIGNAL(starting()),this,SLOT(pauseSeekView()));

    fr->setVideoWinid(mpseekView->getwindowID());
    //fr->setColorkey(5);
    fr->setaspect(false);

    time_queue.clear();
    currentFile = file;
    if(currentFile != ""){
        fr->play(this->currentFile,0);
        fr->pause();
        fr->setOSDlevel(0);
    }

}
//Store the cuts in a file
void MainWindow::on_pushButton_3_clicked()
{
    QString createdFile = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "untitled",
                               tr("text files (*.txt)"));
    if(createdFile != ""){
    QFile file(createdFile);
       if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
           return;

       QTextStream out(&file);
       while(!time_queue.empty()){
           if(time_queue.size() >= 2){
               out<<time_queue.head()<<" ";
               time_queue.dequeue();
               out<<time_queue.head()<<" "<<"\n";
               time_queue.dequeue();
           }else{
               break;
           }
       }

       }
}
//remove last cut from the queue
void MainWindow::on_pushButton_clicked()
{
    time_queue.pop_back();
}
