#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
===========================================================
Approach 1: Last Occurrence Method
Time Complexity  : O(n)
Space Complexity : O(1)

Idea:
We need to count substrings containing at least one
'a', one 'b', and one 'c'.

Instead of checking every substring, store the latest
(last seen) index of a, b, and c.

Example:
s = "abcabc"

right = 2 ('c')

last[a] = 0
last[b] = 1
last[c] = 2

minimum index = min(0,1,2) = 0

All substrings ending at index 2 and starting from:

[0..2]

are valid.

Count = minimum_index + 1
      = 0 + 1
      = 1

Why +1 ?

Because valid starting positions are:
0 → count = 1 position

If minimum index were 2:

possible starting positions:
0,1,2

count = 3 = 2+1

===========================================================
*/

class OptimalSolution {
public:
    int numberOfSubstrings(string s) {

        // Stores latest index of a,b,c
        int last[3] = {-1,-1,-1};

        int count = 0;

        for(int right=0; right<s.size(); right++){

            // Update latest occurrence
            last[s[right]-'a'] = right;

            // Only proceed when all characters exist
            if(last[0]!=-1 &&
               last[1]!=-1 &&
               last[2]!=-1){

                /*
                Smallest index decides how many
                starting positions are possible
                */
                count += min({
                    last[0],
                    last[1],
                    last[2]
                }) + 1;
            }
        }

        return count;
    }
};


/*
===========================================================
Approach 2: Sliding Window (My Solution)
Time Complexity  : O(n)
Space Complexity : O(1)

Idea:
Maintain a window [i...j].

Expand j until window contains:
a,b,c

Once all are present:

Every substring extending from j
to the end of string will also remain valid.

Why?

Current window:
[a...b...c]

If we add more characters to right:
[a...b...c...x]
[a...b...c...y]
[a...b...c...z]

a,b,c still exist.

Hence number of valid substrings:

(n-j)

Then shrink from left and repeat.

Example:

s = "abcabc"

Window = "abc"

j = 2

Valid substrings:

abc
abca
abcab
abcabc

Count += n-j
      += 6-2
      += 4

Then move left pointer and continue.

===========================================================
*/

class MySolution {
public:
    int numberOfSubstrings(string s) {

        int n = s.length();

        // Frequency of a,b,c
        vector<int> mp(3,0);

        int result = 0;

        int i = 0;
        int j = 0;

        while(j<n){

            // Expand window
            mp[s[j]-'a']++;

            /*
            Window currently contains
            all three characters
            */
            while(mp[0]>0 &&
                  mp[1]>0 &&
                  mp[2]>0){

                /*
                All substrings from
                current j till end
                are valid
                */
                result += (n-j);

                // Shrink window
                mp[s[i]-'a']--;
                i++;
            }

            j++;
        }

        return result;
    }
};

int main(){

    string s;

    cout<<"Enter string: ";
    cin>>s;

    MySolution obj;

    cout<<"Number of substrings = "
        <<obj.numberOfSubstrings(s);

    return 0;
}