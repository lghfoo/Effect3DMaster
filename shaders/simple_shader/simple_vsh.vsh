﻿#version 430 core
layout(location = 0)in vec3 vPos;
layout(location = 1)in vec3 vCol;
out vec3 fCol;
void main(){
    gl_Position = vec4(vPos, 1.0);
    fCol = vCol;
}
