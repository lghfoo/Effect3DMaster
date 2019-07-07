#ifndef GLOBAL_H
#define GLOBAL_H
#include <QMouseEvent>
#include<functional>
using std::function;
class MouseEvent{
private:
    int type;
    QPoint pos;
public:
    enum{PRESS, RELEASE, CLICK, MOVE};
    MouseEvent(int type, const QPoint& pos){
        this->type = type;
        this->pos = pos;
    }

    int getType() const{
        return type;
    }

    QPoint getPos() const{
        return pos;
    }
};

typedef function<void(const MouseEvent&)>MouseListener;
class Global
{
public:
    Global();
    static QList<MouseListener>mouseListeners;
    static void addMouseListener(const MouseListener& listener){
        mouseListeners.append(listener);
    }
    static int curTime;
};

#endif // GLOBAL_H
