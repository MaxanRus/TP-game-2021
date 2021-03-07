#version 330 core
layout (location = 0) in vec2 aPos;

out vec2 TexCoord;

uniform mat4 transform;

void main() {
  TexCoord = aPos;
  gl_Position = transform * vec4(aPos, 1.0, 1.0);
}
