#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;


string csv_name[5]={"movie_test1.csv","movie_test2.csv","movie_test3.csv","movie_test4.csv","movie_test5.csv"};

class Screen{
private:
	int ID;
	int max_seats;
	string curr_Mov;
	string facilities;
public:
	Screen(int id,int seats,string facility)
	{
		ID=id;
		max_seats=seats;
		facilities=facility;
		
		ifstream file;//this part is for retrieving moive name from file
		file.open(csv_name[ID-1].c_str());
		getline(file,curr_Mov,',');
		file.close();
	}
	int getID(){
		return ID;
	}
	int getMaxSeats(){
		return max_seats;
	}
	string getCurrMov(){
		return curr_Mov;
	}
	string getFacilities(){
		return facilities;
	}

	void displayScreenInfo();

};

void Screen::displayScreenInfo()
{

	    	cout<<"\n\n";
	    	cout<<"\t\t===========================================================\n";
	    	cout<<"\t\tScreen ID :\t"<<"\t"<<getID()<<endl;
		    cout<<"\t\tMaximum seats :\t"<<"\t"<<getMaxSeats()<<endl;
		    cout<<"\t\tCurrent Movie :\t"<<"\t"<<getCurrMov()<<endl;
		    cout<<"\t\tScreen Facilities :\t"<<getFacilities()<<endl;
		    cout<<"\t\t===========================================================\n\n\n";;
		    char temp;
		    cout<<"\n\n\t\tPRESS ANY KEY TO CONTINUE\n";
			cin>>temp;
		    
		    return;

	
}

int main()
{
	Screen Screen1(1,250,"Standard,Ideal viewing position,Comfy recliner");
	Screen Screen2(2,200,"IMAX,Sliding seats");
	Screen Screen3(3,180,"Couple Seats,Ideal viewing position");
	Screen Screen4(4,150,"Seat Service,Standard screen");
	Screen Screen5(5,100,"Comfy recliner, service call button, Fresh balanket");
	int choice2;
	bool leaveInnerloop=false;
	while(1){
		system("cls");
			    cout<<"\n\n\t\t PRESS 1 TO GET DETAILS OF SCREEN1";
			    cout<<"\n\n\t\t PRESS 2 TO GET DETAILS OF SCREEN2";
			    cout<<"\n\n\t\t PRESS 3 TO GET DETAILS OF SCREEN3 ";
			    cout<<"\n\n\t\t PRESS 4 TO GET DETAILS OF SCREEN4";
			    cout<<"\n\n\t\t PRESS 5 TO GET DETAILS OF SCREEN5";
			    cout<<"\n\n\t\t PRESS 6 TO go back to main menu";
			    cout<<"\n\n\t\t TO EXIT PROGRAM PRESS 9 \n\t\t ::";
			    cin>>choice2;
			    switch(choice2){
			    	case 1:
			    		Screen1.displayScreenInfo();
			    		break;
			    	case 2:
			    		Screen2.displayScreenInfo();
			    		break;
			    	case 3:
			    		Screen3.displayScreenInfo();
			    		break;
			    	case 4:
			    		Screen4.displayScreenInfo();
			    		break;
			    	case 5:
			    		Screen5.displayScreenInfo();
			    		break;
			    	case 6:
			    		leaveInnerloop=true;
			        	break;
			        case 9:
			        	break;
			        default:
			        	break;
				}
				
	}

	
 	
}
