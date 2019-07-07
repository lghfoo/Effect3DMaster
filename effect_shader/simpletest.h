#ifndef SIMPLETEST_H
#define SIMPLETEST_H

#include <qopenglfunctions_4_3_core.h>
#include"../util/rawdata.h"
#include"../common/shader.h"

class SimpleTest{
public:
    static void paint(QOpenGLFunctions_4_3_Core* func){
        static bool init = false;
        static GLuint objId, posBufId, colBufId, programId;
        if(!init){
            init = true;
            func->glGenVertexArrays(1, &objId);
            func->glBindVertexArray(objId);

            func->glGenBuffers(1, &posBufId);
            func->glBindBuffer(GL_ARRAY_BUFFER, posBufId);
            func->glBufferData(GL_ARRAY_BUFFER, sizeof(RawData::quadVerts), RawData::quadVerts, GL_STATIC_DRAW);
            func->glEnableVertexAttribArray(0);
            func->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(QVector3D), nullptr);

            func->glGenBuffers(1, &colBufId);
            func->glBindBuffer(GL_ARRAY_BUFFER, colBufId);
            func->glBufferData(GL_ARRAY_BUFFER, sizeof(RawData::quadColors), RawData::quadColors, GL_STATIC_DRAW);
            func->glEnableVertexAttribArray(1);
            func->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(QVector3D), nullptr);

            programId = Shader::LoadShaders(func, ":/shaders/simple_shader/simple_vsh.vsh", ":/shaders/simple_shader/simple_fsh.fsh");
        }

        func->glBindVertexArray(objId);
        func->glEnableVertexAttribArray(0);
        func->glEnableVertexAttribArray(1);
        func->glUseProgram(programId);
        func->glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        func->glUseProgram(GL_NONE);
        func->glDisableVertexAttribArray(0);
        func->glDisableVertexAttribArray(1);
        func->glBindVertexArray(GL_NONE);
    }

};

#endif // SIMPLETEST_H
