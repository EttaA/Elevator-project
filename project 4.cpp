// Program:				Project4.cpp
// Course:				CSE1311/ Section 02
// Name:				Etta Achere
// Assignment #:		Project 4
// Due Date:			04/25/2019

/* Purpose: This program takes a string array of names 
and an int array of weights and computes how many people (n),
and which of the people can get on an elevator with an 1100lbs 
weight limit.
The program also sorts the array in ascending order by weights
and descneding order by names and then decides which of the methods
allows the most people to ride the elevator at a time. 
*/

// Preprocessor directives

#include <iostream>			// iostream for cin and cout statements 
#include <cstring>			// cstring to handle the string array of names
using namespace std;


// prints the array

void print(string names[], int weight[], int n)
{
	cout << "Names \t Weights " << endl;
	
	for(int i=0; i<n; i++)
		{
			cout << names[i] << "\t " << weight[i] << endl; 
		}
}


// This function finds how many people at a time can get on the elevator

int howmany(int weight[], int lbs)
{
	int total =0, i=0;
	
	while(total<=lbs)
	{
		total+=weight[i];
		i++;
	}
	
	total -=weight[i-1];
	
	cout << i-1 << " People get on the elevator" << endl;
	cout << "Their total weight is " << total << " lbs" << endl;
	
return i-1;  // return i-1 because i includes the person whose wieght makes the total go over 1100lbs 
}

// This funcrion arranges array weight and names in ascending order 

void sortinc(string names[], int weight[], int n)
{
	int holdW;
	string holdN;
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(weight[i]>weight[j])
				{
					// swapping the weights and the names 
					holdW=weight[i];
					holdN=names[i];
					
					weight[i]=weight[j];
					names[i]=names[j];
					
					weight[j]=holdW;
					names[j]=holdN;	
				}
		}
	}	
}

// This funcrion arranges array weight and names in ascending order

void sortdec(string names[], int weight[], int n)
{
	int holdW;
	string holdN;

	for(int index=0; index<n; index++)
		{
			int min= index;
			for (int scan= index+1; scan<n; scan++)
				{
					if(names[scan] > names[min])
						{	
							min=scan;
							// swapping the weights and the names 
							holdW=weight[min];
							holdN=names[min];
							
							weight[min]=weight[index];
							names[min]=names[index];
							
							weight[index]=holdW;
							names[index]=holdN;	
						}
				}
		}
}


int main ()
{
	int n= 12, lbs=1100, CTA, CTB, CTC;
	string names[12]= {"Anne", "Bob", "Ralph", "Tim", "Barbara", "Jane", "Steve", "Tom", "Mike","Shirley", "Pam", "Frank"};
	int weight[12]= { 150, 250, 305, 250, 85, 160, 180, 210, 165, 155, 125, 130};
	
	print(names, weight, 12);
	cout << "\n";
	CTA= howmany(weight, 1100);
	cout <<"\n";
	cout << "The people below get on the elevator \n";
	print(names, weight, CTA);
	cout <<"\n";
	
	sortinc(names, weight, 12);
	cout<< "\n";
	print(names, weight, 12);
	cout<< "\n";
	CTB= howmany(weight, 1100);
	cout<< "\n";
	cout << "The people below get on the elevator \n";
	print(names, weight, CTB);
	
	sortdec(names, weight, 12);
	cout << "\n";
	print(names, weight, 12);
	cout<< "\n";
	CTC= howmany(weight, 1100);
	cout<< "\n";
	cout << "The people below get on the elevator \n";
	print(names, weight, CTC);
	cout<< "\n";
	
	// The following if statement prints out which method allowed the most people on the elevator
	
	if((CTA > CTB) && (CTA > CTC))
		{
			cout << "CTA (Array as given) allowed the most people on the elevator \n";	
		}
	else if((CTB > CTA) && (CTB > CTC))
		{
			cout << "CTB (Dscending array order) allowed the most people on the elevator \n";
		}
	else 
		cout << "CTC (Descending array order) allowed the most people on the elevator \n";
		
	cout << "\n";
		
	cout << "Coded by Etta Achere \n";
	return 0;
}

