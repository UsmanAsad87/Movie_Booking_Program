#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
string csv_name[5]={"movie_test1.csv","movie_test2.csv","movie_test3.csv","movie_test4.csv","movie_test5.csv"};

//str_tim is saving the no.of show of a particular movie
 // can be local
/*ITS THE string array to store the timings of a particular movie
1st argument is for movie number and and argument is for no.timings that
particular runs*/
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
        	int opt;
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
		    cin>>opt;
		    (*this).setChoice(opt);
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



int main()
{
	
    Movie_Manager manager;
    manager.login();

}
