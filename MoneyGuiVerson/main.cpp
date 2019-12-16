//Hamilton Nguyen 1000538439 

#include "money.h"
#include <iostream>
#include <gtkmm/application.h>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv);
  auto app1 = Gtk::Application::create(argc, argv);
  auto app2 = Gtk::Application::create(argc, argv);
  auto app3 = Gtk::Application::create(argc, argv);
  
  auto app4 = Gtk::Application::create(argc, argv);
  auto app5 = Gtk::Application::create(argc, argv);
  auto app6 = Gtk::Application::create(argc, argv);
  auto app7 = Gtk::Application::create(argc, argv);
  
  exchange_window_NE a;
  app->run(a);
  
  exchange_window_SW b;
  app1->run(b);
  
  ReadFileWindow test;
  app3->run(test);

	int verifyfile;
	std::string veri;  
	std::ifstream file;
	std::string line;
	file.open("verify.txt");
	
	if(getline(file,line))
	{
		std::stringstream linestream(line);
		getline(linestream, veri);
	}
	
	std::stringstream vs;
	vs << veri;
	vs>>verifyfile;
{
	
	if (verifyfile == 1)
	{
		converter_window_NE_file c;
		app4->run(c);
		
		converter_window_SW_file d;
		app5->run(d);
		
	}

	if (verifyfile == 2)
	{
		converter_window_NE_HARD e;
		
		app6->run(e);
		
		converter_window_SW_HARD f;
		app7->run(f);
	}		

}  

}