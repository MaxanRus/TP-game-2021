#version 330 core

in vec2 TexCoord;
out vec4 FragColor;

uniform sampler2D texture;

void main() {
  FragColor = textureLod(texture, TexCoord.xy, 1.0/32.0);
}
