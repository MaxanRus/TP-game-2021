#include "engine/objects/ground/GroundEmpty.hpp"

void GroundEmpty::Tick() {}

GroundEmpty::GroundEmpty(const std::string_view& image_name) : Ground(image_name) {}
