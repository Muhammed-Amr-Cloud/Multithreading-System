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

protected:
	string		   name ;
	unsigned int count ;


public:
	/* Default Constructor */
	Actor()
	{
		name  = "Unknown";
		count = 0 ;
	}

	/*Overriding*/
	Actor(string _name ,unsigned int _count )
	{
		name =   _name;
		count = _count;
	}

	/*Destructor */
	virtual ~Actor(){
		// Do nothing
	}

	/* Here we made this class an Abstract Class By using Pure Virtual Function */
	virtual void decrease () = 0  ;
	virtual void increase ()  = 0 ;



	/*setters and Getters*/

	unsigned int getCount (){

		return count;
	}

	void setCount(unsigned int value){

		count = value;
	}

};


class DefaultCount:public Actor{

public:
	/*constructor*/
	DefaultCount(string _actorname = "unKnown", unsigned int _incount = 0):Actor(_actorname,_incount){}


	void decrease()
	{

		count--;
	}

	void increase()
	{

	   count++;
	}

};

class CountWithValue:public Actor{





};








int main()
{

	DefaultCount D("mohamed",0);

	cout<<D.getCount();

	D.increase();

	cout<<D.getCount();

    return 0;
}


