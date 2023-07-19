# Movie Booking Program
## Scenario: Design and develop a booking system for an independent cinema.



https://github.com/UsmanAsad87/Movie_Booking_Program/assets/92229738/30ece99f-d5a4-461c-982d-a131e51ecfe4


## Running the code:
To run the code navigate to "Booking App Code" folder and run "MovieBooking.cpp" file in VScode or Dev-cpp
### Admin Password = 12345




## Basic cinema information: 
The cinema is open from 10:00 to 23:30. The earliest a film can be shown is 10:15. There is a 25-minute gap between film showings so the screen can be cleaned. The cinema contains 5 screens with different seating capacities. The largest screen can hold 250 people the smallest 100 people. Tickets are available in four formats - adults: £9.50, children: £5.50, senior citizens: £6.50 and students: £7.00.

Below outlines the functionality that needs to be carried out by the system:
Capture booking information relating to a ticket sale:<br/>
o Data to be captured should include: number of tickets required, movie choice, date, time, total cost of transaction, payment type (cash or card). For card payments details should be taken but not stored.<br/>
o A booking cannot take place if the following conditions are met:<br/>
• The number of tickets sold exceeds the maximum seating capacity of the screen<br/><br/>
### Screen information:<br/>
o Data to be captured should include: screen ID, movie currently being shown, maximum seating capacity, screen facilities (Standard, IMAX, Couple seats, Seat service etc.<br/>
### Movie information:<br/>
o Data to be captured should include: title, description, genre, running time, main star, release date<br/>
### Weekly schedule information:<br/>
o Once a week new films to be screened have their details entered into the system including which screen is to be allocated to the film and the times of the show in the day.<br/>
<br/>
Each screen shows a film for a weak (Thursday to Wednesday) and the number of showings is determined by the running time of the film. Remember there is a 25 minute gap between films. The manager needs to record the start time and end time of each show factoring in the required 25-minute break between shows.
<br/>
The number of shows for each screen does not need to fit exactly in the amount of time available in the day so long as a show does not exceed the closing time of the cinema. You may decide what is sensible in this regard.
<br/>
An appropriate file system must be created in order for the program to store and retrieve data. This will allow the program to record its states between uses.
<br/>
Elements of the design/program you do not need to consider include recording or processing details related to staff, food & drink, multiple cinemas, security (log-ins/passwords).
<br/><br/>
In addition, there should be at least 4 weeks worth of films stored in the system. Movie information is available from the supplied imdb_top_1000.csv file. This is optional and you can choose to use your own movies if you wish so.
<br/>
Any information not supplied in the scenario you think you may require, may be "made-up" so long as it is sensible and realistic. Any doubts ask your tutor.
<br/>

## Task 1: Analysis and Design
• The first stage is to outline the program specification by describing the purpose of what the software is required to do.<br/>
• The second stage is to analyse the problem by identifying the inputs, processes and outputs described in the program specification.<br/>
• Thirdly discuss how you might approach the design using different paradigms - you should focus on discussing either a procedural approach or an object orientated approach.<br/>
• Fourthly design algorithms for the program using appropriate notations such as pseudo code, flow charts JSP diagrams and class diagrams.<br/>
• Lastly describe the design and purpose of the technical elements of the software solution that will be created such as variables, data structures, functions, classes, methods etc. Again you do not need to go into the technical details of how these elements will work but outline their purpose and function.
