#pragma once

int min(int a, int b) {
  return (a < b) ? a : b;
}

int sign(double x) {
  if (x < 0) {
    return -1;
  } else if (x > 0) {
    return 1;
  } else {
    return 0;
  }
}