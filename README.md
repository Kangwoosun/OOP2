# OOP2
OOP2_2017 Code + Lecture + FinalProject_partB

OOP2 - Final_Project - projectB

Student names : 12171598 김용준, 12171575 강우선,12171615 박민우

We makes 5 header files("Student.h", "Instructor.h", "Grade.h", "Question.h", "Subject.h") and 1 cpp file(main.cpp) to activate the Program. We use 5 binary files("InstructorList.bin", ) to implement the functions.

<main.cpp>
In the main function, we described login page, that when entered ID and Passwd, decide whether Instructor or Student. and print the mainmenu for Instructor or Student. and each parts of the mainmenu are described in "Instructor.h" or "Student.h". In the "main.cpp" file, we wrote these functions 

- bool LoginAdmin() 
fuction deciding whether users are Instructor or not.
Print the login interface and move the cursor to right next the "username : " 
When the is ID is received, open the "InstructorList.bin" and read the contents of the file. 
Compare the entered ID with object's instrucname of the file. 
If ID is matched with instrucname of file, then receive the Passwd.
Compare the entered Passwd with object's passwd of that Instructor in the file. 
If Passwd is matched with passwd of that Instructor, return 1.

- bool LoginStudent() 
fuction deciding whether users are Student or not
Print the login interface and move the cursor to right next the " username : " 
When the is ID is received, open the "StudentList.bin" and read the contents of the file. 
Compare the entered ID with object's studname of the file. 
If ID is matched with studname of file, then receive the Passwd.
Compare the entered Passwd with object's passwd of that Student in the file. 
If Passwd is matched with passwd of that Student, return 1.

- void gotoxy(int x, int y) 
function that locates the consolecursor to the position( x-1, y-1 )
  
<Instructor.h>
Instructor header has basic functions of the class "Instructor", for example, constructor, set & get functions. Also, There are funtions StudentInformation(), InstructorInformation(), QuestionInformation(), SubjectInformation(), GradeInformation(), UpdatePasswd(), BuildFile() that each choices of the Instructor main menu. 

- char MainMenu()
print the mainmenu for the instuctor and receive the character.

- void StudentInformation() 
print submenu of the Student-mainmenu using function submenuforstudent() and call each functions when receive the characters(s, u, a, d or x). 

- void InstructorInformation() 
print submenu of the Instuctor-mainmenu using function submenuforinstructor() and call each functions
when receive the chars(s, u, a, d or x) 

- void QuestionInformation()
print submenu of the Question-mainmenu using function submenuforquestion() and call each functions
when receive the chars(s, u, a, d or x) 

- void SubjectInformation()
print submenu of the Subject-mainmenu using function submenuforsubjecct() and call each functions when   receive the chars(s, u, a, d or x) 
 
- void GradeInformation()
print the whole student's grade list by opening the "GradeList.bin" filed. the grade list is including studentno, period, subject, midscore, finalscore

- void UpdatePasswd()
updates the logined Instructor's password. 
open the "InstructorList.bin" file and read until find the object that has logined Instructor's name. after accessing that object, receive the new passwd. write new passwd to that object. 

- void BuildFile() : 
  receive the student, instructor, grade, question and subject option. next, receive the name and path, check whether the entered path's last leter is '\' or not. if the latter, add the '\' character and using string+operator, create the file that has entered path, name.

There are each funcions for sub-menu. Here, I described only for student, because the submenu functions are similar to each other.

- void ShowStuList() 
show the lists of the student by opening the "StudentList.bin" file. We print studno, name and course of the students.

- void UpdateStu() 
receive the student number, name, course and passwd to update. If we find the student object that has     same number with the entered student number, update the information of that student object(not the   student number) using "write(reinterpret_cast<const char *>(&tmpstudent), sizeof(Student))" function.
   
- void AddNewStu() 
receive the student number, name, course and passwd to add. Create the temporary student object with   these informaions. So, write the student object in the "StudentList.bin" file. the object will locate in the end   of the file.

- void DeleteStu() 
receive the number of student to delete and find the student object that matches with entered number.
we couldn't find the method to delete the contents for size of the object, so we decide to fill object to 
0(for int variable) and ""(for string variable). Instead, when showing the student list, we print student obje
ct except the object that has '0' student number!

- void outputLine_stu()
function that helps to print the student object's information in organized form.

<Student.h>
Student header has basic functions of the class, for example, constructor, set & get functions. Also, 
There are funtions takeExamination(), viewGradeReport() and updatePasswd(), that each choices of the Student main menu. 

- char MainMenu()
print the mainmenu for the student and receive the character.

- void takeExamination()
At first, open the "SubjectList.bin" file to choose subject to take exam. read subject object to the end of file and print the subject number and subject name by using 'read(reinterpret_cast<char*>(& object), sizeof())' and 'outputLine_sublist()'. receive the subject number and examination period from the user. next, locates the file position pointer to beginning of the "SubjectList.bin" file by using clear() and seekg(). and find the subject name of the subject-object that has same number with entered subject number. assign the subject name to string variable subname. 
Secondly, open the "QuestionList.bin" file to read and print the questions. print the questions that are matches with subname, post is true and the period is same with entered period. moving cursor to each quesion, receive the answer and compare the entered answer with anskey. If the answer is correct, increase the count one by one. and final count is saved in midscore or finalscore.  

- void outputLine_sublist()
function that helps to print the subject object's information in organized form.

- void outputLine_exam()
 function that helps to print the question object's information in organized form.

- void viewGradeReport()
print grade list of the student that logined by opening the "GradeList.bin" file. the grade list is including studentno, period, subject, midscore, finalscore.

- void updatePasswd()
receive the new passwd and write the passwd in the logined student object. 

<Grade.h>, <Question.h>, <Subject.h>
In these headers, there are basic member variables and functions that constructor, set & get functions.
  
