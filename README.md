# money
README
**************
File included: money.cpp
**************
This program converts foreign currencies to USD currencies for users at exchanges at the XYZ airport. This
Airport has two currency exchange offices.  

**************
Compilation instructions:

->This is built in a Lubuntu virtual machine

->In terminal:

	g++ -o money money.cpp
  
	./money currency.txt
  
	No
  
	ABC Conversions Armin
  
	DEF Conversions Jep
  
	North
  
	200 yen
  
	West
  
	300 dinar
  
	West
  
	300 peso
  
	exiting

_________________________________

->In terminal:
	g++ -o money money.cpp
  
	./money currency.txt
  
	Yes
  
	ABC Conversions Armin
  
	DEF Conversions Jep
  
	North
  
	200 yen
  
	West
  
	300 dinar
  
	West
  
	300 peso
  
	exiting


GUI VERSION
**************
File included: money.cpp, money.h, makefile, main.cpp, currency.txt
**************
This program converts foreign currencies to USD currencies for users at exchanges at the XYZ airport. This
Airport has two currency exchange offices. Note that this program is designed as a gtkmm window environment.

**************
Compilation instructions:
->This is built in a Lubuntu virtual machine
->In terminal:
	make
	
	./money
	
	ABC CONVERSIONS
	
	Armin
	
	click submit
	
	DEF CONVERSIONS
	
	Jep
	
	click submit
	
	click yes
	
	100000
	
	yen
	
	click ok
	
	10000
	
	dong
	
	click ok
	
	click close
