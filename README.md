# Google-Calander_with_CPP
Google Calander using C++ , using class and objects , concept of constructor , destructor , OOP's 
There are various Functions like: 

● The client wishes to obtain the Day, Month and Year of a given date.
● The client wishes to know the next weekday of a given date in the year 2023.
● The client wishes to know the next holiday of any given date in the year 2023.

● string Calendar::getDay(Date d) { return “Monday/Tuesday/….”}
● string Calendar::getMonth(Date d);
● string Calendar::getYear(Date d);
● Date Calendar::getNextWeekDay(Date d) {}
● Date Calendar::getNextHoliday(Date d) {}
● A mamber class in which The client wishes to be able to provide any valid date and get the corresponding day.
● A mamber class in which The client wishes to be able to set a particular date as a holiday. The client expects all
Saturdays and Sundays to be set as holidays by default.
● A mamber class in which The client wishes to perform addition and subtraction operators to be enabled for the
dates. Specifically, the client wishes to be able to add a date with an integer to obtain a
valid date that comes the specified integer number of days post the supplied date.

● A mamber class in which The client wishes to know the number of holidays in a given month of a specified year.

● A mamber class in which  The client wishes to know if a date preceded a different date. Example (23/08/2023 <
22/08/2023) is true but (23/08/2023 < 24/08/2023) is false.

● A mamber class in which The client wishes to add a note to a given date. For instance the client might want to
add a note “Meeting with Alan Turing” to the date 23/08/2023.

● A mamber class in which The client wishes to be able to remove a note that was added to a date.

● A mamber class in which  The client wishes to display all notes for the next n days of a given date for a given n.


● A mamber class in which The client wishes to be able to compute the number of days between any two valid
dates.

● A mamber class in which The client wishes to print the calendar for any given month of a specified year.

● A mamber class in which The client wishes to check if two given users, who have their own meetings noted in
their respective calendars, have any set of common days in a given month of an year
where they are free to schedule a meeting and if so list the dates (of course, they can’t
have meetings on holidays).
