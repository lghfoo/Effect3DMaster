#ifndef RIPPLE2DSHADER_H
#define RIPPLE2DSHADER_H

#include <qopenglfunctions_4_3_core.h>
#include"../global.h"
struct Ripple2D{
    QPoint origin;
    int beginTime;
    int curTime;
    Ripple2D(const QPoint& origin, int beginTime, int curTime){
        this->origin = origin;
        this->beginTime = beginTime;
        this->curTime = curTime;
    }
};

class Ripple2DShader{
private:
public:
    static void paint(QOpenGLFunctions_4_3_Core* func){
        static bool init = false;
        static QList<Ripple2D>ripples;
        if(!init){
            init = true;
            Global::addMouseListener([&](const MouseEvent& event){
                if(event.getType() == MouseEvent::PRESS){
                    ripples.append(Ripple2D(event.getPos(), Global::curTime, Global::curTime));
                }
            });

        }
    }
};

#endif // RIPPLESHADER_H
