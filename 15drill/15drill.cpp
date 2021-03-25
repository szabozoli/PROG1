/*
    g++ 15drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double x) {return 1;};
double slope(double x) {return x/2;};
double square(double x) {return x*x;};
double sloping_cos(double x) {return cos(x)+slope(x);};

int main()
{
    using namespace Graph_lib;

    constexpr int xmax = 600;
    constexpr int ymax = 600;
    constexpr int x_orig = xmax/2;
    constexpr int y_orig = ymax/2;
    constexpr int scale = 20;
    constexpr int x_length = 400;
    constexpr int y_length = 400;

    Simple_window win {Point{100,100}, xmax, ymax, "Function graphs"};

    Axis x {Axis::x, Point{100, y_orig}, x_length, x_length/scale, "1 = = 20 pixels"};
    Axis y {Axis::y, Point{x_orig,y_length+100}, y_length, y_length/scale, "1 = = 20 pixels"};
    x.set_color(Color::red);
    y.set_color(Color::red);

    constexpr int min = -10;
    constexpr int max = 11;
    constexpr int points = 400;

    Function f1 {one, min, max, Point{x_orig,y_orig}, points, scale, scale};

    Function f2 {slope, min, max, Point{x_orig, y_orig}, points, scale, scale};

    Text x2 {Point{100, ymax-185}, "x/2"};

    Function f3 {square, min, max, Point{x_orig, y_orig}, points, scale, scale};

    Function f4 {[] (double x) {return cos(x); }, min, max, Point{x_orig, y_orig}, points, scale, scale};
    f4.set_color(Color::blue);

    Function f5 {sloping_cos, min, max, Point{x_orig, y_orig}, points, scale, scale};

    win.attach(f1);
    win.attach(f2);
    win.attach(x2);
    win.attach(f3);
    win.attach(f4);
    win.attach(f5);
    win.attach(x);
    win.attach(y);
    win.wait_for_button();
}