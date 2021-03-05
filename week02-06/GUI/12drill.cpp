#include "Simple_window.h"
#include "Graph.h"

int main()
try {
	Point tl {150,150};
	Simple_window win {tl,600,400,"Dia"};
	win.wait_for_button();

	Axis xa {Axis::x, Point{20,300}, 280, 10, "penz axis"};
	win.attach(xa);
	win.set_label("Dia #2");
	win.wait_for_button(); 

	Axis ya {Axis::y, Point{20,300}, 280, 10, "ido axis"};
	ya.set_color(Color::red);
	ya.label.set_color(Color::green);
	win.attach(ya);
	win.set_label("Dia #3");
	win.wait_for_button();

	Function sine {sin,0,100,Point{20,180},100,10,10};
	win.attach(sine);
	win.set_label("Dia #4");
	win.wait_for_button();

	sine.set_color(Color::yellow);
	Polygon poly;
	poly.add(Point{250,100});
	poly.add(Point{350,120});
	poly.add(Point{400,200});
	poly.set_color(Color::blue);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("Dia #5");
	win.wait_for_button();

	Rectangle r {Point{200,200}, 100, 50};
	win.attach(r);
	win.set_label("Dia #6");
	win.wait_for_button();

	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	win.attach(poly_rect);
	poly_rect.add(Point{50,75});

	r.set_fill_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dash,3));
	poly_rect.set_style(Line_style(Line_style::dash,3));
	poly_rect.set_fill_color(Color::blue);
	win.set_label("Dia #7");
	win.wait_for_button();	

	Text t {Point{150,150}, "Buenos dias!"};
	win.attach(t);
	win.set_label("Dia #8");
	win.wait_for_button();

	t.set_font(Font::times_bold);
	t.set_font_size(30);
	win.set_label("Dia #9");
	win.wait_for_button();

	Image ii {Point(100,50),"doggo2.jpg"}; // 400*212-pixel jpg
	win.attach(ii);
	win.set_label("Dia #10");
	win.wait_for_button();

	ii.move(100,200);
	win.set_label("Dia #11");
	win.wait_for_button();

	Circle c {Point{100,200},50};
	Ellipse e {Point{100,200}, 75,25};
	e.set_color(Color::blue);
	Mark m {Point(100,200),'x'};
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};
	Image cal {Point{225,225},"namcat.gif"};
	cal.set_mask(Point{40,40},200,150);
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.attach(cal);
	win.set_label("Dia #12");
	win.wait_for_button();


}
catch (exception& e) {
    return 1;
}
catch (...) {
    return 2;
}