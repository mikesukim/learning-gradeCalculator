#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;



class Course
{
public:
    Course(); // default constructor
    void get(string& name, string& time, string& number,
        char& g, int& h) const;
    void set(string name, string time, string number,
        char g, int h);
    void print() const;
    
private:
   
   string courseName;
   string courseTime;
   string courseNumber;
   char grade;
   int hours;
  
};

Course::Course()
{
  
   
   courseName = "none";
   courseTime = "none";
   courseNumber = "none";
   grade = ' ';
   hours = 0;
   Per
   
}
void Course::set(string name, string time, string number, char g, int h)
{
    
    courseName = name;
    courseTime = time;
    courseNumber = number;
    grade = g;
    hours = h;
           
}
void Course::get(string& name, string& time, string& number, char& g, int& h) const
{
    name = courseName;
    time = courseTime;
    number = courseNumber;
    g = grade;
    h = hours;
           
}
void Course::print() const
{
    
    cout << courseName << endl;
    cout << courseTime << endl;
    cout << courseNumber << endl;
    cout << grade << endl;
    cout << hours << endl;
    
}

class requirement
{
public:
    requirement();
    void get(string& Group, string &Subgroup, int &Subgrouphour);
    void set(string group, string subgroup, int subgrouphour);
    void add(string coursenumber , int coursehour, int &k );
    void getadd(string Coursenumber[50], int Coursehour[50]);
    void print();
   
    
private:
        
    string group;
    string subgroup;
    int subgrouphour;
    string coursenumber[50];
    int coursehour[50];
    int max;
    string Coursenumber[50];
    int Coursehour[50];
};
requirement :: requirement()
{
    group = "test";
    subgroup = " ";
    subgrouphour = 0;
}
void requirement :: get(string& Group, string &Subgroup, int &Subgrouphour)
{
    Group = group;
    Subgroup = subgroup;
    Subgrouphour =subgrouphour ;
    
}
void requirement :: set (string Group, string Subgroup, int Subgrouphour)
{
    group = Group;
    subgroup = Subgroup;
    subgrouphour = Subgrouphour;   
    
}

void requirement :: add (string Coursenumber, int Coursehour, int & i ) 
{
    coursenumber[i] = Coursenumber;
    coursehour[i] = Coursehour;
    max = i;
    
}
void requirement :: getadd (string Coursenumber[50], int Coursehour[50])
{
    for(int k = 0; k < 50; k++)
    {
    Coursenumber[k] = coursenumber[k];
    Coursehour[k] = coursehour[k];
    }
    
}

void requirement :: print ()
{
    cout << group << endl;
    cout << subgroup << endl;
    cout << subgrouphour << endl;         
      for(int k = 0; k <= max; k++)
    { 
        cout << coursenumber[k] << endl;
        cout << coursehour[k] << endl;
    } 
}




/////////////////// OPTION A ////////////////////////////
/////////////////////////////////////////////////////////

double gpa(int n, Course course[80]) {
    double gradeacredit = 0; // == grade * credit
    double totalcredit = 0; // ==sum of credits
    double tgradeacredit = 0; // == total sum of (grade * credit)
     // *** Extra array for credit(hours) is because for grade
    //     'W' and 'i' it could not be changed straight to hours[] = 0
    //     because of declaration parameter with const for int hours.  ***

   string name;
   string time;
   string number;
   char grade;
   int hours;

    for (int i = 0; i < n; i += 1) {

        course[i].get(name,time,number,grade,hours);
        

        if (grade == 'a' ||
                grade == 'A') {
            gradeacredit = 4 * hours;
        } else if (grade == 'b' ||
                grade == 'B') {
            gradeacredit = 3 * hours;
        } else if (grade == 'c' ||
                grade == 'C') {
            gradeacredit = 2 * hours;
        } else if (grade == 'd' ||
                grade == 'D') {
            gradeacredit = 1 * hours;
        } else if (grade == 'f' ||
                grade == 'F') {
            gradeacredit = 0 * hours;
        } else if (grade == 'w' ||
                grade == 'W') {
            gradeacredit = 0 * hours;
            hours = 0;
            
        } else if (grade == 'i' ||
                grade == 'I') {
            gradeacredit = 0 * hours;
            hours = 0;
        }



        totalcredit = totalcredit + hours;

        tgradeacredit = tgradeacredit + gradeacredit;
    }

    double finalgpa = tgradeacredit / totalcredit;

    if (finalgpa >= 3.5) {
        cout << "Excellent!! Your GPA is !! = " << finalgpa << endl;
    } else if (finalgpa >= 3.0) {
        cout << "It's a high score!! Your GPA is !! = " << finalgpa << endl;
    } else if (finalgpa >= 2.0) {
        cout << "Its goood!! Your GPA is !! = " << finalgpa << endl;
    } else {
        cout << "Sorry dude.. Your GPA is !! = " << finalgpa << endl;
    }


    return finalgpa;

}


/////////////////// OPTION B ////////////////////////////
/////////////////////////////////////////////////////////

double semesterGpa(int n, string &semester, Course course[80]) {
    double totalcredit = 0;
    double gradeacredit = 0;
    double tgradeacredit = 0;
    double finalgpa;
    bool match = false;

   string name;
   string time;
   string number;
   char grade;
   int hours;

    for (int k = 0; k < n; k ++) {
        course[k].get(name,time,number,grade,hours); 
        if( semester == time) {
            match = true;
        }
    }


    if (match) {
        for (int k = 0; k < n; k += 1){
            
            course[k].get(name,time,number,grade,hours); 
            
            if (semester == time){
                if (grade == 'a' ||
                    grade == 'A') {
                    gradeacredit = 4 * hours;
                }
                else if (grade == 'b' ||
                    grade == 'B') {
                    gradeacredit = 3 * hours;
                } 
                else if (grade == 'c' ||
                    grade == 'C') {
                    gradeacredit = 2 * hours;
                } 
                else if (grade == 'd' ||
                    grade == 'D') {
                    gradeacredit = 1 * hours;
                } 
                else if (grade == 'f' ||
                        grade == 'F') {
                        gradeacredit = 0 * hours;
                } 
                else if (grade == 'w' ||
                        grade == 'W') {
                        gradeacredit = 0 * hours;
                        hours = 0;
                }
                else if     (grade == 'i' ||
                        grade == 'I') {
                        gradeacredit = 0 * hours;
                        hours = 0;
                }


                totalcredit += hours;
                tgradeacredit += gradeacredit;

            }
        }
        finalgpa = tgradeacredit / totalcredit;

        if (finalgpa >= 3.5) {
            cout << "Excellent!! Your GPA is !! = " << finalgpa << endl;
        } else if (finalgpa >= 3.0) {
            cout << "It'ss a high score!! Your GPA is !! = " << finalgpa << endl;
        } else if (finalgpa >= 2.0) {
            cout << "Its goood!! Your GPA is !! = " << finalgpa << endl;
        } else {
            cout << "Sorry dude.. Your GPA is !! = " << finalgpa << endl;
        }
    }

    if (!match) {

        cout << "The semester you just entered has not be found." << endl;

    }


    return finalgpa;

}



/////////////////// OPTION C ////////////////////////////
/////////////////////////////////////////////////////////

int DRule(int n, Course course[80]) {

   string name;
   string time;
   string number;
   char grade;
   int hours;
   
    int dcredit = 0;
    for (int k = 0; k < n; k += 1)
    {
        course[k].get(name,time,number,grade,hours);
        if (grade == 'd' || grade == 'D')
        {
            dcredit += hours;
        }
    }

    cout << "Total hours with D grades are " << dcredit << ". " << endl;

    return 0;

}


/////////////////// OPTION D ////////////////////////////
/////////////////////////////////////////////////////////

void print(int n , Course course[80]) {
   
    for(int i = 0; i < n; i++)
    {
         course[i].print();
    }
 

       
}


/////////////////// OPTION E ////////////////////////////
/////////////////////////////////////////////////////////

void getCourse( int n, Course course[80]) {

   string name;
   string time;
   string number;
   char grade;
   int hours;
    // course name
    cout << "Type the course name for your class " << n << "." << endl;

    getline(cin, name);
    getline(cin, name);

    //semester
    cout << "Type the semeter for your class " << n << "." << endl;

    getline(cin, time);

    //course number
    cout << "Type the coruse number for your class " << n << "." << endl;

    getline(cin, number);

    //letter grade
    cout << "Type a grade(A,B,C,D,F,W,I) for a class " << n << "!" << endl;
    cin >> grade;
    // While for user input error for grade
    while (grade != 'a' && grade != 'A'
            && grade != 'b' && grade != 'B'
            && grade != 'c' && grade != 'C'
            && grade != 'd' && grade != 'D'
            && grade != 'f' && grade != 'F'
            && grade != 'w' && grade != 'W'
            && grade != 'i' && grade != 'I')
 {
        cout << "you typed an incorrect grade for a class " << n << "." << endl;
        cout << "Type a grade(A,B,C,D,F,W,I) for a class " << n << "!" << endl;

        cin >> grade;
    }

    //credit hours
    cout << "Type credit hours(1..5) for a class " << n << "!" << endl;
    cin >> hours;
    // While for user error for credit
    while (hours < 1 || hours > 5)
 {
        cout << "you typed incorrect credit for a class " << n << "." << endl;
        cout << "Type a credit hour(1..5) for a class " << n << "." << endl;
        cin >> hours;
    }

    course[n-1].set(name,time,number,grade,hours);
}

/////////////////// OPTION F ////////////////////////////
/////////////////////////////////////////////////////////

char menu() {
    char a;
    const string textmenu = " \nwelcome to the interactive menu driven part of your system! "
            " \nPlease enter the chracter next to the choice you wish to pick!"
            " \nHere are your Options:\n"
            " \nA(a). Compute the GPA of all courses"
            " \nB(b). Compute the GPA for a particular semester"
            " \nC(c). Compute the total credit hours of the courses with grade D"
            " \nD(d). List all courses"
            " \nE(e). Add another course to the course list"
            " \nF(f). Delete a course to the course list"
            " \n **********G(g). For reading 'requirement.txt' , validating for courses, degree audting!! ********HW7 "
            " \nQ(q). Quit the program"


            " \n"
            " \n Please choose one the above! \n";

    cout << textmenu;
    cin >> a;

    return a;
}


//////////////////HW 5///////////////////////////////////
//////////////////////////////////////////////////////////

bool reading(const char filename[], int& n,
        int capacity, Course course[80]) {
   
   string name;
   string time;
   string number;
   char grade;
   int hours;  
   
   
    fstream infile;
    infile.open(filename);

    if (infile.fail())
    {
        cout << "Error: could not open input file named : " << infile << endl;
        exit(EXIT_FAILURE);
        return 0;
    }
    cout << "File input was successful. Please review the courses." << endl;
    infile >> n;
    if (n > capacity) {
        cout << "Your number of classes should be below 80." << endl;
        cin >> n;
    }


    for (int i = 0; i < n; i++) {
        getline(infile, name);
        getline(infile, name);
 
        getline(infile, time);
        getline(infile, number);
        infile >> grade;
        infile >> hours;
        
        course[i].set(name, time, number, grade, hours);
    }
    
    for(int i = 0; i < n; i++)
    {
         course[i].print();
    }
 
        
    

    
    infile.close();
    return 1;


}

bool writing(const char filename[],int n, Course course[80]) {
 
   string name;
   string time;
   string number;
   char grade;
   int hours;
    
    fstream outfile;
    outfile.open(filename);
    
   
    if (outfile.fail()){
        cout << "Error: could not open output file named : "<< outfile << endl; 
        exit(EXIT_FAILURE);
        return 0;
    }
    outfile << n << endl;
    for (int i = 0; i < n; i++) {
        course[i].get(name,time,number,grade,hours);
        outfile << name << endl;
        outfile << time << endl;
        outfile << number << endl;
        outfile << grade << endl;
        outfile << hours << endl;

    }
    
    string blank =  " ";
    for (int k = n; k <= 51; k++){
        outfile << blank << endl;
    }
    
    outfile.close();
    return 1;

}

bool deletion ( int& n, Course course[10]){

    string name;
    string time;
    string number;
    char grade;
    int hours;
    
    int choice;
    char confirm;
    
    if(n == 0){
        cout << "There are nothing to be deleted" << endl;
        return 0;
    }
    cout << "Select from 1 to " << n << " for the course to be deleted." << endl;
    cin >> choice;
    
    
    while ( choice > n || choice < 1 ){
        cout << " Select from 1 to " << n << " for the course to be deleted." << endl;
        cin >> choice;
     }
            
    
    cout << "Here is the course you have selected for deletion."<< endl;
    
   
    course[choice - 1].print();
 
    
    cout << "Would you like to delete the course above?" << endl;
    cout << "Please enter y for yes and n for no" << endl;
    cin >> confirm;

    while (confirm != 'y' &&
            confirm != 'n') {
        cout << "The character entered is " << confirm << " is not y or n " << endl;
        cout << "Would you like to delete the course above?" << endl;
        cout << " Please type y for yes and n for no." << endl;
        cin >> confirm;
    }

    if(confirm == 'y') {
        
        while(choice  <= n){
            
            course[choice].get(name, time, number, grade, hours);
            course[choice-1].set(name, time, number, grade, hours);
                    
                                      
        choice ++;
        
        }
    n = n - 1;    
       
    return 1;    
    

    }


  
    
return 0;   
    
     
    
}

void requirement_reading(const char filename[], requirement requirement[30], int& i)
{
    fstream infile;
    infile.open(filename);

    if (infile.fail())
    {
        cout << "Error: could not open input file named : " << infile << endl;
        exit(EXIT_FAILURE);
      
    }
    cout << "Requirement file was input successful. Please review the courses." << endl;
 
    string group;
    string subgroup;
    int subgrouphour;
    string coursenumber;
    int coursehour;
    
     i = 0;
     int k = 0;

    while(!infile.eof())
    {  
        getline(infile, group);
        getline(infile, subgroup);
        infile >> subgrouphour;
      
        infile.ignore();

        requirement[i].set(group, subgroup, subgrouphour);
 
           
        getline(infile, coursenumber);
       
        while (!coursenumber.empty() && !infile.eof())
        {
            infile >> coursehour;  
            infile.ignore();
            requirement[i].add(coursenumber, coursehour, k); 
                          
            k++;
      
            getline(infile, coursenumber);
        }
            i++;    
            k = 0;
    }   
    infile.close();  
}

void validation(Course course[80], Course unique[50], int & size, int & m)
{   
    string name;
    string time;
    string number;
    char grade;
    int hours;
    
    string uname;
    string utime;
    string unumber;
    char ugrade;
    int uhours;
    
 
   
    int k = 0;   
    m = 0;
    
    
    course[k].get(name,time,number,grade,hours);
    
    if(!(grade == 'f' || grade == 'F' ||
       grade == 'w' || grade == 'W' ||
       grade == 'i' || grade == 'I'))
   
    {unique[k].set(name,time,number,grade,hours);}
    
    k ++;
    m ++;

    while(k < size)
    {  
        bool found= false; 
        
        course[k].get(name,time,number,grade,hours);
        
        if((grade == 'f' || grade == 'F' ||
                 grade == 'w' || grade == 'W' ||
                 grade == 'i' || grade == 'I'))
        { k++; 
          continue;  }
                      
        for(int i = 0; i < k; i++)
        {
            unique[i].get(uname,utime,unumber,ugrade,uhours);                              
                               
            if(name == uname)              
            {
                found = true; 
                if(grade < ugrade) 
                {   
                    unique[i].set(name,time,number,grade,hours);                   
                } 
               
            } 
             
        }   

        if(!found) 
        {unique[m].set(name,time,number,grade,hours); 
         m++;}
        
         k++;
            
    }   
}

void audit(Course unique[50], requirement requirement[30],Course final[50], int & i, int & m)
{
    string group;
    string subgroup;
    int subgrouphour;
    string coursenumber[50];
    int coursehour[50];
    
    string name;
    string time;
    string number;
    char grade;
    int hours;
    
    bool match = false;
    int totalhour = 0;
    
    int j = 0;
    int q = 0;
    int w = 0;
    
    
     for( int k = 0; k < m; k++)
     {
     requirement[k].get(group,subgroup,subgrouphour);  
     requirement[k].getadd(coursenumber, coursehour);   
    
        for(int k = 0 ; k < i; k++ )
        {
         unique[k].get(name,time,number,grade,hours); 
         
        
        
             for(int t = 0; t < 50; t++)
             {  
                if (coursenumber[t] == number)
                {match = true;
                  
                
                final[q].set(name,time,number,grade,hours);
               
                q++;
                
                //cout << hours << endl;
                totalhour = hours + totalhour;
               // cout << totalhour <<endl;
                }               
            }    
         
            
        }
     
     //cout <<" Q = " <<q << endl;
     
     bool met = false;
     bool partially_met = false;
     bool notatall = false;
     bool over =  false;
     
     
     if(totalhour >= subgrouphour)
     {  met = true;}              
     if(totalhour == 0)
     {  notatall = true;}    
     if(totalhour < subgrouphour)
     {  partially_met = true;}
     if(w >= q)
     { over = true;}
     
     if(met)
     { 
        cout << group <<" " << subgroup <<" "<<"is met by :" << endl;
      
        while(w < q)       
            {final[w].print();             
       
            w++;}
        
     }  
     
     if (notatall)
     { 
         cout << group <<" " << subgroup <<" "<<"is not met at all" << endl;
         k++;
         continue;
     }
     
     if(partially_met)
         { 
            cout << group <<" " << subgroup <<" "<<"is partially met by " <<"(hour still need : "<< subgrouphour - totalhour << ")" << endl;
            while(w < q)       
               {final[w].print();             
               // cout << "W = " << w << endl;
                w++;}
            
         }
     
   //  if(over)
   //  { cout << group << " " << subgroup << " " << "is not met at all" << endl;
       
   //  }
     //cout << "W = " << w << endl;
     //cout << totalhour << endl;
     
     totalhour = 0;
     }
    
    
   // cout << "                                final array" << endl;
   // for(int b = 0; b < 15; b++)
   // final[b].print();
     
}



/////////////////////MAIN FUNCTION////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////

int main() {


    int numberofclasses = 0; // for an user input for number of classes
    int classnumber = 0;

    char read_file_choice;
    char def_file_choice;
    char filename[15] = "courses.txt";
    char dfilename[15];
    char requirement_name[30] = "requirement.txt";
    char drequirement[30];
    
    ////////HW7!!!!!!!!!//////////////////
   ///////////////////////////////////////
     
    Course course[80];
    requirement requirement[30];
    Course unique[50];
    Course final[50];
    
    
    string name;
    string number;
    string semester;
    char grade;
    int hours;
  
    ////////////////////////////////////
    
 
    
    cout << "Welcome to PF1 course management system v1. " << endl;

    cout << "Would you like to read the courses taken from a file?" << endl;

    cout << " Please type y for yes and n for no." << endl;
    cin >> read_file_choice;

    

       
       
    while (read_file_choice != 'y' &&
            read_file_choice != 'n') {
        cout << "The character entered is " << read_file_choice << " is not y or n " << endl;
        cout << "Would you like to read the courses taken from a file?" << endl;
        cout << " Please type y for yes and n for no." << endl;
        cin >> read_file_choice;
    }

    if (read_file_choice == 'y') {

        cout << "Would you like to use the default file?" << endl;
        cout << "Please type y for yes and n for no." << endl;
        cin >> def_file_choice;

        while (def_file_choice != 'y' &&
                def_file_choice != 'n') {
            cout << "The character entered is " << def_file_choice << " is not y or n " << endl;
            cout << "Would you like to use the default file?" << endl;
            cout << " Please type y for yes and n for no." << endl;
            cin >> read_file_choice;
        }

        if (def_file_choice == 'y') {


            reading(filename,  numberofclasses, 80 , course);

        }

    }

    if (def_file_choice == 'n') {

        cout << "Enter your file name." << endl;
        cin >> dfilename;

        reading(dfilename, numberofclasses, 80 , course);

    }

    if (read_file_choice == 'n') {


        cout << "Interactive mode was selected." << endl;
        cout << "Enter the number of classes for your system!" << endl;
        cin >> numberofclasses;

        while (!(numberofclasses <= 80 && numberofclasses > 0)) {
            cout << "number of classes can not be more than 80!" << endl;
            cout << "Enter the number of classes for your system!" << endl;
            cin >> numberofclasses;
        }

        for (int i = 0; i < numberofclasses; i += 1) {




            //To present class number (ex. class1, class2)
            classnumber = classnumber + 1;


            // course name
            cout << "Type the course name for your class " << classnumber << "." << endl;

            getline(cin, name);
            getline(cin, name);


            //semester
            cout << "Type the semeter for your class " << classnumber << "." << endl;

            getline(cin, semester);

            //course number
            cout << "Type the course number for your class " << classnumber << "." << endl;

            getline(cin, number);

            //letter grade
            cout << "Type a grade(A,B,C,D,F,W,I) for a class " << classnumber << "!" << endl;
            cin >> grade;

            // While for user input error for grade
            while (grade != 'a' && grade != 'A'
                    && grade != 'b' && grade != 'B'
                    && grade != 'c' && grade != 'C'
                    && grade != 'd' && grade != 'D'
                    && grade != 'f' && grade != 'F'
                    && grade != 'w' && grade != 'W'
                    && grade != 'i' && grade != 'I')
            {
                cout << "you typed an incorrect grade for a class " << classnumber << "." << endl;
                cout << "Type a grade(A,B,C,D,F,W,I) for a class " << classnumber << "!" << endl;

                cin >> grade;
            }

            //credit hours
            cout << "Type credit hours(1..5) for a class " << classnumber << "!" << endl;
            cin >> hours;

            // While for user error for credit
            while ( hours < 1
                    || hours > 5)
            {
                cout << "you typed incorrect credit for a class " << classnumber << "." << endl;
                cout << "Type a credit hour(1..5) for a class " << classnumber << "." << endl;
                cin >> hours;
            }

            course[i].set(name, semester, number, grade, hours);
        }

    }

   
    
    
    char choice;
    choice = menu();

    while (choice != 'Q' && choice != 'q') {



        if (choice == 'A' || choice == 'a') {
            cout << "\n===Option A is selected===\n";

            gpa(numberofclasses, course);

        }

        else if (choice == 'B' || choice == 'b') {
            cout << "\n===Option B is selected===\n";

            string csemester;
            cout << "Type specific semester for calculating your GPA" << endl;
            getline(cin, csemester);
            getline(cin, csemester);

            semesterGpa(numberofclasses, csemester, course);

        }
        else if (choice == 'C' || choice == 'c') {
            cout << "\n===Option C is selected===\n";

            DRule(numberofclasses, course);
        }
        else if (choice == 'D' || choice == 'd') {
            cout << "\n===Option D is selected===\n";

            print( numberofclasses, course );
        }
        else if (choice == 'E' || choice == 'e') {
            cout << "\n===Option E is selected===\n";


            getCourse( numberofclasses + 1, course);
            numberofclasses += 1;

            
        }
        else if (choice == 'F' || choice == 'f') {
            cout << "\n===Option F is selected===\n";
            deletion ( numberofclasses, course );
        
        }
            
        
        else if (choice == 'G' || choice == 'g'){
            cout << "\n===Option G is selected===\n";	
            
            
            int k = 0;
            requirement_reading(requirement_name,requirement,k);
	    int q = 0;
            validation( course, unique, numberofclasses, q);
            cout <<"***** REVIEW YOUR REQUIREMENT FILE **********" << endl;
            for(int i = 0; i < k; i++)
	    {requirement[i].print();}
            cout <<"***** REVIEW YOUR VALIDATED COURSES **********" << endl;
            for(int i = 0; i < q; i++){
            unique[i].print();}
            cout <<"*************HERE IS DEGREE AUDIT*********"<<endl;
            cout <<"*******************************************" <<endl;
            audit (unique, requirement,final ,q, k );

        }
 
      
            
        else {
            cout << "\n *** You did not follow the menu instruction and entered : " << choice << "  *** \n";

        }
        choice = menu();


    }


    writing(filename, numberofclasses, course);
   
    
    
 
 
    cout << "\n ===terminating...===\n";
    cout << endl;
    cout << "Thank you." << endl;


    return 0;
}

