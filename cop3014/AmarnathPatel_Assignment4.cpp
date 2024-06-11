
#include <iostream>
#include <string>

using namespace std;

class COP3014 {
public:
    COP3014() : firstName(""), lastName(""), zNumber(""), assignment1(0), assignment2(0), assignment3(0), midterm(0), finalExam(0), totalGrade(0), letterGrade("") {}

    COP3014(string firstName, string lastName, string zNumber, int a1, int a2, int a3, int midterm, int finalExam) :
        firstName(firstName), lastName(lastName), zNumber(zNumber), assignment1(a1), assignment2(a2), assignment3(a3), midterm(midterm), finalExam(finalExam), totalGrade(0), letterGrade("") {}

    void setFirstName(string firstName) {
        this->firstName = firstName;
    }

    void setLastName(string lastName) {
        this->lastName = lastName;
    }

    void setZNumber(string zNumber) {
        this->zNumber = zNumber;
    }

    void setAssignment1(int a1) {
        assignment1 = a1;
    }

    void setAssignment2(int a2) {
        assignment2 = a2;
    }

    void setAssignment3(int a3) {
        assignment3 = a3;
    }

    void setMidterm(int midterm) {
        this->midterm = midterm;
    }

    void setFinalExam(int finalExam) {
        this->finalExam = finalExam;
    }

    string getFirstName() {
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    string getZNumber() {
        return zNumber;
    }

    int getAssignment1() {
        return assignment1;
    }

    int getAssignment2() {
        return assignment2;
    }

    int getAssignment3() {
        return assignment3;
    }

    int getMidterm() {
        return midterm;
    }

    int getFinalExam() {
        return finalExam;
    }

    void input() {
        cout << "Enter student's first name: ";
        cin >> firstName;
        cout << "Enter student's last name: ";
        cin >> lastName;
        cout << "Enter student's Z-number: ";
        cin >> zNumber;
        cout << "Enter student's grade for assignment 1: ";
        cin >> assignment1;
        cout << "Enter student's grade for assignment 2: ";
        cin >> assignment2;
        cout << "Enter student's grade for assignment 3: ";
        cin >> assignment3;
        cout << "Enter student's grade for midterm: ";
        cin >> midterm;
        cout << "Enter student's grade for final exam: ";
        cin >> finalExam;
    }

    double getGrade() {
        double total = (assignment1 + assignment2 + assignment3) * 0.25 + midterm * 0.3 + finalExam * 0.45;
        totalGrade = total;
        return total;
    }

    string getLetterGrade() {
    double grade = getGrade();
    if (grade >= 90) {
        letterGrade = "A";
    }
    else if (grade >= 80) {
        letterGrade = "B";
    }
    else if (grade >= 70) {
        letterGrade = "C";
    }
    else if (grade >= 60) {
        letterGrade = "D";
    }
    else {
        letterGrade = "F";
    }
    return letterGrade; // Return the calculated letter grade
}


    void output() {
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Z-number: " << zNumber << endl;
        cout << "Grades below:" << endl;
        cout << "=====================" << endl;
        cout << "Assignment 1: " << assignment1 << endl;
        cout << "Assignment 2: " << assignment2 << endl;
        cout << "Assignment 3: " << assignment3 << endl;
        cout << "Midterm: " << midterm << endl;
        cout << "Final Exam: " << finalExam << endl;
        cout << "Total Grade: " << totalGrade << endl;
        cout << "Letter Grade: " << getLetterGrade() << endl;
    }

protected:
    string firstName;
    string lastName;
    string zNumber;
    int assignment1;
    int assignment2;
    int assignment3;
    int midterm;
    int finalExam;
    double totalGrade;
    string letterGrade;
};

class Fall23 : public COP3014 {
public:
   /* Fall23() : COP3014(), assignment4(0) {
        totalGrade=100;
    } */

    /*void input() {
        COP3014::input();
        cout << "Enter student's grade for assignment 4: ";
        cin >> assignment4;
    } */

    void setAssignment4(int a4) {
        assignment4 = a4;
    }
    int getAssignment4() {
        return assignment4;
    }

    /* void output() {
        COP3014::output();
        cout << "Assignment 4: " << assignment4 << endl; */
    
    void calculateGrades() { 
        totalGrade=(assignment1 + assignment2 + assignment3 + assignment4) * 0.25 + midterm * 0.3 + finalExam * 0.45;
    };
private:
    int assignment4;
};



class Summer23 : public COP3014 {
public:
    /* Summer23() : COP3014(), assignment4(0), bonus(0) {
        totalGrade=100;
    } // Constructor for the derived class. */
        void setAssignment4(int a4) {
            assignment4 = a4;
        }

        int getAssignment4(){
            return assignment4;
        }

        void setBonus(double bonusPercentage) {
            double bonus = 0.03;
            bonus = bonusPercentage;
            
            /* bonus = bonusPercentage; */
        }

        /* void input() {
            COP3014::input();
            cout << "Enter student's grade for assignment 4: ";
            cin >> assignment4;
            cout << "Enter student's bonus percentage: ";
            cin >> bonus;
        }
        */

        double addBonusToGrade() {
            double total = (assignment1 + assignment2 + assignment3 + assignment4) * 0.25 + midterm * 0.3 + finalExam * 0.45;
            totalGrade = total * (1 + bonus / 100);
            return totalGrade;
        }
        
        int calculateGrades() { 
        totalGrade=(assignment1 + assignment2 + assignment3 + assignment4) * 0.25 + midterm * 0.3 + finalExam * 0.45;
        return totalGrade;
    };
        
    protected:
        int assignment4;
        double bonus;
    public:
        void output() {
            COP3014::output();
            float bonuspercent = 0.03;
            cout << "Assignment 4: " << assignment4 << endl;
            cout << "Bonus Percentage: " << 3 << "%" << endl;
            cout << "Total Grade with Bonus:" << calculateGrades() << endl;
        }
  
};

int main() {
    Fall23 fallStudent;
    Summer23 summerStudent;

    // Input information for Fall23 student
    cout << "Enter information for Fall23 student:\n";
    fallStudent.input();

    // Input information for Summer23 student
    cout << "Enter information for Summer23 student:\n";
    summerStudent.input();

    // Display information for the Fall23 student
    cout << "\nInformation for Fall23 student:\n";
    fallStudent.output();
    
    // Display information for the Summer23 student
    cout << "\nInformation for Summer23 student:\n";
    summerStudent.output();

    return 0;
}
