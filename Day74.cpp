// Day 74 - Question 1: Winner of an Election
// Close
// Problem Statement
// Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

// Input Format
// First line contains an integer n representing number of votes.
// Second line contains n space-separated strings representing candidate names.

// Output Format
// Print the name of the winning candidate followed by the number of votes received.

// Sample Input
// 13
// john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

// Sample Output
// john 4

// Explanation
// Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.

#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> votes;

    // Count votes
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        votes[name]++;
    }

    string winner = "";
    int maxVotes = 0;

    // Find winner
    for (auto x : votes) {
        string name = x.first;
        int count = x.second;

        if (count > maxVotes) {
            maxVotes = count;
            winner = name;
        }
    }

    cout << winner << " " << maxVotes;

    return 0;
}