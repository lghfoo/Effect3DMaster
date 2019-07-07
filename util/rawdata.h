#ifndef RAWDATA_H
#define RAWDATA_H

#include <QVector3D>

class RawData
{
public:
    RawData();
    //use tri_fan to draw
    static QVector3D quadVerts[4];
    static QVector3D quadColors[4];

};

#endif // RAWDATA_H
