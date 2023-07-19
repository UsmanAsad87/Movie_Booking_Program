#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

class Movie{
public:
	string Name;
	string description;
	string genre;
	string runningtime;
	string mainStar;
	string release;
	string imdb;
	
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
		    
		    return;
		}
		getline(file,Name,'\n');  
		i++;
		}
	file.close();
}


string Movie::displayMovieNames(string MoviesNames[100])
{
	for(int i=0;!MoviesNames[i].empty();i++)
 	{
 		cout<<"MOVIE :\t"<<i+1<<"  "<<MoviesNames[i]<<endl;
	}
	int MovieNumber=0;
	cout<<"\nEnter then name of the movie you want to get information: ";
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
		i++;//to access the different movie names
	}
	file.close();
}
void Movie::EnterMovieDetails()
{
	fstream fout;
  
    fout.open("imdbTop.csv", ios::out | ios::app);
  
    cout << "Enter the details of the Movie:"<< endl;

  
	cout<< "Enter the name of the Movie:";
	getchar();
	getline(cin,Name);
	cout<< "Enter the description of the Movie:";
	getchar();
	getline(cin,description);
	cout<< "Enter the genre of the Movie:";
	getline(cin,genre);
	cout<< "Enter the running time of the Movie:";
	cin>>runningtime;
	cout<< "Enter the mainStar of the Movie:";
	getchar();
	getline(cin,mainStar);
	cout<< "Enter the release of the Movie:";
	cin>>release;
	cout<< "Enter the imdb of the Movie:";
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


int main()
{
	string MoviesNames[100],selectedMovie;
	Movie obj;
	
	obj.MovieName(MoviesNames);
	selectedMovie=obj.displayMovieNames(MoviesNames);
	obj.movieDetails(selectedMovie);
	obj.EnterMovieDetails();
 	
}
