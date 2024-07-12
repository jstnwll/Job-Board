/*
Alaska Jobs Directory.
Danielle Prupura
Justin Willemsen

This program allows employers to: 
    Add new job postings 
        Postings are given ID starting with 001
    Remove postings when a position is filled 
    
It also allows job seekers to:
    View all available job posting summaries
    Filter jobs by title, location, salary range, or company
    View full job posting
    Submit an inquiry for individual postings (save as an email?) 

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct jobListing
{
    int id;
    string title;
    string company;
    string location;
    double salary;
    string edReq;
    string expLevel;
    string description;
};

// FUNCTIONS
void employerMenu(vector<jobListing>& jobs);
void seekerMenu(const vector<jobListing>& jobs);
void addJob(vector<jobListing>& jobs);
void deleteJob(vector<jobListing>& jobs);
void viewJobs(const vector<jobListing>& jobs, int filterBy);
void displayJob(const jobListing& job);

int main()
{
    vector<jobListing> jobs;
    int choice;

    do
    {
    cout << "----- ALASKA JOBS MAIN MENU -----\n";
    cout << "\t1. Employer\n";
    cout << "\t2. Job Seeker\n";
    cout << "\t3. Exit\n";
    cin >> choice;
    cout << endl;

    switch (choice) {
        case 1: employerMenu(jobs); break;
        case 2: seekerMenu(jobs); break;
        case 3: cout << "Goodbye.\n"; break;
        default: cout << "Invalid entry. Try again.\n"; break;
        }
    } while (choice != 3);
    
    return 0;
}


/*
MENU FOR EMPLOYERS TO ADD/REMOVE JOB POSTINGS
*/
void employerMenu(vector<jobListing>& jobs)
{
    int choice;

    do
    {
    cout << "----- ALASKA JOBS EMPLOYER MENU -----\n";
    cout << "\t1. Post New Position\n";
    cout << "\t2. Remove Filled Position\n";
    cout << "\t3. Return to Main Menu\n";
    cout << "\t4. Exit\n";
    cin >> choice;
    cout << endl;

    switch (choice) {
        case 1: addJob(jobs); break;
        case 2: deleteJob(jobs); break;
        case 3: return;
        case 4: exit(0);
        default: cout << "Invalid entry. Try again.\n"; break;
        }
    } while (choice != 3);    
}


/*
MENU FOR JOB SEEKERS TO VIEW ALL OR FILTER JOB POSTINGS
*/
void seekerMenu(const vector<jobListing>& jobs)
{
    int choice;

    do
    {
        cout << "----- ALASKA JOBS JOB SEEKER MENU -----\n";
        cout << "\t1. View All\n";
        cout << "\tFilter By:\n";
        cout << "\t\t2. Title\n";
        cout << "\t\t3. Location\n";
        cout << "\t\t4. Starting Salary\n";
        cout << "\t\t5. Education Requirement\n";
        cout << "\t\t6. Experience Level\n";
        cout << "\t7. Return to Main Menu\n";
        cout << "\t8. Exit\n";
        cin >> choice;
        cout << endl;
        cin.ignore();

        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5: 
            case 6: 
                viewJobs(jobs, choice); break;
            case 7: return;
            case 8: exit(0);    
            default: cout << "Invalid entry. Try again.\n"; break;
            } 
    } while (choice != 7);
}

/*
FUNCTION TO ADD JOB DETAILS TO A NEW JOB ENTRY IN VECTOR
*/ 
void addJob(vector<jobListing>& jobs)
{
    jobListing newJob;
    int locationFilter;
    int salaryFilter;
    int edReqFilter;
    int expLevelFilter;

    // GENERATE JOB POSTING ID
    if (jobs.empty())
    {
        newJob.id = 1;
    }
    else
    {
        newJob.id = jobs.back().id + 1;
    }

    cout << "Enter New Job Details\n";

    cout << "Title: ";
    cin.ignore();
    getline(cin, newJob.title);

    cout << "Company: ";
    getline(cin, newJob.company);

    cout << "Location: \n";
    cout << "\t1. Anchorage\n";
    cout << "\t2. Fairbanks\n";
    cout << "\t3. Juneau\n";
    cout << "\t4. Matanuska Valley\n";
    cout << "\t5. Remote\n";
    cin >> locationFilter;
    cout << endl;

    switch (locationFilter) {
        case 1: newJob.location = "Anchorage"; break;
        case 2: newJob.location = "Fairbanks"; break;        
        case 3: newJob.location = "Juneau"; break; 
        case 4: newJob.location = "Matanuska Valley"; break; 
        case 5: newJob.location = "Remote"; break; 
        default: newJob.location = "Unknown"; break;                                             
        }

    cout << "Starting Salary: \n";
    cout << "\t1. $30,000+\n";
    cout << "\t2. $50,000+\n";
    cout << "\t3. $70,000+\n";
    cout << "\t4. $90,000+\n";
    cout << "\t5. $110,000+\n";
    cin >> salaryFilter;
    cout << endl;

    switch (salaryFilter) {
        case 1: newJob.salary = 30000; break;
        case 2: newJob.salary = 50000; break;        
        case 3: newJob.salary = 70000; break; 
        case 4: newJob.salary = 90000; break; 
        case 5: newJob.salary = 110000; break; 
        default: newJob.salary = 0; break;      // 0 = "UNKNOWN" STARTING SALARY                     
        }

    cout << "Education Requirements: \n";
    cout << "\t1. High School\n";
    cout << "\t2. Associates Degree\n";
    cout << "\t3. Bachelors Degree\n";
    cout << "\t4. Masters Degree\n";
    cout << "\t5. No Education Required\n";    
    cin >> edReqFilter;
    cout << endl;

    switch (edReqFilter) {
        case 1: newJob.edReq = "High School"; break;
        case 2: newJob.edReq = "Associates Degree"; break;        
        case 3: newJob.edReq = "Bachelors Degree"; break; 
        case 4: newJob.edReq = "Masters Degree"; break; 
        case 5: newJob.edReq = "No Education Required"; break; 
        default: newJob.edReq = "No Education Required"; break;                                             
        }

    cout << "Experience Level: \n";
    cout << "\t1. Entry-Level\n";
    cout << "\t2. Mid-Level\n";
    cout << "\t3. Senior-Level\n";
    cout << "\t4. No Experience Required\n";      
    cin >> expLevelFilter;
    cout << endl;

    switch (expLevelFilter) {
        case 1: newJob.expLevel = "Entry-Level"; break;
        case 2: newJob.expLevel = "Mid-Level"; break;        
        case 3: newJob.expLevel = "Senior-Level"; break; 
        case 4: newJob.expLevel = "No Experience Required"; break; 
        default: newJob.expLevel = "No Experience Required"; break;                                             
        }

    cin.ignore();
    cout << "Job Description: \n";
    getline(cin, newJob.description);
    cout << endl;

    jobs.push_back(newJob);
    cout << "Job Posted!\n\n";
}

/*
FUNCTION ALLOWS EMPLOYERS TO REMOVE POSITIONS AFTER THEY ARE FILLED
*/
void deleteJob(vector<jobListing>& jobs)
{
    if (jobs.empty())
    {
        cout << "There are no job postings to delete.\n";
        return;
    }

    // DISPLAY AVAILABLE JOBS TO DELETE BY ID, COMPANY, AND TITLE
    cout << "Current job postings.\n";
    for (int i = 0; i < jobs.size(); i++)
    {
        cout << "ID: " << jobs[i].id << "\tCompany: " << jobs[i].company << "\tTitle: " << jobs[i].title << endl;
    }
    cout << endl;

    int id;
    cout << "Enter the Job ID to delete.\n";
    cin >> id;

    for (int i = 0; i < jobs.size(); i++)
    {
        if (id == jobs[i].id)
        {
            jobs.erase(jobs.begin() + i);
            cout << "Job deleted.\n";
            return;
        }
    }

    cout << "Job ID Not Found.\n";
}

/*
FUNCTION ALLOWS JOB SEEKER TO VIEW ALL AVAILABLE JOBS OR A SELECTION BASED ON FILTER
*/
void viewJobs(const vector<jobListing>& jobs, int filterBy)
{
    string filter;
    if (filterBy == 2) // VIEW JOBS BY TITLE
    {
        cout << "Enter a job title to filter by: ";
        cin.ignore();
        getline(cin, filter);

        for (int i = 0; i < jobs.size(); i++)
        {
            if (filter == jobs[i].title)
            {
                displayJob(jobs[i]);
            }
        }
    }

    else if (filterBy == 3) // VIEW JOBS BY LOCATION
    {
        cout << "Enter a location to filter by (Anchorage, Fairbanks, Juneau, Matanuska Valley, Remote, Unknown): \n";
        getline(cin, filter);

        for (int i = 0; i < jobs.size(); i++)
        {
            if (filter == jobs[i].location)
            {
                displayJob(jobs[i]);
            }
        }
    }

    else if (filterBy == 4) // VIEW JOBS BY STARTING SALARY
    {
        double salaryFilter;
        cout << "Enter a starting salary to filter by (30000, 50000, 70000, 90000, 110000, 0): \n";
        cin >> salaryFilter;

        for (int i = 0; i < jobs.size(); i++)
        {
            if (salaryFilter == jobs[i].salary)
            {
                displayJob(jobs[i]);
            }
        }
    }

    else if (filterBy == 5) // VIEW JOBS BY EDUCATION REQUIREMENTS
    {
        cout << "Enter an education level to filter by (High School, Associates Degree, Bachelors Degree, Masters Degree, No Education Required): \n";
        getline(cin, filter);        

        for (int i = 0; i < jobs.size(); i++)
        {
            if (filter == jobs[i].edReq)
            {
                displayJob(jobs[i]);
            }
        }
    }

    else if (filterBy == 6) // VIEW JOBS BY EXPERIENCE LEVEL
    {
        cout << "Enter an experience level to filter by (Entry-Level, Mid-Level, Senior-Level, No Experience Required): \n";
        getline(cin, filter);        

        for (int i = 0; i < jobs.size(); i++)
        {
            if (filter == jobs[i].expLevel)
            {
                displayJob(jobs[i]);
            }
        }
    }

    else // VIEW ALL JOBS
    {
        for (int i = 0; i < jobs.size(); i++)
        {
            displayJob(jobs[i]);
        }
    }

}


// FUNCTION OUTPUTS SELECTED JOB POSTING
void displayJob(const jobListing& job)
{
    cout << "Job ID: " << job.id << endl;
    cout << "Job Title: " << job.title << endl;
    cout << "Company: " << job.company << endl;
    cout << "Location: " << job.location << endl;
    cout << "Starting Salary: $" << job.salary << endl;
    cout << "Education Required: " << job.edReq << endl;
    cout << "Experience Required: " << job.expLevel << endl;
    cout << "Description: " << job.description << endl;
    cout << endl;
}
