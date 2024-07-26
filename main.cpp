#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

struct Subject {
    string name;
    double credits;
    double gradePoints;
};

double calculateCGPA(const vector<Subject>& subjects) {
    double totalCredits = 0;
    double totalGradePoints = 0;

    for (const auto& subject : subjects) {
        totalCredits += subject.credits;
        totalGradePoints += subject.gradePoints * subject.credits;
    }

    return totalGradePoints / totalCredits;
}

void addSubject(vector<Subject>& subjects) {
    Subject subject;
    cout << "Enter subject name: ";
    cin >> subject.name;

    while (true) {
        cout << "Enter credits: ";
        cin >> subject.credits;
        if (cin.fail() || subject.credits <= 0) {
            cout << "Invalid input. Please enter a positive number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    while (true) {
        cout << "Enter grade points: ";
        cin >> subject.gradePoints;
        if (cin.fail() || subject.gradePoints < 0 || subject.gradePoints > 10) {
            cout << "Invalid input. Please enter a number between 0 and 10." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    subjects.push_back(subject);
    cout << "Subject added successfully!" << endl;
}

void viewSubjects(const vector<Subject>& subjects) {
    cout << left << setw(15) << "Subject" << setw(10) << "Credits" << setw(15) << "Grade Points" << endl;
    cout << "-----------------------------------------" << endl;
    for (const auto& subject : subjects) {
        cout << left << setw(15) << subject.name << setw(10) << subject.credits << setw(15) << subject.gradePoints << endl;
    }
}

int main() {
    vector<Subject> subjects;
    int choice;

    while (true) {
        cout << "\nCGPA Calculator Menu" << endl;
        cout << "1. Add Subject" << endl;
        cout << "2. View Subjects" << endl;
        cout << "3. Calculate CGPA" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addSubject(subjects);
                break;
            case 2:
                viewSubjects(subjects);
                break;
            case 3: {
                if (subjects.empty()) {
                    cout << "No subjects available to calculate CGPA." << endl;
                } else {
                    double cgpa = calculateCGPA(subjects);
                    cout << "Your CGPA is: " << fixed << setprecision(2) << cgpa << endl;
                }
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
