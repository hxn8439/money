

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

class Converter //converter class
{
    int value;
    string filename;
    double worth;
    double worth1;
    double worth2;
    double worth3;
    double worth4;
    double worth5;
    double amount=0;
    double total=0;
    vector<string>money_name;
    vector<double>container;
    
public: //Converter Constructors

    Converter(int val); 
    Converter(string filename, double worth, double worth1, double worth2, double worth3, double worth4, double worth5);
    
    void input(double num, string n);
    double requestTotal();
    double requestAmount();
    double Yen_To_USD(double worth);
    double Taiwan_To_USD(double worth1);
    double Yuan_To_USD(double worth2);
    double Euro_To_USD(double worth3);
    double Dong_To_USD(double worth4);
    double Peso_To_USD(double worth5);
    
    double Yen_USD_File(double worth);
    double Taiwan_USD_File(double worth1);
    double Yuan_USD_File(double worth2);
    double Euro_USD_File(double worth3);
    double Dong_USD_File(double worth4);
    double Peso_USD_File(double worth5);
    
};

void Converter::input(double num, string n) //this constructor calculates the exchange rate if using a ReadFile
{
    for(int i = 0; i <money_name.size();i++)
    {
        if(n.compare(money_name[i])==0)
        {
            amount =num*container[i];
            total +=amount;
        }
    }
}

Converter::Converter(string filename, double worth, double worth1, double worth2, double worth3, double worth4, double worth5) //this constructor opens and read ReadFile
{
    string name_of_money;
    double rawnumber;
	ifstream myFile;
	myFile.open(filename);
	
	if (myFile.is_open())
	{
		
		if(!myFile.is_open())
		{
			cout<<"Unable to open file";
			exit(1);
		}
		
		while(!myFile.eof())
		{
			myFile>>rawnumber>>name_of_money;
			container.push_back(rawnumber);
			money_name.push_back(name_of_money);
		}
	
		worth = container[0];
		
		worth1 = container[1];
		
		worth2 = container[2];
		
		worth3 = container[3];
		
		worth4 = container[4];
		
		worth5 = container[5];
	   
	}
}

 double Converter::requestTotal() //constructor that request total
{
	return total;
}
double Converter::requestAmount() //constructor that request amount
{
	return amount;
}

Converter::Converter(int val) // constructor that evaluate input and set to value variable.
{
	value = val;
}

// These constructors, whether hardcoded or readFile, help calculate and return exchange rate values. 

double Converter::Euro_To_USD(double worth3) 
{
	worth3 = 1.136;
	return worth3 * value;
}

double Converter::Yuan_To_USD(double worth2)
{
	worth2 = 0.145;
	return worth2 * value;
}

double Converter::Dong_To_USD(double worth4)
{
	worth4 = 0.0000429;
	return worth4 * value;
}

double Converter::Taiwan_To_USD(double worth1)
{
	worth1 = 0.0323;
	return worth1 * value;
}

double Converter::Yen_To_USD(double worth)
{
	worth = 0.00933;
	return worth * value;
}

double Converter::Peso_To_USD(double worth5)
{
	worth5 = 0.0521;
	return worth5 * value;
}

double Converter::Euro_USD_File(double worth3)
{
	return worth3 * value;
}

double Converter::Yuan_USD_File(double worth2)
{
	
	return worth2 * value;
}

double Converter::Dong_USD_File(double worth4)
{
	
	return worth4 * value;
}

double Converter::Taiwan_USD_File(double worth1)
{
	
	return worth1 * value;
}

double Converter::Yen_USD_File(double worth)
{
	
	return worth * value;
}

double Converter::Peso_USD_File(double worth5)
{
	
	return worth5 * value;
}

class Exchange //Exchange class
{
	double convertedCurrency;
	double worth;
	double worth1;
	double worth2;
	double worth3;
	double worth4;
	double worth5;
	string readFile;
	
public:
	Exchange(int val, string curr, string readFile);
	double getEqualUSD();
};

 Exchange::Exchange(int val, string curr, string readFile) //Constructor that is responsbile for determining the type of currencies and the choice of
 //input called ReadFile variable that are going to be used in calculations.
{
	Converter converter(val);
	convertedCurrency = 0.0;
	
	if(curr == "yen" && readFile == "No")
		convertedCurrency = converter.Yen_To_USD(worth);
	
	else if(curr == "taiwan" && readFile == "No")
		convertedCurrency = converter.Taiwan_To_USD(worth1);
	
	else if(curr == "yuan" && readFile == "No")
		convertedCurrency = converter.Yuan_To_USD(worth2);
	
	else if(curr == "euro" && readFile == "No")
		convertedCurrency = converter.Euro_To_USD(worth3);
	
	else if(curr == "dong" && readFile == "No")
		convertedCurrency = converter.Dong_To_USD(worth4);
	
	else if(curr == "peso" && readFile == "No")
		convertedCurrency = converter.Peso_To_USD(worth5);
	
	else if(curr == "yen" && readFile == "Yes")
		convertedCurrency = converter.Yen_USD_File(worth);
	
	else if(curr == "taiwan" && readFile == "Yes")
		convertedCurrency = converter.Taiwan_USD_File(worth1);
	
	else if(curr == "yuan" && readFile == "Yes")
		convertedCurrency = converter.Yuan_USD_File(worth2);
	
	else if(curr == "euro" && readFile == "Yes")
		convertedCurrency = converter.Euro_USD_File(worth3);
	
	else if(curr == "dong" && readFile == "Yes")
		convertedCurrency = converter.Dong_USD_File(worth4);
	
	else if(curr == "peso" && readFile == "Yes")
		convertedCurrency = converter.Peso_USD_File(worth5);
}

double Exchange::getEqualUSD()//this constructor 
{
	return convertedCurrency;
}

int main(int argc, char ** argv)
{
	string readFile;
	string filename = argv[1];
	int value;
	string currency;
	double USD;
	double totalUSD = 0.0;
	string office1, tmp, office2, name1, name2;
	string location = "";
	
	double worth;
	double worth1;
	double worth2;
	double worth3;
	double worth4;
	double worth5;
	
	cout << "Read in file of currencies? ";
	cin >> readFile;
	if (readFile == "No") // If input No for not reading the file
	{
		cout<<"~~~Ok, using pre-loaded currencies.~~~"<<endl<<endl;
		cout << "Enter name of Exchange office and manager: ";
		cin >> office1 >> tmp >> name1;
		cout << "Enter name of Exchange office and manager: ";
		cin >> office2 >> tmp >> name2;
		cout << endl;
		cout << fixed << setprecision(2);
		
		while(location != "exit")
		{
			cout << "********" << endl;
			cout << "Hello traveler! Where are you in the airport? ";
			cin >> location;
			cout << "********" << endl << endl;
			if(location != "exit")
			{
				if(location == "North" || location == "north" || location == "East" || location == "east")
				{
					cout << "Welcome to " << office1 << " " << tmp<< " ";
					cout << "Please contact manager " << name1 << " if you have any complaints." << endl;
				}
				
				else
				{
					cout << "Welcome to " << office2 << " " << tmp<< " ";
					cout << "Please contact manager " << name2 << " if you have any complaints." << endl;
				}
				
				cout << "What currency are you converting to dollars and how much? ";
				cin >> value >> currency;
				
				Exchange exchange(value, currency, readFile);
				USD = exchange.getEqualUSD();
				totalUSD += USD;
				if(USD != 0)
				cout << "Here you go: $" << USD << endl << endl<<endl;
				else
				cout << "We do not convert " << currency << " currency here. Sorry." << endl << endl<<endl;
			}
		} 
	}
	
	else if(readFile == "Yes") // If input Yes for reading the file
	{
		Converter obj(filename, worth, worth1, worth2, worth3, worth4, worth5);
		cout<<"~~~Ok, currencies read in the file!"<<endl<<endl;
		cout << "Enter name of Exchange office and manager: ";
		cin >> office1 >> tmp >> name1;
		cout << "Enter name of Exchange office and manager: ";
		cin >> office2 >> tmp >> name2;
		cout << endl;
		cout << fixed << setprecision(2);
		
		while(location != "exit")
		{
			cout << "********" << endl;
			cout << "Hello traveler! Where are you in the airport? ";
			cin >> location;
			cout << "********" << endl << endl;
			if(location != "exit")
			{
				if(location == "North" || location == "north" || location == "East" || location == "east")
				{
					cout << "Welcome to " << office1 << " " << tmp<< " ";
					cout << "Please contact manager " << name1 << " if you have any complaints." << endl;
				}
				
				else
				{
					cout << "Welcome to " << office2 << " " << tmp<< " ";
					cout << "Please contact manager " << name2 << " if you have any complaints." << endl;
				}
				
				cout << "What currency are you converting to dollars and how much? ";
				cin >> value >> currency;
				obj.input(value,currency);
				USD = obj.requestAmount();
				totalUSD =obj.requestTotal();
				if(USD != 0)
				cout << "Here you go: $" << USD << endl << endl<<endl;
				else
				cout << "We do not convert " << currency << " currency here. Sorry." << endl << endl<<endl;
			}
		}
	}
	
	else // Error handling if input for reading file response is totally different from Yes to No
	{
		cout<<"Invalid input, please restart the program and input Yes or No response exactly!."<<endl<<endl;
	}
	
	cout << "$$$Total dollars given out: $" << totalUSD << endl;
	cout << "Exiting..." << endl<<endl;
}
	
	