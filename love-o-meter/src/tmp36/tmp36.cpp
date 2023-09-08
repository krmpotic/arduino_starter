#include "tmp36.h"

float tmp36Vol(int r) {
  return ((float)r/1024.0) * 5.0;
}

float tmp36Cel(int r) {
  float vol = tmp36Vol(r);
  return (vol - 0.5) * 100;
}
