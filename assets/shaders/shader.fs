#version 330 core

out vec4 FragColor;

void main() {
  if (gl_FragCoord.y > 300.0)
    FragColor = vec4(0.7f, 0.01f, 0.01f, 1.0f);
  else
    FragColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);

  FragColor.r = pow(FragColor.r, 0.45);
  FragColor.g = pow(FragColor.g, 0.45);
  FragColor.b = pow(FragColor.b, 0.45);
}
