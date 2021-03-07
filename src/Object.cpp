#include "Object.hpp"

void Object::Draw(unsigned int x, unsigned int y) const {
  /// TODO
}
void Object::Draw(std::pair<unsigned int, unsigned int> p) const {
  Draw(p.first, p.second);
}
Object::Object(Graphics::Image *img): img_(img) {
}
