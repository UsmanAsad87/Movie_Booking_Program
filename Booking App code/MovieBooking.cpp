#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
//int m=0;
string name[100];
int ar[100][100][100][12][18],tkt_row[12],tkt_col[18];
string csv_name[5]={"movie_test1.csv","movie_test2.csv","movie_test3.csv","movie_test4.csv","movie_test5.csv"};


//////////////////////////////////////////////////////////
/////////////////////////MovieBookingClass////////////////
//////////////////////////////////////////////////////////
class movie_booking
{
private:
	int adults,children,senior_citizen,students,payment;
    double cost;
    string hall_name;
    int tkt_pr;
    int tkt;
    int arg;
    int arg2;

public:
	movie_booking(){
		adults=0;
		children=0;
		senior_citizen=0;
		students=0;
		payment=0;
		cost=0.0;
	}
	int screen;
    void first();
    int show_seat_frm_file();
    void seatdisp(int z,int wt);
    void book(int z,int wt ,int a);
    void seatin(int z,int wt);
    void ticket_print(int sti);
    void hal_name()
    {
        switch((*this).screen)
        {
            case 1:
            (*this).hall_name="SCREEN1";
            break;
             case 2:
            (*this).hall_name="SCREEN2";
            break;
             case 3:
            (*this).hall_name="SCREEN3";
            break;
             case 4:
            (*this).hall_name="SCREEN4";
            case 5:
            (*this).hall_name="SCREEN5";
            break;
        }

    }

};


void movie_booking::first()
{
    int i;
    int sti;
    char in='c',cus;//cus is customer and ind is manager input
    system("cls");
    cout<<"\n\n\t\tDEAR CUSTOMER TO BOOK SEATS PRESS 'y' or 'Y' \n";
    cout<<"\t\t::";
    cin>>cus;
    //HERE I HAVE TO ADD THE CUSTOMER LOGIN FUNCTION
     if((cus=='y')||(cus=='Y'))//the customer part starts here
     {  
 system("cls");
 cout<<"\n\n\t\tTHE SEATS AVAILABLE ARE:\n";
                 while((in=='c')||(in=='C'))
    {
        (*this).cost=0;
        (*this).adults=0;
		(*this).children=0;
		(*this).senior_citizen=0;
		(*this).students=0;
		(*this).payment=0;
		
        int total_mov =(*this).show_seat_frm_file();
            cout<<"\n\n\t\tENTER THE MOVIE NUMBER TO BOOK TICKET\n";
            cout<<"\t\t:";
            cin>>arg;
            while(arg>total_mov){
            	cout<<"\n\n\t\tENTER THE Correct MOVIE NUMBER TO BOOK TICKET\n";
            	cout<<"\t\t:";
            	cin>>arg;
			}
                
            ifstream fin;//this part is for retrieving moive name from file
	fin.open(csv_name[(*this).screen-1].c_str());
   for(i=0;i<arg-1;i++)
   {
    getline(fin,name[i],'\n');
   }
   getline(fin,name[i],',');
    fin.close();
             cout<<"\n\n\t\tCHOOSE THE NUMBER CORRENSPONDING TO TIMING TO BOOK TICKET FOR MOVIE :-"<<endl;

            cout<<"\t\t"<<name[i];
            cout<<"\t\t";
            cin>>sti;
            
            (*this).seatdisp(arg,sti);
            (*this).seatin(arg,sti);
            system("cls");
            (*this).seatdisp(arg,sti);
            system("cls");
            (*this).ticket_print(sti);
    cout<<"\n\n\t\tPRESS 'C' or 'c' IF U WANT TO BOOK SEAT AGAIN?\n";
    cin>>in;



    }
         }

}

int  movie_booking::show_seat_frm_file()
{int i=0,j,m=0;
string tim[100][100];
    system("cls");//after the input is being over the screen is cleared and data is displayed
cout<<"\n\n\t\tTHE MOVIES RUNNING IN HALL ARE:\n\n\n";
ifstream fin;
fin.open(csv_name[(*this).screen-1].c_str());
while(!fin.eof())
{
     cout<<"\n\t\t";

    getline(fin,name[i],',');
    cout<<"MOVIE :\t"<<i+1<<"\t"<<name[i]<<endl<<endl;
    m++;
    cout<<"\t\t";
    cout<<"THE TIMINGS OF THE MOVIE : "<<name[i]<<" :-  "<<endl;
    int j=0;

    
    getline(fin,tim[i][j],'\n');
	//cout<<"\t\t";
	//cout<<tim[i][j]<<endl<<endl;
	std::string delimiter_char = ",";
    size_t pos = 0;
    std::string token;
    while ((pos = tim[i][j].find(delimiter_char)) != std::string::npos) 
		{
        token = tim[i][j].substr(0, pos);
        cout <<"\t\t "<< token << std::endl;
        tim[i][j].erase(0, pos + delimiter_char.length());
		}
	

i++;//to access the different movie names
}
fin.close();
return m;
}


void movie_booking::seatdisp(int z,int wt)
//1st argument to display the seats of that particular movie
//2nd arg is for the particular movie time
{
    arg=z;
    int sti=wt;
    int i,j;
    char ch='A',st;
    system("cls");
    cout<<"\n\nCOST OF Adult :9.50 Pounds\n";
    cout<<"COST OF Children :5.50 pounds\n";
    cout<<"COST OF  Senior Citizen :6.50 pounds\n";
    cout<<"COST OF  Students : 7.00 pounds\n";
    
ifstream fin;//this part is for retrieving moive name from file
fin.open(csv_name[(*this).screen-1].c_str());
   cout<<"\n\n\t\tBOOKED SEATS ARE MARKED WITH [x]\n\n";
   for(i=0;i<arg-1;i++)
   {
    getline(fin,name[i],'\n');
   }
   getline(fin,name[i],',');
   cout<<"\n\n\t\tTHIS IS THE SEAT MATRIX FOR MOVIE: "<<name[i]<<"\n\n";
    fin.close();
    
    
    int width=10;
    if((*this).screen==1)
        width=25; //largest screen
    else if((*this).screen==2)
        width=22; //2nd largest screen
    else if((*this).screen==3)
        width=18; //medium screen
    else if((*this).screen==4)
        width=15; //small screen
    else if((*this).screen==5)
        width=10; //smallest screen
    
    for(i=0;i<9;i++)
    {
        ch='A';
        ch=ch+i;
        cout<<"\t";
     for(j=0;j<width;j++)
        {
            if(ar[(*this).screen][arg][sti][i][j]==1)
            cout<<"["<<" X"<<"]";
            else
            {
                cout<<"["<<ch<<j+1<<"]";
            }

            cout<<" ";//1 white spaces given
                      //the seat would be displayed in format[A1]

            if(j==4||j==12 || j==20) 
                cout<<"\t";

        }
        cout<<"\n\n";
 if(i==12)
    {
        cout<<"\n\n\t\t SCREEN THIS WAY\n";
        cout<<"\t______________________________________________________________________________________________________________";
    }

    }

}
   



void movie_booking::book(int z,int wt ,int a)//first argument is for the movie number and 3rd argument for manager mode
//2nd arg is for show time
{int i,j,num,al,n,col,stor,arg;
arg=z;
int sti=wt;
    arg2=a;
    if(arg2==100)
    {
      cout<<"\n\n\t\tADMIN ENTER THE SEATS WHICH WONT BE AVAILABLE FOR BOOKING\n";
    }

else
{
 cout<<"\n\n\t\tCUSTOMER BOOKING\n";
}

        (*this).seatdisp(arg,sti);
    char ch='A',chr;
    cout<<"\n\n\t\tENTER THE SEAT NUMBER\t";

        cin>>chr>>col;
        stor=chr-65;
        col=col-1;

        if(ar[(*this).screen][arg][sti][stor][col]==0)
        {
            ar[(*this).screen][arg][sti][stor][col]=1;

            tkt_col[tkt]=col;
            tkt_row[tkt]=stor;


        }
        else
        {

            while(ar[(*this).screen][arg][sti][stor][col]!=0)
            {
                if(arg2==100)
                {
                  cout<<"\n\n\t\tADMIN YOU HAVE ALREADY MARKED THIS SEAT AS BOOKED ENTER A NEW SEAT WHICH IS BOOKED\n";
               cout<<"\t\t ";
                }

           else
           {
            cout<<"\n\n\t\tTHE SEAT YOU SELECTED IS ALREADY OCCUPIED ENTER A NEW SEAT\n";
            cout<<"\t\tt ";
           }
                cin>>chr>>col;
                stor=chr-65;
                col=col-1;
            }
            ar[(*this).screen][arg][sti][stor][col]=1;
           tkt_col[tkt]=col;
            tkt_row[tkt]=stor;
        }

}

void movie_booking::seatin(int z,int wt)
{

    int n,i;
    arg=z;
    int sti=wt;

    ifstream fin;
	fin.open(csv_name[(*this).screen-1].c_str());

    for(i=0;i<arg-1;i++)
    {
     getline(fin,name[i],'\n');
    }
    getline(fin,name[i],',');

    cout<<"\t\t MOVIE NAME="<<name[i]<<endl;
    fin.close();
    cout<<"\t\t ";
    cout<<"\n\n\t\tENTER THE NUMBER OF SEATS TO BE BOOKED :";
    cin>>n;
    tkt_pr=n;
    for(tkt=0;tkt<n;tkt++)//loop for booking the desired no. of tickets as input by user
		{
		     (*this).book(arg,sti,20);
		     cout<<"LOOP IS RUNNING\n";
		       system("cls");
		  (*this).seatdisp(arg,sti);
		
		}
	
	cout<<"\n\t\tEnter the number of Adults :";
	cin>>(*this).adults;
	cout<<"\n\t\tEnter the number of Children :";
	cin>>(*this).children;
	cout<<"\n\t\tEnter the number of Senior citizens :";
	cin>>(*this).senior_citizen;
	cout<<"\n\t\ttEnter the number of Students :";
	cin>>(*this).students;
    
// CLEAR();
 system("cls");

}

void movie_booking::ticket_print(int sti)
{    int i,a=0,b=0,d=0;
    char c;
    string time;//time to store the movie timing

    (*this).cost=(*this).adults*9.50 + (*this).children*5.50+(*this).senior_citizen*6.50+(*this).students*7.0;


    system("cls");
    ifstream fin;//this part is for retrieving moive name from file
    fin.open(csv_name[(*this).screen-1].c_str());

   for(i=0;i<arg-1;i++)
   {
    getline(fin,name[i],'\n');
   }
   getline(fin,name[i],',');
   
         for(int j=0;j<sti;j++)
   {
    getline(fin,time,',');
   }
   fin.close();
    (*this).hal_name();
    cout<<"\n\n\n\n\t\t\t________________________________________________________________________\n";
		cout<<"\t\t\t|                                                                       |\n";
		cout<<"\t\t\t|   Dear Customer,                                                      |\n";
		cout<<"\t\t\t|                      Congratulation!! Your tickets has been booked.   |\n";
		cout<<"\t\t\t|                                                                       |\n";
		cout<<"\t\t\t|                  THE DETAILS:                                         |\n";
		cout<<"\t\t\t|                            MOVIE HALL: "<<(*this).hall_name<<"                 \n";
		cout<<"\t\t\t|                            MOVIE NAME: "<<name[i]<<"                                 \n";
		cout<<"\t\t\t|                            SHOW STARTS:"<<time<<"                        \n";
		cout<<"\t\t\t|                            NUMBER OF TICKETS BOOKED: "<<tkt_pr<<"                |\n";
		cout<<"\t\t\t|                            COST :                                     |"<<endl;
        if(adults!=0)
        cout<<"\t\t\t|                                  "<<(*this).adults<<" * 9.50 pounds                      |"<<endl;
    	if(children!=0)
        cout<<"\t\t\t|                                  "<<(*this).children<<" * 5.50 pounds                      |"<<endl;
        if(senior_citizen!=0)
        cout<<"\t\t\t|                                  "<<(*this).senior_citizen<<" * 6.50 pounds                      |"<<endl;
        if(students!=0)
        cout<<"\t\t\t|                                  "<<(*this).students<<" * 7.50 pounds                      |"<<endl;
		cout<<"\t\t\t|                            THE TOTAL TICKET COST =  "<<(*this).cost<<" pounds       |"<<endl;
		cout<<"\t\t\t|                 THE SEAT NUMBERS ARE: ";for(i=0;i<tkt_pr;i++)
		                                            {   c=tkt_row[i]+65;
		                                                cout<<c<<tkt_col[i]+1;//PLS CHECK WHY I HV WRITTEN HERE +
		                                                if(i<tkt-1)
		                                                {
		                                                    cout<<",";
		                                                }
		                                            }
		cout<<"                        \n";
		cout<<"\t\t\t|_______________________________________________________________________|\n";
		cout<<"\n\n\t\t Payment is by Card or Cash(0 or 1) ? ";
		cin>>(*this).payment;
		char temp;
		cout<<"\n\n\t\tPRESS ANY KEY TO CONTINUE\n";
		cin>>temp;

}

//////////////////////////////////////////////////////////
/////////////////////////MovieBookingClass////////////////
//////////////////////////////////////////////////////////


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&& Movie Class &&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
class Movie{
private:
	string Name;
	string description;
	string genre;
	string runningtime;
	string mainStar;
	string release;
	string imdb;
public:
	void MovieName(string MoviesNames[100]);
	string displayMovieNames(string MoviesNames[100]);
	void movieDetails(string Mname);
	void EnterMovieDetails();
};

void Movie::movieDetails(string Mname)
{
	int i=0;
	ifstream file;
	file.open("imdbTop.csv");
	while(!file.eof())
		{

	    getline(file,Name,',');
	    
	    if(Name == Mname)
	    {
	    	cout<<"\n\n";
	    	cout<<"\t\t===========================================================\n";
	    	cout<<"\t\tMovie Name :\t"<<"\t"<<Name<<endl;
	    	getline(file,description,',');
		    cout<<"\t\tDescription :\t"<<"\t"<<description<<endl;
		    getline(file,genre,',');
		    cout<<"\t\tGenre :\t"<<"\t"<<genre<<endl;
		    getline(file,runningtime,',');
		    cout<<"\t\tRunningtime :\t"<<"\t"<<runningtime<<endl;
		    getline(file,mainStar,',');
		    cout<<"\t\tMainStar :\t"<<"\t"<<mainStar<<endl;
		    getline(file,release,',');
		    cout<<"\t\tRelease :\t"<<"\t"<<release<<endl;
		    getline(file,imdb,'\n');
		    cout<<"\t\tIMDB :\t"<<"\t"<<imdb<<endl;
		    cout<<"\t\t===========================================================\n\n\n";;
		    char temp;
		    cout<<"\n\n\t\tPRESS ANY KEY TO CONTINUE\n";
			cin>>temp;
		    
		    return;
		}
		getline(file,Name,'\n');  
		i++;
		}
	file.close();
}


string Movie::displayMovieNames(string MoviesNames[100])
{
	cout<<endl<<endl<<endl;
	for(int i=0;!MoviesNames[i].empty();i++)
 	{
 		cout<<"\t\tMOVIE :\t"<<i+1<<"  "<<MoviesNames[i]<<endl;
	}
	int MovieNumber=0;
	cout<<"\n\n\t\tEnter then number of the movie you want to get information: ";
	cin>>MovieNumber;
	return MoviesNames[MovieNumber-1];
}

void Movie::MovieName(string MoviesNames[100])
{
	int i=0;
	ifstream file;
	file.open("imdbTop.csv");
	while(!file.eof())
	{
	
	    getline(file,Name,',');
	    MoviesNames[i]=Name;
		getline(file,Name,'\n');
		i++;
	}
	file.close();
}
void Movie::EnterMovieDetails()
{
	fstream fout;
  
    fout.open("imdbTop.csv", ios::out | ios::app);
  
    cout << "\n\n\t\tEnter the details of the Movie:"<< endl;

  
	cout<< "\t\tEnter the name of the Movie:";
	getchar();
	getline(cin,Name);
	cout<< "\t\tEnter the description of the Movie:";
	getchar();
	getline(cin,description);
	cout<< "\t\tEnter the genre of the Movie:";
	getline(cin,genre);
	cout<< "\t\tEnter the running time of the Movie:";
	cin>>runningtime;
	cout<< "\t\tEnter the mainStar of the Movie:";
	getchar();
	getline(cin,mainStar);
	cout<< "\t\tEnter the release of the Movie:";
	cin>>release;
	cout<< "\t\tEnter the imdb of the Movie:";
	cin>>imdb;
 
    fout<< Name << ", "
        << description << ", "
        << genre << ", "
        << runningtime << ","
        << mainStar << ", "
        << release << ", "
        << imdb
        << "\n";
        
        
    fout.close();
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&& Movie Class &&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&



/////////////////////////////////////////////////////////
//////////////////// Screen Class ///////////////////////
/////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////
//////////////////// Screen Class ///////////////////////
/////////////////////////////////////////////////////////

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&& Movie Manager Class &&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

class Movie_Manager
{
	int choice;
	string name[100];
	string pass;
	int str_tim[100];
	string tim[100][100];
public:
	int getChoice(){
		return choice;
	}
	void setChoice(int ch){
		choice=ch;
	}
    int login();
    void showMoviesFromFile();
    void AddMovie();
    void pass_proctect();
    void deleteMovie();
};


int Movie_Manager::login()
{

    int pas_count=0;
    while(pas_count<3)
    {
        (*this).pass_proctect();
        if(pass=="12345")
        {
        	int opt,option;
		    while(1)
		    {
		    system("cls");
		    cout<<"\n\n\t\t PRESS 1 TO MANAGE SCREEN_1";
		    cout<<"\n\n\t\t PRESS 2 TO MANAGE SCREEN_2";
		    cout<<"\n\n\t\t PRESS 3 TO MANAGE SCREEN_3 ";
		    cout<<"\n\n\t\t PRESS 4 TO MANAGE SCREEN_4";
		    cout<<"\n\n\t\t PRESS 5 TO MANAGE SCREEN_5";
		    cout<<"\n\n\t\t TO EXIT PROGRAM PRESS 9 ";
		    cout<<"\n\n\t\t ::";
		    cin>>option;
		    (*this).setChoice(option);
		    if((*this).getChoice() >=1 && (*this).getChoice() <=5 )
		    {
		    	system("cls");
		    	cout<<"\n\n\t\t PRESS 1 TO DISPLAY MOVIES";
		    	cout<<"\n\n\t\t PRESS 2 TO ADD MOVIES";
		    	cout<<"\n\n\t\t PRESS 3 TO DELETE MOVIE";
		    	cout<<"\n\n\t\t TO RETURN PRESS 9 ";
		    	cout<<"\n\n\t\t ::";
		    	cin>>opt;
		    	switch(opt){
		    		case 1:
		    			(*this).showMoviesFromFile();
		    			char a;
		    			cout<<"\n\n\t\tEnter Any key to countinue:";
		    			cin>>a;
		    			break;
		    		case 2:
		    			(*this).AddMovie();
		    			//cout<<"Enter Any key to countinue:";
		    			//getch();
		    			break;
		    		case 3:
		    			(*this).deleteMovie();
		    			//cout<<"Enter Any key to countinue:";
		    			//getch();
		    			break;
		    		default:
		    			break;
		    			
				}
			}
			else if(option == 9){
				return 9;
			}
			else{
				return 1;
			}
		
        	
            pas_count=3;
        }
    	}

	    else
	    {
	    cout<<"PASSWORD ENTERED IS WRONG!!"<<" ATTEMPTS REMAINING = "<<2-pas_count<<" \n";//pas_count is to count no. of attempts left
	        pas_count++;
	    }

	}
    system("cls");
    
     
}

void Movie_Manager::showMoviesFromFile()
{
	int i=0,j;
    system("cls");
	cout<<"\n\n\t\tTHE MOVIES RUNNING IN HALL ARE:\n\n\n";
	ifstream fin;
	fin.open(csv_name[choice-1].c_str());
	while(!fin.eof())
	{
	    cout<<"\n\t\t";
	
	    getline(fin,name[i],',');
	    if(name[i].empty())
	    		break;              
	    cout<<"MOVIE :\t"<<i+1<<"\t"<<name[i]<<endl;
	    cout<<"\t\t";
	    cout<<"THE TIMINGS OF THE MOVIE : "<<name[i]<<" :-  "<<endl;
	    int j=0;
	    
	
	   	getline(fin,tim[i][j],'\n');
	    //cout<<"\t\t";
	    //cout<<tim[i][j]<<endl<<endl;
	    std::string delimiter_char = ",";
    	size_t pos = 0;
    	std::string token;
    	while ((pos = tim[i][j].find(delimiter_char)) != std::string::npos) 
			{
	        token = tim[i][j].substr(0, pos);
	        cout <<"\t\t "<< token << std::endl;
	        tim[i][j].erase(0, pos + delimiter_char.length());
    		}
	
		i++;//to access the different movie names
	}
	fin.close();
	//getchar();

}

void Movie_Manager::deleteMovie()//this function is for entering the number of movie running in hall
{
	int number,i=0;
	string temp[50];
	(*this).showMoviesFromFile();
	cout<<"\n\n\t\t Enter the number of movie you want to delete: \n\t\t ::";
	cin>>number;
	ifstream fin;
	fin.open(csv_name[choice-1].c_str());
	while(!fin.eof())
	{
	    getline(fin,temp[i],'\n');         
		i++;
	}
	fin.close();
	std::ofstream ofs(csv_name[choice-1].c_str(), std::ofstream::trunc);
	ofstream fout;
    fout.open(csv_name[choice-1].c_str(),ios::out);
	for(int j=0;j<i-1;j++)
	{
		if(j!=(number-1) && !temp[j].empty()) //overewite a file and dont write the deleted movie record
			fout<<temp[j]<<"\n";
	}
	fout.close();
	
	
}
void Movie_Manager::AddMovie()//this function is for entering the number of movie running in hall
{
    int i,j;
    int m,nt;
    //p=(int*)(malloc(sizeof(int)));
    cout<<"\n\n\t\t ENTER THE NUMBER MOVIES RUNNING IN THE HALL\n";
    cout<<"\t\t ::";
    cin>>m;
    //(*p)=m;
     ofstream fout;
    fout.open(csv_name[choice-1].c_str(),ios::app);
	for(i=0;i<m;i++)//m is the total no of movies running in that hall
	{   
	fflush(stdin);
    cout<<"\n\n\t\t ENTER THE NAME OF MOVIE "<<i+1<<endl;
    cout<<"\t\t ::";
    getline(cin,name[i]);
    fflush(stdin);
    fout<<name[i]<<",";//movie name writing in file
    cout<<"\n\n\t\t ENTER THE NUMBER OF SHOWS OF MOVIE: "<<name[i]<<" IN A DAY : \n\t\t ::";
    cin>>nt;
    //str_tim[i]=nt;
    //here a function is to be added to save the show timings
    cout<<"\n\n\t\t ENTER THE SHOW TIMINGS OF THE MOVIE(dd_Mon_HH:MM) : "<<name[i]<<endl;
    for(j=0;j<nt;j++)
    {   fflush(stdin);
         cout<<"\t\t : ";
        getline(cin,tim[i][j]);// this is the function for collecting the show timings
        fout<<tim[i][j]<<",";

    }
    fout<<endl;

	}
	
	fout.close();
	cout<<"\n\t\t Movie Added, Enter any key to countinue:";
	getchar();
}







void Movie_Manager::pass_proctect()//to protect the password
{

        int ps=0,star=0;// to count the characters in password

        //star is to print the password in * format
                    //pas[-1]=0;//intialised just like that "I GUESS ITS NIT REQUIRED"
         cout<<"\n\n\t\t ENTER THE MANAGER PASSWORD\n";
         cout<<"\t\t ::";

                cin>>pass;
               ps=pass.length();
                system("cls");
                while(star<ps)
                {   if(star==0)
                {
                    cout<<"\n\n\t\t ENTER THE MANAGER PASSWORD\n\n";

                    cout<<"\t\t ::";

                }

                    cout<<" * ";
                    star++;
                }

}





//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&& Movie Manager Class &&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

int main()
{
    movie_booking obj;
    string MoviesNames[100],selectedMovie;
	Movie object;
	Movie_Manager manager;
	Screen Screen1(1,250,"Standard,Ideal viewing position,Comfy recliner");
	Screen Screen2(2,200,"IMAX,Sliding seats");
	Screen Screen3(3,180,"Couple Seats,Ideal viewing position");
	Screen Screen4(4,150,"Seat Service,Standard screen");
	Screen Screen5(5,100,"Comfy recliner, service call button, Fresh balanket");
				
    int CHOICE,choice1,choice2;
    while(1)
    {
    system("cls");
    cout<<"\n\n\t\t PRESS 1 TO VIEW THE DETAIL OF THE MOVIE";
    cout<<"\n\n\t\t PRESS 2 TO GET DETAILS OF THE SCREENS";
    cout<<"\n\n\t\t PRESS 3 TO BOOK TICKET ";
    cout<<"\n\n\t\t PRESS 4 TO ENTER IN MANAGER MENU";
    cout<<"\n\n\t\t PRESS 9 TO EXIT \n\t\t ::";
    cin>>CHOICE;
    bool leaveInnerloop=false;
    switch(CHOICE){
    	case 1:
    		 while(1)
			    {
    		
    			system("cls");
				cout<<"\n\n\t\t PRESS 1 TO VIEW THE DETAIL OF THE MOVIE";
    			cout<<"\n\n\t\t PRESS 2 TO ENTER DETAILS OF MOVIE ";
    			cout<<"\n\n\t\t PRESS 3 TO go back to main menu";
			    cout<<"\n\n\t\t TO EXIT PROGRAM PRESS 9 \n\t\t ::";
    			cin>>choice1;
    			if(choice1==1)
    			{
    				object.MovieName(MoviesNames);
					selectedMovie=object.displayMovieNames(MoviesNames);
					object.movieDetails(selectedMovie);	
				}
				else if(choice1==2)
				{
					object.EnterMovieDetails();
				}
				else if(choice1==3)
				{
					break;
				}
				else
					goto bye;
			}
				
				break;
		case 2:
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
			        	goto bye;
			        default:
			        	cout<<"enter a valid number\n";
			        	goto bye;
			        	break;
					}
				if(leaveInnerloop)
				    {
				    		break;
					}
				
				}
			break;
		case 3:
			    while(1)
			    {
			    system("cls");
			    cout<<"\n\n\t\t PRESS 1 TO BOOK TICKET IN SCREEN1";
			    cout<<"\n\n\t\t PRESS 2 TO BOOK TICKET IN SCREEN2";
			    cout<<"\n\n\t\t PRESS 3 TO BOOK TICKET IN SCREEN3 ";
			    cout<<"\n\n\t\t PRESS 4 TO BOOK TICKET IN SCREEN4";
			     cout<<"\n\n\t\t PRESS 5 TO BOOK TICKET IN SCREEN5";
			     cout<<"\n\n\t\t PRESS 6 TO go back to main menu";
			    cout<<"\n\n\t\t TO EXIT PROGRAM PRESS 9 ";
			    cout<<"\n\n\t\t :: ";
			    cin>>obj.screen;
			    switch(obj.screen)
			    {
			        case 1:
			            cout<<"\t\t";
			            cout<<"SCREEN1 IS SELECTED\n";
			        obj.first();
			        break;
			        case 2:
			        cout<<"\t\t";
			            cout<<"SCREEN2 IS SELECTED\n";
			        obj.first();
			        break;
			        case 3:
			        cout<<"\t\t";
			             cout<<"SCREEN3 IS SELECTED\n";
			        obj.first();
			        break;
			        case 4:
			        cout<<"\t\t";
			            cout<<"SCREEN4 IS SELECTED\n";
			        obj.first();
			        break;
			        case 5:
			        cout<<"\t\t";
			            cout<<"SCREEN5 IS SELECTED\n";
			        obj.first();
			        break;
			        case 6:
			        leaveInnerloop=true;
			        break;
			        case 9:
			                goto bye;
			                break;
			        default:
			        cout<<"enter a valid number\n";
			        goto bye;
			                break;
			    }
			    if(leaveInnerloop)
				    {
				    		break;
					}
				}
			case 4:
				int ret;
    			ret=manager.login();
    			if(ret==1)
    			{
    				break;
				}
				else{
					goto bye;
				}

				
			case 9:
			    goto bye;
			    break;
			default:
			    cout<<"enter a valid number\n";
			    goto bye;
		}
	}
    


bye:
     system("cls");
     cout<<"\n\n\n\n\t\t THANK YOU FOR USING OUR APPLICATION!!";
 return 0;

}
