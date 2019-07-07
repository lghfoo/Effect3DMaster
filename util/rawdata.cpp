#include "rawdata.h"

RawData::RawData()
{

}

QVector3D RawData::quadVerts[4] = {
    QVector3D(-1, -1, 0),
    QVector3D(1, -1, 0),
    QVector3D(1, 1, 0),
    QVector3D(-1, 1, 0)
};

QVector3D RawData::quadColors[4] = {
    QVector3D(1, 1, 1),
    QVector3D(0, 1, 1),
    QVector3D(1, 0, 1),
    QVector3D(1, 1, 0)
};
