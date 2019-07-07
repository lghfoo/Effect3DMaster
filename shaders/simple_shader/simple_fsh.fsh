#version 430 core
in vec3 fCol;
void main(){
    gl_FragColor = vec4(fCol, 1.0);
}
