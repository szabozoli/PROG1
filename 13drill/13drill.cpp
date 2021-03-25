 //g++ 13drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images` 

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

constexpr int xmax= 1000;
constexpr int ymax= 800;

Simple_window win {Point {100,100}, xmax, ymax, "13. Drill"};

constexpr int grid_size = 100;
constexpr int grid_max= 800;

Lines grid;
for (int x = grid_size;x<= grid_max; x+= grid_size)
{
	grid.add(point{x,0}, point{x,grid_max});
	grid.add(point{0,x}, point{grid_max,x});
}

win.attach(grid);

vector_ref<rectangles> vr;

for(in i=0;i<8; ++i)
{
	vr.push_back(new rectangle(point{i*grid_size,i*grid_size,grid_size}));
	vr[vr.size()-1].set_fill_color(color::red);
	win.attach(vr[vr.size()-1]);
}

vector_ref<image> vi;

vi.push_back(new image(point{0,200}, "dog.jpg"));
vi.push_back(new image(point{0,400}, "dog.jpg"));
vi.push_back(new image(point{0,600}, "dog.jpg"));

constexpr int image_size=200;

for(int i=0;i<vi.size();++i)
{
	vi[i].set_mask(point{100,100}, image_size, image_size);
	win.attach(vi[i]);
}

Image logo(point{0,0}, "car.jpg");
win.attach(logo);

for(int i=0; i<8; ++i)
{
	for( int j=0;j<8;++j)
	{
		win.wait_for_button();
		if(j<7)
		{
			logo.move(100,0);
		}
		else
		{
			logo.move(-700,100);
		}
	}

}
