#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;
class Bus_Details;
class Allotment;
class Display;


static int p = 0;


void vline(char ch)

{

	for (int i = 90; i > 0; i--)

		cout << ch;

}

class Bus_Details {

public:
	char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
	int cost;

	Bus_Details() {}                                                                                         

	void addbus();
	void position(int i);


};

class Allotment : public Bus_Details {
public:
	void allot();
	void empty();
	void cancel();



};
class Display : public Allotment {
public:

	void show() {

		int n;

		char number[5];

		cout << "Enter bus no: ";

		cin >> number;

		for (n = 0; n <= p; n++)

		{

			if (strcmp(bus[n].busn, number) == 0)

				break;

		}

		while (n <= p)

		{

			vline('*');

			cout << "Bus no: \t" << bus[n].busn

				<< "\nDriver: \t" << bus[n].driver << "\t\tArrival time: \t"

				<< bus[n].arrival << "\tDeparture time:" << bus[n].depart

				<< "\nFrom: \t\t" << bus[n].from << "\t\tTo: \t\t" <<

				bus[n].to << "\nCost: " << bus[n].cost << "\n";

			vline('*');

			bus[0].position(n);

			int a = 1;

			for (int i = 0; i < 8; i++)

			{

				for (int j = 0; j < 4; j++)

				{

					a++;

					if (strcmp(bus[n].seat[i][j], "Empty") != 0)

						cout << "\nThe seat no " << (a - 1) << " is reserved for " << bus[n].seat[i][j] << ".";

				}

			}
			system("pause");

			break;

		}

		if (n > p)

			cout << "Enter correct bus no: ";

	}



	void avail() {
		for (int n = 0; n < p; n++)

		{
			cout << endl << "Index Number: " << n + 1 << endl;
			vline('_');

			cout << "Bus no: \t" << bus[n].busn << "\nDriver: \t" << bus[n].driver

				<< "\t\tArrival time: \t" << bus[n].arrival << "\tDeparture Time: \t"

				<< bus[n].depart << "\nFrom: \t\t" << bus[n].from << "\t\tTo: \t\t\t"

				<< bus[n].to << "\n" << "Cost per Seat: \t\t" << bus[n].cost << endl;

			/*vline('*');*/
			cout << endl;
			vline('_');
			cout << endl;
			system("pause");

		}
	}
}bus[10];

void Allotment::empty() {
	for (int i = 0; i < 8; i++)

	{

		for (int j = 0; j < 4; j++)

		{

			strcpy(bus[p].seat[i][j], "Empty");

		}

	}

}
void Bus_Details::addbus() {

	cout << "Enter bus no: ";

	cin >> bus[p].busn;

	cout << "\nEnter Driver's name: ";

	cin >> bus[p].driver;

	cout << "\nArrival time: ";

	cin >> bus[p].arrival;

	cout << "\nDeparture: ";

	cin >> bus[p].depart;

	cout << "\nFrom: \t\t\t";

	cin >> bus[p].from;

	cout << "\nTo: \t\t\t";

	cin >> bus[p].to;
	cout << "\n Enter Cost: \t\t";
	cin >> bus[p].cost;

	bus[p].empty();

	p++;
	cout << endl << "Details Entered Successfully!!" << endl;


}

void Allotment::allot() {
	int seat;

	char number[5];

top:

	cout << "Bus no: ";

	cin >> number;

	int n;

	for (n = 0; n <= p; n++)

	{

		if (strcmp(bus[n].busn, number) == 0)

			break;

	}

	while (n <= p)

	{

		cout << "\nEnter Seat Number: ";

		cin >> seat;

		if (seat > 32)

		{

			cout << "\nThere are only 32 seats available in this bus.";

		}

		else

		{

			if (strcmp(bus[n].seat[seat / 4][(seat % 4) - 1], "Empty") == 0)

			{

				cout << "Enter passanger's name: ";

				cin >> bus[n].seat[seat / 4][(seat % 4) - 1];
				cout << "Cost of Ticket: " << bus[n].cost;
				cout << "Seat No." << seat << " Reserved for " << bus[n].seat[seat / 4][(seat % 4) - 1];

				break;

			}

			else

				cout << "The seat no. is already reserved.\n";

		}
		cout << endl;

	}

	if (n > p)

	{

		cout << "Enter correct bus no.\n";
		cout << endl;

		goto top;

	}
}






void Allotment::cancel() {
	int seat;

	char number[5];
	cout << "Bus no: ";

	cin >> number;

	int n;

	for (n = 0; n <= p; n++)

	{

		if (strcmp(bus[n].busn, number) == 0)

			break;

	}

	if (n <= p)

	{

		cout << "\nEnter Seat Number: ";

		cin >> seat;

		if (seat > 32)

		{

			cout << "\nThere are only 32 seats available in this bus.";

		}

		else

		{
			strcpy(bus[n].seat[seat / 4][(seat % 4) - 1], "Empty");
			cout << "Reservation Cancelled";
			cout << endl;
		}
	}
}

void Bus_Details::position(int l) {
	int s = 0; int x = 0;

	for (int i = 0; i < 8; i++)

	{

		cout << "\n";

		for (int j = 0; j < 4; j++)

		{

			s++;

			if (strcmp(bus[l].seat[i][j], "Empty") == 0)

			{

				cout.width(5);

				cout.fill(' ');

				cout << s << ".";

				cout.width(10);

				cout.fill(' ');

				cout << bus[l].seat[i][j];

				x++;

			}

			else

			{

				cout.width(5);

				cout.fill(' ');

				cout << s << ".";

				cout.width(10);

				cout.fill(' ');

				cout << bus[l].seat[i][j];

			}

		}

	}

	cout << "\n\nThere are " << x << " seats empty in Bus No: " << bus[l].busn;

}



int main() {

	system("cls");

	int ch;
	int ch2;

	while (1)

	{


		system("cls");

		cout << "\n\n\n\n\n";
		cout << "\t\t\t\t\t\t"; vline('*');
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t\t\tBUS MANAGEMENT SYSTEM" << endl;;
		cout << "\t\t\t\t\t\t"; vline('*');
		cout << "\n\t\t\t\t\t\t\t1.Bus Operator\n\t\t\t"

			<< "\n\t\t\t\t\t\t\t2.Customer\n\t\t\t";
		cout << endl;
		cout << "\t\t\t\t\t\t\t3.To Quit Portal\n";
		cout << "\t\t\t\t\t\t"; vline('*');
		cout << endl;

		cout << "\n\t\t\tEnter your choice:-> ";

		cin >> ch;
		cout << endl;

		switch (ch)

		{

		case 1:

			do {
				system("cls");
				cout << "\n\n\n\n\n";
				cout << "\t\t\t\t\t\t"; vline('*');
				cout << endl;
				cout << "\t\t\t\t\t\t\t\t\t\tBUS MANAGEMENT SYSTEM" << endl;;
				cout << "\t\t\t\t\t\t"; vline('*');
				cout << "\n\t\t\t\t\t\t\t1.Add New Bus";
				cout << "\n\t\t\t\t\t\t\t2.Display Buses";
				cout << "\n\t\t\t\t\t\t\t3.Check Seats Of Bus";
				cout << "\n\t\t\t\t\t\t\t4.Main Menu";
				cout << endl;
				cout << "\t\t\t\t\t\t"; vline('*');
				cout << endl;
				cout << "\n\t\t\tEnter your choice:-> ";
				cin >> ch2;
				switch (ch2)
				{
				case 1:
					bus[p].addbus();

					break;
				case 2:
					bus[0].avail();
					break;

				case 3:
					bus[0].show();
					break;
				default:
					cout << "Invalid Choice, Please Re-Enter!\n";
					system("pause");
					break;

				case 4:

					break;
				}
			} while (ch2 != 4);

			break;
		case 2:
			do {
				system("cls");
				cout << "\n\n\n\n\n";
				cout << "\t\t\t\t\t\t"; vline('*');
				cout << endl;
				cout << "\t\t\t\t\t\t\t\t\t\tBUS MANAGEMENT SYSTEM" << endl;;
				cout << "\t\t\t\t\t\t"; vline('*');
				cout << "\n\t\t\t\t\t\t\t1.Display Available Buses";
				cout << "\n\t\t\t\t\t\t\t2.Check Availabilty of Seats";
				cout << "\n\t\t\t\t\t\t\t3.Book a Seat";
				cout << "\n\t\t\t\t\t\t\t4.Cancel Booked Seat";
				cout << "\n\t\t\t\t\t\t\t5.Main Menu";
				cout << endl;
				cout << "\t\t\t\t\t\t"; vline('*');
				cout << endl;
				cout << "\n\t\t\tEnter your choice:-> ";
				cin >> ch2;
				switch (ch2)
				{
				case 1:
					bus[0].avail();

					break;
				case 2:
					bus[0].show();
					break;
				case 3:
					bus[p].allot();
					break;
				case 4:
					bus[p].cancel();
					break;
				default:
					cout << "Invalid Choice, Please Re-Enter!";
					system("pause");
				case 5:
					system("pause");
					break;
				}
			} while (ch2 != 5);
			break;
		case 3:
			cout << "\t\t\t\t\t\tThank You For Using!!";
			system("pause");
			exit(0);

			break;
		default:
			cout << "Invalid Choice, Please Re-Enter!!";
			system("pause");
		}



		system("pause");

	}

	return 0;

}







