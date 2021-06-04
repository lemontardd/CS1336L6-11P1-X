#include <fstream>
#include <iostream>
#include<string>
#include <iomanip>
using namespace std;

int Read(ifstream& inputFile, string infile, char arr[]);
void display(char studentAnswers[], char answers[], int maxSize);
int main()
{
   //Each array must be able to support up to 30 characters
   const int MAX_QUESTIONS = 30;

   //Declare two parallel arrays
   char studentAnswers[MAX_QUESTIONS];
   char answers[MAX_QUESTIONS];

   //Save the two filenames user enters.
   string infile1, infile2;
   
   // input stream for the input file
   ifstream inputFile;

   //prompt and read student file from the console
   cout << "Enter student answers file name" << endl;
   //infile1 = "student.txt"; 
   cin >> infile1;
   int answerCount = Read(inputFile, infile1, studentAnswers);
   if (answerCount != -1)
   {
	   inputFile.close();

	   //prompt and read answers file from the console
	   cout << "Enter correct answer file name" << endl;
	   //infile2 = "student5.txt"; 
	   cin >> infile2;
	   int studentAnswerCount = Read(inputFile, infile2, answers);
	   if (studentAnswerCount != -1)
	   {
		   if (studentAnswerCount == 0 && answerCount == 0)
		   {
			   cout << "The number of student answers and correct answers are both 0" << endl;
			   cout << "No grade can be calculated" << endl;
		   }
		   else if (studentAnswerCount != answerCount)
		   {
			   cout << "The student answers file has " << answerCount  << " entries and the correct answers file has " << studentAnswerCount << " entries" << endl;
			   cout << "Grading cannot be done if they are not the same" << endl;
		   }
		   else
		   {
			   //call the display function
			   display(studentAnswers, answers, answerCount);
		   }
	   }
	   else
	   {
		   //If either call to the read function does
		   //not work it should output a message stating
		   //that the specific file could not be opened
		   cout << "File \"" << infile2 << "\" could not be opened" << endl;
	   }
   }
   else
   {
	   cout << "File \"" << infile1  << "\" could not be opened" << endl;
   }

   return 0;
}

//One function needs to be passed a char array of size 30,
//it also needs to be passed an input file name
int Read(ifstream& inputFile, string infile, char arr[])
{
   char ans;
   int count = 0;
   inputFile.open(infile.c_str());

   if (inputFile.fail())
   {
      return -1;
   }
   else
   {
      while (inputFile >> ans)
      {
         arr[count] = ans;
		 count++;
		 if (count >= 30) // Skip reading after 30 answers.
		 {
			 break;
		 }
      }
   }
   //The return from the function should be a bool value
   return count;
}

//The display function will be passed the two
//arrays and should calculate results
void display(char studentAnswers[], char answers[], int answerCount)
{
   int count = 0;
   double studentGrade;
   for (int i = 0; i < answerCount; i++)
   {
      if (studentAnswers[i] != answers[i])
      {
         //display the results from the program
         cout << "Question " << i + 1 << " has incorrect answer '"   << studentAnswers[i] 
              << "', the correct answer is '"  << answers[i] << "'" << endl;
      }
      else
      {
         count++;
      }
   }

   if (count != answerCount)
   {
      //display the number of question were missed
      cout << answerCount - count << " questions were missed out of " << answerCount << endl;
   }
   else
   {
      cout << answerCount - count << " questions were missed out of " << answerCount << endl;
   }
   studentGrade = (((double)count) / answerCount) * 100;
   cout << "The student grade is " << setprecision(1) << fixed << studentGrade << "%" << endl;

   if (studentGrade < 70)
   {
      //Display a message
      cout << "The student failed" << endl;
   }
   else
   {
      //Display a message
      cout << "The student passed" << endl;
   }
}