#ifndef WINDOW3D_H
#define WINDOW3D_H
#include<qdebug.h>
#include<QOpenGLWidget>
#include<QOpenGLFunctions_4_3_Core>
#include"global.h"
#include"./effect_shader/ripple2dshader.h"
#include"./effect_shader/simpletest.h"
class Widget3D : public QOpenGLWidget{
    Q_OBJECT
    QOpenGLFunctions_4_3_Core* func;
public:
    Widget3D(){

    }
    void initializeGL()Q_DECL_OVERRIDE{
        func = new QOpenGLFunctions_4_3_Core();
        func->initializeOpenGLFunctions();
        connect(this, SIGNAL(frameSwapped()), this, SLOT(update()));
    }

    void paintGL()Q_DECL_OVERRIDE{
        func->glClearColor(0.3f, 0.6f, 0.9f, 0);
        func->glClear(GL_COLOR_BUFFER_BIT);
        Ripple2DShader::paint(func);
    }

    void resizeGL(int width, int height)Q_DECL_OVERRIDE{

    }

public slots:
    void update(){
        QOpenGLWidget::update();
    }

protected:
    void mousePressEvent(QMouseEvent* event)Q_DECL_OVERRIDE{
        for(auto listener : Global::mouseListeners){
            listener(MouseEvent(MouseEvent::PRESS, event->pos()));
        }
    }

    void mouseReleaseEvent(QMouseEvent* event)Q_DECL_OVERRIDE{
        for(auto listener : Global::mouseListeners){
            listener(MouseEvent(MouseEvent::RELEASE, event->pos()));
        }
    }
};

#endif // WINDOW3D_H
