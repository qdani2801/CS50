#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Defining name and votes for Structure type Candidate
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array to store candidate name and vote
candidate candidates[MAX];

int candidate_count;

// Declaring Function Prototypes
bool vote(string name);
void print_winner(void);

// Main function
int main(int argc, string argv[])
{
    // Check for invalid commandline arguments
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Assign candidate names into candidates structure
    candidate_count = argc - 1;

    // If user enters more than 9 Candidate names
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // Assigning candidate names and votes
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Looping over voter's votes
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // If the vote isnt in candidate names then print out the error message
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Print Winner of Election
    print_winner();
}
// Main Function ends here

// Updating the vote count for Candidates
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++){
        if (strcmp(candidates[i].name, name) == 0){
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

// Print out the winner (or winners) of the election
void print_winner(void)
{
    int vote = 0;
    string name;
    for(int i = 0; i < candidate_count; i++){
        if (candidates[i].votes > vote){
            vote = candidates[i].votes;
            name = candidates[i].name;
        }
    }

    // In case there are more than 1 winners, we print out every winning candidate having tie
    for (int i = 0; i < candidate_count; i++){
        if (candidates[i].votes == vote){
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

// check50 cs50/problems/2022/x/plurality

