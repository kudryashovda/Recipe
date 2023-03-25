#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

constexpr int window_width = 800;
constexpr int window_height = 600;

Mat image(window_height, window_width, CV_8UC3, Scalar(0, 0, 0));

void drawPoint(int x, int y) {
  Point p{x, y};
  line(image, p, p, Scalar(255, 255, 0), 1, LINE_8);
}

void drawThickLineHelper(int x1, int y1, int x2, int y2, int th,
                         void (*drawPen)(int, int, int, int, int), int width,
                         int height) {
  const int deltaX = abs(x2 - x1);
  const int deltaY = abs(y2 - y1);
  const int signX = x1 < x2 ? 1 : -1;
  const int signY = y1 < y2 ? 1 : -1;
  int error = deltaX - deltaY;
  drawPen(x2, y2, th, width, height);
  while (x1 != x2 || y1 != y2) {
    drawPen(x1, y1, th, width, height);
    int error2 = error * 2;
    if (error2 > -deltaY) {
      error -= deltaY;
      x1 += signX;
    }
    if (error2 < deltaX) {
      error += deltaX;
      y1 += signY;
    }
  }
}

void drawHorPen(int x, int y, int th, int width, int heigth) {
  y = max(0, y);
  y = min(y, heigth);

  const int xstart = max(0, x - th / 2);
  const int xend = min(x + th / 2, width);

  for (int xi = xstart; xi <= xend; ++xi) {
    drawPoint(xi, y);
  }
}

void drawVertPen(int x, int y, int th, int width, int height) {
  x = max(0, x);
  x = min(x, width);

  const int ystart = max(0, y - th / 2);
  const int yend = min(y + th / 2, height);

  for (int yi = ystart; yi <= yend; ++yi) {
    drawPoint(x, yi);
  }
}

void drawThickLine(int x1, int y1, int x2, int y2, int th, int width,
                   int height) {
  const int deltaX = abs(x2 - x1);
  const int deltaY = abs(y2 - y1);

  if (deltaX > deltaY) {
    drawThickLineHelper(x1, y1, x2, y2, th, &drawVertPen, width, height);
  } else {
    drawThickLineHelper(x1, y1, x2, y2, th, &drawHorPen, width, height);
  }
}

int main() {

  drawThickLine(0, 0, 820, 610, 5, window_width, window_height);
  drawThickLine(100, 0, 820, 610, 10, window_width, window_height);
  drawThickLine(200, 0, 500, 400, 20, window_width, window_height);
  drawThickLine(300, 0, 300, 610, 20, window_width, window_height);
  drawThickLine(400, 0, 300, 610, 1, window_width, window_height);

  imshow("Output", image);
  waitKey(0);

  return 0;
}


/*
cmake_minimum_required(VERSION 3.0.0)
project(lineDraw VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} lineDraw.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} -lstdc++fs)
*/
