#include<iostream>
using namespace std;

//Diamond Problem Code
class storble
{

	public:

		storble()
		{
			cout<<"In storble Constructor"<<endl;
		}

		void read()
		{
			cout<<"In storble read"<<endl;
		}
};

class transmitter : public virtual storble
{

	public:
		transmitter()
		{
			cout<<"In transmitter Constructor"<<endl;
		}

};

class receiver : public virtual storble
{

	public:
		receiver()
		{
			cout<<"In receiver Constructor"<<endl;
		}
};

class radio : public transmitter , public receiver
{
	public:
	radio()
	{
		cout<<"In radio Constructor"<<endl;
	
	}
};

int main()
{

	radio rad;
	rad.read();
	return 0;
}
