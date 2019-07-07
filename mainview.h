#ifndef MAINVIEW_H
#define MAINVIEW_H
#include<qmainwindow.h>
#include<widget3d.h>
class MainView : public QMainWindow{
private:
    Widget3D* widget3d;
public:
    MainView(){
        widget3d = new Widget3D();
        this->setCentralWidget(widget3d);
    }
};

#endif // MAINVIEW_H
