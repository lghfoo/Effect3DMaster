#include<QApplication>
#include"mainview.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainView* view = new MainView();
    view->resize(800, 600);
    view->show();
    return a.exec();
}
