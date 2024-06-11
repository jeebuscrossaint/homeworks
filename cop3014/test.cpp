#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int MAX_QUIZZES = 10;

struct Student {
    string firstName;
    string lastName;
    int quizScores[MAX_QUIZZES];
    int numQuizzes;
    double averageScore;
};

int generateNumQuizzes() {
    return rand() % (MAX_QUIZZES + 1);
}

void generateQuizScores(int numQuizzes, int quizScores[]) {
    for (int i = 0; i < numQuizzes; i++) {
        quizScores[i] = rand() % 21;
    }
}

void readStudentInfo(ifstream& inputFile, Student& student) {
    inputFile >> student.lastName >> student.firstName;
    student.numQuizzes = 0;
    while (inputFile >> student.quizScores[student.numQuizzes]) {
        student.numQuizzes++;
    }
}

double computeAverageScore(int numQuizzes, int quizScores[]) {
    double totalScore = 0;
    for (int i = 0; i < numQuizzes; i++) {
        totalScore += quizScores[i];
    }
    return totalScore / MAX_QUIZZES;
}

void writeStudentInfo(ofstream& outputFile, const Student& student) {
    outputFile << student.lastName << " " << student.firstName << " ";
    for (int i = 0; i < student.numQuizzes; i++) {
        outputFile << student.quizScores[i] << " ";
    }
    for (int i = student.numQuizzes; i < MAX_QUIZZES; i++) {
        outputFile << "0 ";
    }
    outputFile << fixed << setprecision(1) << student.averageScore << endl;
}

int main() {
    srand(time(NULL));
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    outputFile << "This file displays the student grades along with the average score for each student." << endl;
    for (int i = 0; i < 5; i++) {
        Student student;
        student.numQuizzes = generateNumQuizzes();
        generateQuizScores(student.numQuizzes, student.quizScores);
        writeStudentInfo(outputFile, student);
    }
    inputFile.close();
    inputFile.open("input.txt");
    while (!inputFile.eof()) {
        Student student;
        readStudentInfo(inputFile, student);
        student.averageScore = computeAverageScore(student.numQuizzes, student.quizScores);
        writeStudentInfo(outputFile, student);
    }
    inputFile.close();
    outputFile.close();
    return 0;
}
