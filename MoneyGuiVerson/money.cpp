//Hamilton Nguyen 1000538439 

#include "money.h"

ReadFileWindow::ReadFileWindow()
: m_HBox(Gtk::ORIENTATION_VERTICAL, 5), m_VBox2(Gtk::ORIENTATION_VERTICAL, 5), m_Frame_LineWrapped("Question 1:"), m_Box1(Gtk::ORIENTATION_VERTICAL, 10), 
m_Box2(Gtk::ORIENTATION_VERTICAL, 10), m_Button_Yes("Yes"), m_Button_No("No")
{
  // Set title and border of the window
  set_size_request(700, 200);	
  set_title("Money Converter");
  set_border_width(5);

  add(m_HBox);

  m_HBox.pack_start(m_VBox2, Gtk::PACK_SHRINK);

  m_Label_LineWrapped.set_text(

	"Read in File of currencies?");
  m_Label_LineWrapped.set_line_wrap();
  m_Frame_LineWrapped.add(m_Label_LineWrapped);
  m_VBox2.pack_start(m_Frame_LineWrapped, Gtk::PACK_SHRINK);

  //Put the inner boxes and the separator in the outer box:
  m_HBox.pack_start(m_Box1);
  m_HBox.pack_start(m_Separator);
  m_HBox.pack_start(m_Box2);

  // Set the inner boxes' borders
  m_Box2.set_border_width(10);
  m_Box1.set_border_width(10);

  // Put submit button in Box2:
  m_Box2.pack_start(m_Button_Yes);

  // Make the button the default widget
  m_Button_Yes.set_can_default();
  m_Button_Yes.grab_default();

  // Connect the clicked signal of the button to
  // ReadFileWindow::on_button_clicked()
  m_Button_Yes.signal_clicked().connect(sigc::mem_fun(*this, &ReadFileWindow::on_button_clicked_Yes) );
  
    // Put submit button in Box2:
  m_Box2.pack_start(m_Button_No);

  // Make the button the default widget
  m_Button_No.set_can_default();
  m_Button_No.grab_default();

  // Connect the clicked signal of the button to
  // ReadFileWindow::on_button_clicked()
  m_Button_No.signal_clicked().connect(sigc::mem_fun(*this, &ReadFileWindow::on_button_clicked_No) );

  
  show_all_children();
}

ReadFileWindow::~ReadFileWindow()
{
}

void ReadFileWindow::on_button_clicked_Yes()
{
  
  verifyfile = 1;
  std::ofstream written("verify.txt");
	if(written.is_open())
	{	
		written<<verifyfile<<std::endl;
	}
  hide(); 
}

void ReadFileWindow::on_button_clicked_No()
{
	verifyfile = 2;
	std::ofstream written("verify.txt");
	if(written.is_open())
	{	
		written<<verifyfile<<std::endl;
	}
  hide(); //to close the application.
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

exchange_window_NE::exchange_window_NE() : box(Gtk::ORIENTATION_VERTICAL), button_close("Close"), button_send("Submit")
{			
	set_size_request(400, 200);			
	set_title("Airport Exchange N&E");	
	
	add(box);	
	
	label.set_text("ENTER A NAME OF EXCHANGE OFFICE");	
	box.pack_start(label);	
	entry.set_max_length(4000);
	entry.set_text("e.g. ABC CONVERSIONS");	
	entry.select_region(0, entry.get_text_length());
	box.pack_start(entry);	

	label1.set_text("ENTER A NAME OF A MANAGER");	
	box.pack_start(label1);	
	entry1.set_max_length(4000);
	entry1.set_text("e.g. Armin");	
	entry1.select_region(1, entry1.get_text_length());
	box.pack_start(entry1);	

	button_send.signal_clicked().connect(sigc::mem_fun(*this,&exchange_window_NE::send_value));		
	box.pack_start(button_send);	

	button_close.signal_clicked().connect(	sigc::mem_fun(*this, &exchange_window_NE::close_button));
	box.pack_start(button_close);	

	button_close.set_can_default();	
	button_close.grab_default();	

	show_all_children();	
}	
	
exchange_window_NE::~exchange_window_NE()
{

}	

void	exchange_window_NE::send_value()	
{			
	 office_NE=entry.get_text();
	 manager_NE=entry1.get_text();
	 
	 std::ofstream written("airportNE.txt");
	 if(written.is_open())
	 {
		 written<<office_NE<<std::endl;
		 written<<manager_NE<<std::endl;
	 } 
	 

	hide();	
}	
	
void exchange_window_NE::close_button()
{			
	exit(0);
}	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

exchange_window_SW::exchange_window_SW() : box(Gtk::ORIENTATION_VERTICAL), button_close("Close"), button_send("Submit")
{			
	set_size_request(400, 200);			
	set_title("Airport Exchange S&W");	
	
	add(box);	
	
	label.set_text("ENTER A NAME OF EXCHANGE OFFICE");	
	box.pack_start(label);	
	entry.set_max_length(4000);
	entry.set_text("e.g. DEF CONVERSIONS");	
	entry.select_region(0, entry.get_text_length());
	box.pack_start(entry);	

	label1.set_text("ENTER A NAME OF A MANAGER");	
	box.pack_start(label1);	
	entry1.set_max_length(4000);
	entry1.set_text("e.g. Jep");	
	entry1.select_region(1, entry1.get_text_length());
	box.pack_start(entry1);	

	button_send.signal_clicked().connect(sigc::mem_fun(*this,&exchange_window_SW::send_value));		
	box.pack_start(button_send);	

	button_close.signal_clicked().connect(	sigc::mem_fun(*this, &exchange_window_SW::close_button));
	box.pack_start(button_close);	

	button_close.set_can_default();	
	button_close.grab_default();	

	show_all_children();	
}	
	
exchange_window_SW::~exchange_window_SW()
{

}	

void	exchange_window_SW::send_value()	
{			 
	office_SW=entry.get_text();
	manager_SW=entry1.get_text();

	std::ofstream written("airportSW.txt");
	if(written.is_open())
	{
		written<<office_SW<<std::endl;
		written<<manager_SW<<std::endl;
	} 

	hide();	
}	
	
void exchange_window_SW::close_button()
{			
	exit(0);
}

///////////////////////////////////////////////////////////////////////////////////////

converter_window_NE_file::converter_window_NE_file() : box(Gtk::ORIENTATION_VERTICAL), button_close("Close"), button_send("Convert")
{			
	std::string data;
	std::ifstream file;
	std::string line;
	file.open("airportNE.txt");

	while(getline(file,line))
	{
		std::stringstream linestream(line);
		getline(linestream, raw[i]);
		++i;
	}	

	std::string office_NE = raw[0];
	std::string manager_NE = raw[1];

	set_size_request(500, 300);			
	set_title("Airport Exchange N&E Converter");	

	add(box);	

	label2.set_text("Welcome to "+ office_NE +". Please contact the manager "+  manager_NE+ " if you haven any complaints");	
	box.pack_start(label2);	

	label.set_text("What currency are you converting to dollars.");	
	box.pack_start(label);	
	entry.set_max_length(4000);
	entry.set_text("e.g. 100");	
	entry.select_region(1, entry.get_text_length());
	box.pack_start(entry);	

	label1.set_text("Enter a name of currency you are converting from.");	
	box.pack_start(label1);	
	entry1.set_max_length(4000);
	entry1.set_text("e.g. yen");	
	entry1.select_region(2, entry1.get_text_length());
	box.pack_start(entry1);	

	button_send.signal_clicked().connect(sigc::mem_fun(*this,&converter_window_NE_file::send_value));		
	box.pack_start(button_send);	

	button_close.signal_clicked().connect(	sigc::mem_fun(*this, &converter_window_NE_file::close_button));
	box.pack_start(button_close);	

	button_close.set_can_default();	
	button_close.grab_default();	

	show_all_children();
}	
	
converter_window_NE_file::~converter_window_NE_file()
{

}	

void	converter_window_NE_file::send_value()	
{			
	double yen;
	double taiwan;
	double yuan;
	double euro;
	double dong;
	double peso;
	
	std::vector<double>container;
	std::vector<std::string>money_name;
	std::string name_of_money;
    double rawnumber;
	
	std::ifstream myFile;
	myFile.open("currency.txt");
	
	if (myFile.is_open())
	{
		
		if(!myFile.is_open())
		{
			std::cout<<"Unable to open file";
			exit(1);
		}
		
		while(!myFile.eof())
		{
			myFile>>rawnumber>>name_of_money;
			container.push_back(rawnumber);
			money_name.push_back(name_of_money);
		}
	
		yen = container[0];
		
		taiwan = container[1];
		
		yuan = container[2];
		
		euro = container[3];
		
		dong = container[4];
		
		peso = container[5];
	   
	}
	
	std::string	input=entry.get_text();
	double value1 = stoi(input);
	std::string	input1=entry1.get_text();
	
	for (int i=0; i<input1.size(); i++)
	{
		input1[i] = tolower(input1[i]);
	}
	
	if(input1 == "yen" )
	{
		value1 = yen * value1;
		std::ostringstream strs;
		strs << value1;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}	
	
	else if(input1 == "taiwan")
	{
		value1 = taiwan * value1;
		std::ostringstream strs;
		strs << value1;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}	
	
	else if(input1 == "yuan")
	{
		value1 = yuan * value1;
		std::ostringstream strs;
		strs << value1;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}
	
	else if(input1 == "euro")
	{
		
		value1 = euro * value1;
		std::ostringstream strs;
		strs << value1;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}
	
	else if(input1 == "dong")
	{
		std::ostringstream strs;
		value1 = dong * value1;
		strs << value1;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}
	
	else if(input1 == "peso")
	{
		std::ostringstream strs;
		value1 = peso * value1;
		strs << value1;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}
	
	else
	{
		Gtk::MessageDialog dialog (*this, "Invalid currency",false,Gtk::MESSAGE_ERROR);
		dialog.set_secondary_text("We do not convert the "+ input1+" currency here. Sorry.");
		dialog.run();
	}
}	
	
void converter_window_NE_file::close_button()
{			
	hide();	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

converter_window_SW_file::converter_window_SW_file() : box(Gtk::ORIENTATION_VERTICAL), button_close("Close"), button_send("Convert")
{			
	std::string data;
	std::ifstream file;
	std::string line;
	file.open("airportSW.txt");
	
	while(getline(file,line))
	{
		std::stringstream linestream(line);
		getline(linestream, raw[i]);
		++i;
	}	
	
	std::string office_SW = raw[0];
	std::string manager_SW = raw[1];

	set_size_request(500, 300);			
	set_title("Airport Exchange S&W Converter");	
	
	add(box);	
	
	label2.set_text("Welcome to "+ office_SW +". Please contact the manager "+  manager_SW+ " if you haven any complaints");	
	box.pack_start(label2);	
	
	label.set_text("What currency are you converting to dollars.");	
	box.pack_start(label);	
	entry.set_max_length(4000);
	entry.set_text("e.g. 100");	
	entry.select_region(1, entry.get_text_length());
	box.pack_start(entry);	

	label1.set_text("Enter a name of currency you are converting from.");	
	box.pack_start(label1);	
	entry1.set_max_length(4000);
	entry1.set_text("e.g. yen");	
	entry1.select_region(2, entry1.get_text_length());
	box.pack_start(entry1);	

	button_send.signal_clicked().connect(sigc::mem_fun(*this,&converter_window_SW_file::send_value));		
	box.pack_start(button_send);	

	button_close.signal_clicked().connect(	sigc::mem_fun(*this, &converter_window_SW_file::close_button));
	box.pack_start(button_close);	

	button_close.set_can_default();	
	button_close.grab_default();	

	show_all_children();
}	
	
converter_window_SW_file::~converter_window_SW_file()
{

}	

void converter_window_SW_file::send_value()	
{			
	double yen;
	double taiwan;
	double yuan;
	double euro;
	double dong;
	double peso;
	
	std::vector<double>container;
	std::vector<std::string>money_name;
	std::string name_of_money;
    double rawnumber;
	
	std::ifstream myFile;
	myFile.open("currency.txt");
	
	if (myFile.is_open())
	{
		
		if(!myFile.is_open())
		{
			std::cout<<"Unable to open file";
			exit(1);
		}
		
		while(!myFile.eof())
		{
			myFile>>rawnumber>>name_of_money;
			container.push_back(rawnumber);
			money_name.push_back(name_of_money);
		}
	
		yen = container[0];
		
		taiwan = container[1];
		
		yuan = container[2];
		
		euro = container[3];
		
		dong = container[4];
		
		peso = container[5];
	   
	}
	
	std::string	input=entry.get_text();
	double value1 = stoi(input);
	std::string	input1=entry1.get_text();
	
	for (int i=0; i<input1.size(); i++)
	{
		input1[i] = tolower(input1[i]);
	}
	
	if(input1 == "yen" )
	{
		value1 = yen * value1;
		std::ostringstream strs;
		strs << value1;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}	
	
	else if(input1 == "taiwan")
	{
		value1 = taiwan * value1;
		std::ostringstream strs;
		strs << value1;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}	
	
	else if(input1 == "yuan")
	{
		value1 = yuan * value1;
		std::ostringstream strs;
		strs << value1;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}
	
	else if(input1 == "euro")
	{
		
		value1 = euro * value1;
		std::ostringstream strs;
		strs << value1;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}
	
	else if(input1 == "dong")
	{
		std::ostringstream strs;
		value1 = dong * value1;
		strs << value1;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}
	
	else if(input1 == "peso")
	{
		std::ostringstream strs;
		value1 = peso * value1;
		strs << value1;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}
	
	else
	{
		Gtk::MessageDialog dialog (*this, "Invalid currency",false,Gtk::MESSAGE_ERROR);
		dialog.set_secondary_text("We do not convert the "+ input1+" currency here. Sorry.");
		dialog.run();
	}
	

}	
	
void converter_window_SW_file::close_button()
{			
	exit(0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

converter_window_NE_HARD::converter_window_NE_HARD() : box(Gtk::ORIENTATION_VERTICAL), button_close("Close"), button_send("Convert")
{			
	std::string data;
	std::ifstream file;
	std::string line;
	file.open("airportNE.txt");
	
	while(getline(file,line))
	{
		std::stringstream linestream(line);
		getline(linestream, raw[i]);
		++i;
	}	
	
	std::string office_NE = raw[0];
	std::string manager_NE = raw[1];

	set_size_request(500, 300);			
	set_title("Airport Exchange N&E Converter");	
	
	add(box);	
	
	label2.set_text("Welcome to "+ office_NE +". Please contact the manager "+  manager_NE+ " if you haven any complaints");	
	box.pack_start(label2);	
	
	label.set_text("What currency are you converting to dollars.");	
	box.pack_start(label);	
	entry.set_max_length(4000);
	entry.set_text("e.g. 100");	
	entry.select_region(1, entry.get_text_length());
	box.pack_start(entry);	

	label1.set_text("Enter a name of currency you are converting from.");	
	box.pack_start(label1);	
	entry1.set_max_length(4000);
	entry1.set_text("e.g. yen");	
	entry1.select_region(2, entry1.get_text_length());
	box.pack_start(entry1);	

	button_send.signal_clicked().connect(sigc::mem_fun(*this,
	&converter_window_NE_HARD::send_value));		
	box.pack_start(button_send);	

	button_close.signal_clicked().connect(	sigc::mem_fun(*this, 
	&converter_window_NE_HARD::close_button));
	box.pack_start(button_close);	

	button_close.set_can_default();	
	button_close.grab_default();	

	show_all_children();

}	
	
converter_window_NE_HARD::~converter_window_NE_HARD()
{

}	

void	converter_window_NE_HARD::send_value()	
{			
	std::string	input=entry.get_text();
	double value = stoi(input);
	std::string	input1=entry1.get_text();
	double worth;
	
	
	for (int i=0; i<input1.size(); i++)
	{
		input1[i] = tolower(input1[i]);
	}
	
	if(input1 == "yen" )
	{
		worth = 0.00933;
		value = worth * value;
		std::ostringstream strs;
		strs << value;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}	
	
	else if(input1 == "taiwan")
	{
		worth = 0.0323;
		value = worth * value;
		std::ostringstream strs;
		strs << value;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}	
	
	else if(input1 == "yuan")
	{
		worth = 0.145;
		value = worth * value;
		std::ostringstream strs;
		strs << value;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}
	
	else if(input1 == "euro")
	{
		worth = 1.136;
		value = worth * value;
		std::ostringstream strs;
		strs << value;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}
	
	else if(input1 == "dong")
	{
		worth = 0.0000429;
		std::ostringstream strs;
		value = worth * value;
		strs << value;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}
	
	else if(input1 == "peso")
	{
		worth = 0.0521;
		std::ostringstream strs;
		value = worth * value;
		strs << value;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}
	
	else
	{
		Gtk::MessageDialog dialog (*this, "Invalid currency",false,Gtk::MESSAGE_ERROR);
		dialog.set_secondary_text("We do not convert the "+ input1+" currency here. Sorry.");
		dialog.run();
	}	

}	
	
void converter_window_NE_HARD::close_button()
{			
	hide();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

converter_window_SW_HARD::converter_window_SW_HARD() : box(Gtk::ORIENTATION_VERTICAL), button_close("Close"), button_send("Convert")
{				
	std::string data;
	std::ifstream file;
	std::string line;
	file.open("airportSW.txt");
	
	while(getline(file,line))
	{
		std::stringstream linestream(line);
		getline(linestream, raw[i]);
		++i;
	}	
	
	std::string office_SW = raw[0];
	std::string manager_SW = raw[1];

	set_size_request(500, 300);			
	set_title("Airport Exchange S&W Converter");	
	
	add(box);	
	
	label2.set_text("Welcome to "+ office_SW +". Please contact the manager "+  manager_SW+ " if you haven any complaints");	
	box.pack_start(label2);	
	
	label.set_text("What currency are you converting to dollars.");	
	box.pack_start(label);	
	entry.set_max_length(4000);
	entry.set_text("e.g. 100");	
	entry.select_region(1, entry.get_text_length());
	box.pack_start(entry);	

	label1.set_text("Enter a name of currency you are converting from.");	
	box.pack_start(label1);	
	entry1.set_max_length(4000);
	entry1.set_text("e.g. yen");	
	entry1.select_region(2, entry1.get_text_length());
	box.pack_start(entry1);	

	button_send.signal_clicked().connect(sigc::mem_fun(*this,
	&converter_window_SW_HARD::send_value));		
	box.pack_start(button_send);	

	button_close.signal_clicked().connect(	sigc::mem_fun(*this, 
	&converter_window_SW_HARD::close_button));
	box.pack_start(button_close);	

	button_close.set_can_default();	
	button_close.grab_default();	

	show_all_children();

	
}	
	
converter_window_SW_HARD::~converter_window_SW_HARD()
{

}	

void converter_window_SW_HARD::send_value()	
{			
	std::string	input=entry.get_text();
	double value = stoi(input);
	std::string	input1=entry1.get_text();
	double worth;
	
	for (int i=0; i<input1.size(); i++)
	{
		input1[i] = tolower(input1[i]);
	}
	
	if(input1 == "yen" )
	{
		worth = 0.00933;
		value = worth * value;
		std::ostringstream strs;
		strs << value;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}	
	
	else if(input1 == "taiwan")
	{
		worth = 0.0323;
		value = worth * value;
		std::ostringstream strs;
		strs << value;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}	
	
	else if(input1 == "yuan")
	{
		worth = 0.145;
		value = worth * value;
		std::ostringstream strs;
		strs << value;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}
	
	else if(input1 == "euro")
	{
		worth = 1.136;
		value = worth * value;
		std::ostringstream strs;
		strs << value;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}
	
	else if(input1 == "dong")
	{
		worth = 0.0000429;
		value = worth * value;
		std::ostringstream strs;
		strs << value;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}
	
	else if(input1 == "peso")
	{
		worth = 0.0521;
		value = worth * value;
		std::ostringstream strs;
		strs << value;
		input = strs.str();
		Gtk::MessageDialog dialog (*this, "Converted",false,Gtk::MESSAGE_INFO);
		dialog.set_secondary_text("Here you go: $"+ input+" US Dollars.");
		dialog.run();
	}
	
	else
	{
		Gtk::MessageDialog dialog (*this, "Invalid currency",false,Gtk::MESSAGE_ERROR);
		dialog.set_secondary_text("We do not convert the "+ input1+" currency here. Sorry.");
		dialog.run();
	}	
}	
	
void converter_window_SW_HARD::close_button()
{			
	exit(0);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


