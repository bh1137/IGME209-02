#pragma once
#include <iostream>
using namespace std;

template <class T>
class Queue
{
public:
	T queueArray[]; //array
	Queue(T newQueue[]) { this->queueArray = newQueue;} //paramertized constructor
	Queue(const Queue &copyVariable) { this.queueArray = copyVariable; } //copy constructor
	~Queue() 
	{ cout << "This object is being destoyed";
		
	} //destructor
	void pushQueue(T variable, T queueArrayAddTo[])
	{
		//check to see if array space is empty
		for (int i = 0; i < sizeof(queueArrayAddTo); i++)
		{
			//if space is found 
			if (queueArrayAddTo[i] == NULL)
			{
				queueArrayAddTo[i] = variable;
				return;
			}
			//if not make a new queue 
			else
			{
				//make a new queue copy 
				int arrayNumber = (sizeof(queueArrayAddTo) * 2);
				T newQueueArray[];

				//call copy constructor
				Queue(newQueueArray);

				//destroy the old queue 
				queueArrayAddTo.~Queue();

				//if space is found 
				if (newQueueArray[i] == NULL)
				{
					newQueueArray[i] = variable;
					return;
				}
			}
		}
	}
	void pop()
	{
		//remove the first element 
		delete queueArray[0];
	}
	void print()
	{
		cout << "Printing Results..." << endl;
		//print 
		for (int i = 0; i < sizeof(queueArray); i++)
		{
			cout << queueArray[i] << endl;
		}
	}
	void getSize()
	{
		//make int variable 
		int queueSize = 0;
		for (int i =0 ; i < sizeof(queueArray); i++)
		{
			//if not null +1
			if (queueArray[i] != NULL)
			{
				queueSize++;
			}
		}
		//print the results
		cout << "The size of the queue is: " << queueSize << endl;
	}
	bool IsEmpty()
	{
		//for loop to see if empty 
		for (int i = 0; i < sizeof(queueArray); i++)
		{
			//if not NULL return 
			if (queueArray[i] != NULL)
			{
				//print message
				cout << "This Queue is not empty." << endl;
				return false;
			}
		}
		//if empty
		cout << "This Queue is empty." << endl;
		return true;
	}
};