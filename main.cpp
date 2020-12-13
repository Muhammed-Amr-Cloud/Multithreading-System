/*
 * main.cpp
 *
 *  Created on: Dec 11, 2020
 *      Author: Muhamed
 */
#include <iostream>
#include <string>
#include <thread>
using namespace std;


/* Abstract Class */
class Actor
{

protected:
	string		   name ;
	unsigned int count ;

public:

	static unsigned int numberOfActorsCreated ;

	/* Default Constructor */
	Actor()
	{
		name  = "Unknown";
		count = 0 ;
		numberOfActorsCreated++;
	}

	/*Overriding*/
	Actor(string _name ,unsigned int _count  )
	{
		name =   _name;
		count = _count;
		numberOfActorsCreated++;
	}

	/*Destructor */
	virtual ~Actor(){
		numberOfActorsCreated--;
	}

	/* Here we made this class an Abstract Class By using virtual Function */
	/* if i dont want to create objects from Actor I could use Pure Virtual Function */

	virtual void decrease () {}; //do nothing
	virtual void increase () {}; //do nothing

	/*setters and Getters*/

	unsigned int getCount (){

		return count;
	}

	void setCount(unsigned int value){

		count = value;
	}

	/***/

	unsigned int getNumberofActorsCreated(){

		return numberOfActorsCreated;
	}

	string getName(){return name;}
	void  setName(string _name ) {name = _name;}
};


unsigned int Actor::numberOfActorsCreated = 0  ;

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

protected:
	unsigned int incrementField ;

public:

	CountWithValue(string _actorname = "unKnown", unsigned int _incount = 0,unsigned int incrementValue = 1):Actor(_actorname,_incount)
	{

		incrementField = incrementValue;
	}

	void decrease()
	{
		count-= incrementField;
	}

	void increase()
	{
	    count+= incrementField;
	}
};



class AutoIncrease:public CountWithValue{


	unsigned int autoIncrease;

public:

	void increase()
		{
		  count += incrementField;
		}


	AutoIncrease(string _actorname = "unKnown",
			unsigned int _incount = 0,
			unsigned int incrementValue = 1,
			unsigned int _autoIncrease = 1):CountWithValue(_actorname,_incount,incrementValue)
	{

		autoIncrease = _autoIncrease;

		for(unsigned int i = 0 ; i < autoIncrease ; i++)
		{
			increase();
		}

	}

};


class AutoDecrease:public CountWithValue{


	unsigned int autoDecrease;

public:

	void decrease()
		{
		  count += incrementField;
		}


	AutoDecrease(string _actorname = "unKnown",
			unsigned int _incount = 0,
			unsigned int incrementValue = 1,
			unsigned int _autoDecrease = 1):CountWithValue(_actorname,_incount,incrementValue)
	{

		autoDecrease = _autoDecrease;

		for(unsigned int i = 0 ; i < autoDecrease ; i++)
		{
			decrease();
		}

	}

};



int main(int argc, char* argv[])
{

	Actor actorArr[10] ;
	int flag  = 0 ;

	thread actorThread(Actor); // seperate thread
	if(argc > 1)
	{
		for(int i = 1 ; i < argc ;i++)
		{

			for(int j = 0 ; j < i; j++)
			{

				// if multiple names, count only one
				if(actorArr[j].getName() == argv[i])
				{
					flag = 1 ;
				}

			}
				if(flag == 1)
				{
					flag = 0 ;

				}
				else
				{
					 actorArr[i].setName(argv[i]);
					cout<<actorArr[i].getName()<<" "<<endl;
				}
		}
	}
	else
	{


	}

	DefaultCount   D("mohamed",0);
	CountWithValue V("Layla",0,3);
	AutoIncrease   A ("Peter",0,3,6);

	cout<<D.getCount()<<" ";
	D.increase();
	cout<<D.getCount()<<" "<<endl;

	cout<<V.getCount()<<" ";
	V.increase();
	cout<<V.getCount()<<" ";
	V.decrease();
	cout<<V.getCount()<<" "<<endl;

	//A.increase();
	cout<<A.getCount()<<endl;
	cout<< A.getNumberofActorsCreated();


    return 0;
}


