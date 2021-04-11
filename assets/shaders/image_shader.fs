#version 330 core

in vec2 TexCoord;
out vec4 FragColor;

uniform sampler2D our_texture;

void main() {
  FragColor = textureLod(our_texture, TexCoord, 1.0/32.0);
}
