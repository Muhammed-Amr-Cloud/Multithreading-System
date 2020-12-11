/*
 * main.cpp
 *
 *  Created on: Dec 11, 2020
 *      Author: Muhamed
 */
#include <iostream>
#include <thread>
#include <string>
using namespace std;

/* Abstract Class */
class Actor
{
	string		   name ;
	unsigned char count ;


public:
	/* Default Constructor */
	Actor()
	{
		name  = "Unknown";
		count = 0 ;
	}

	/*Overriding*/
	Actor(string _name ,unsigned char _count )
	{
		name =   _name;
		count = _count;
	}

	/*Destructor */
	~Actor(){
		// Do nothing
	}

	/* Here we made this class an Abstract Class By using Pure Virtual Function */
	virtual void decrease () = 0  ;
	virtual void increase ()  = 0 ;

};












int main()
{



    return 0;
}


