#ifndef GTKMM_MONEY_H
#define GTKMM_MONEY_H

//Hamilton Nguyen 1000538439 

#include <gtkmm.h>
#include <iostream>
#include <sstream>
#include <fstream>

class airport
{
	protected:
	std::string office_NE;
	std::string manager_NE;
	std::string office_SW;
	std::string manager_SW;
	int verifyfile;
	std::string raw[256];
	int i;
	
	public:
};

class ReadFileWindow : public Gtk::Window, airport
{
public:
	ReadFileWindow();
	virtual ~ReadFileWindow();

protected:

	void send_value();
	void on_button_clicked_Yes();
	void on_button_clicked_No();


	//Child widgets:
	Gtk::Box m_HBox;
	Gtk::Box m_VBox2;
	Gtk::Entry entry;
	Gtk::Frame m_Frame_LineWrapped;
	Gtk::Label m_Label_LineWrapped;
	Gtk::Box m_Box1, m_Box2;
	Gtk::Separator m_Separator;
	Gtk::Button m_Button_Yes;
	Gtk::Button m_Button_No;
};

class exchange_window_NE : public	Gtk::Window, airport	
{	
	
	public:

	exchange_window_NE();		
	virtual	~exchange_window_NE();	
		
	protected:			

	//signal	handlers
	void send_value();
	void close_button();	
		
	//widgets
	Gtk::Box shape;
	Gtk::Label	label;
	Gtk::Label	label1;
	Gtk::Box	box;
	Gtk::Entry	entry;
	Gtk::Entry	entry1;
	Gtk::Button	button_close, button_send; 
};	

class exchange_window_SW : public Gtk::Window, airport	
{	
	
	public:

	exchange_window_SW();		
	virtual	~exchange_window_SW();	
		
	protected:			

	//signal	handlers
	void send_value();
	void close_button();	
		
	//widgets
	Gtk::Box shape;
	Gtk::Label	label;
	Gtk::Label	label1;
	Gtk::Box	box;
	Gtk::Entry	entry;
	Gtk::Entry	entry1;
	Gtk::Button	button_close, button_send; 
};


class converter_window_NE_file : public Gtk::Window, airport	
{	
	
	public:

	converter_window_NE_file();		
	virtual	~converter_window_NE_file();	
		
	protected:			

	//signal	handlers
	void send_value();
	void close_button();	
		
	//widgets
	Gtk::Box shape;
	Gtk::Label	label;
	Gtk::Label	label1;
	Gtk::Label	label2;
	Gtk::Box	box;
	Gtk::Entry	entry;
	Gtk::Entry	entry1;
	Gtk::Button	button_close, button_send; 
};

class converter_window_SW_file : public Gtk::Window, airport	
{	
	
	public:

	converter_window_SW_file();		
	virtual	~converter_window_SW_file();	
		
	protected:			

	//signal	handlers
	void send_value();
	void close_button();	
		
	//widgets
	Gtk::Box shape;
	Gtk::Label	label;
	Gtk::Label	label1;
	Gtk::Label	label2;
	Gtk::Box	box;
	Gtk::Entry	entry;
	Gtk::Entry	entry1;
	Gtk::Button	button_close, button_send; 
};

class converter_window_NE_HARD : public Gtk::Window, airport	
{	
	
	public:

	converter_window_NE_HARD();		
	virtual	~converter_window_NE_HARD();	
		
	protected:			

	//signal	handlers
	void send_value();
	void close_button();	
		
	//widgets
	Gtk::Box shape;
	Gtk::Label	label;
	Gtk::Label	label1;
	Gtk::Label	label2;
	Gtk::Box	box;
	Gtk::Entry	entry;
	Gtk::Entry	entry1;
	Gtk::Button	button_close, button_send; 
};

class converter_window_SW_HARD : public Gtk::Window, airport	
{	
	
	public:

	converter_window_SW_HARD();		
	virtual	~converter_window_SW_HARD();	
		
	protected:			

	//signal	handlers
	void send_value();
	void close_button();	
		
	//widgets
	Gtk::Box shape;
	Gtk::Label	label;
	Gtk::Label	label1;
	Gtk::Label	label2;
	Gtk::Box	box;
	Gtk::Entry	entry;
	Gtk::Entry	entry1;
	Gtk::Button	button_close, button_send; 
};



#endif 