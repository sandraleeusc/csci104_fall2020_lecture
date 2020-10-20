/*************************
 * N-Queens solution
 *  Author: David Kempe & Mark Redekopp
 *  
 *  Notes: Modify to print ALL Solutions
 *
 *************************/
#include <iostream>
#include <cstdlib>
using namespace std;

//prototypes
void addToThreats(int row, int col, int change);
bool search(int row);
void printSolution();
void printEntry(int r, int c);

// Global Variables
//   These could be local variables that we just pass to search(...)
int *q;         // queen location array
int n;          // number of board / size
int **t;        // n x n threat array
int nsols = 0;  // number of solutions found

int main(int argc, char* argv[])
{
  if(argc < 2) {
    cerr << "Please provide the size fo the board" << endl;
    return 1;
  }
  n = atoi(argv[1]);
  q = new int[n];
  t = new int*[n];
  for(int i=0; i < n; i++){
    t[i] = new int[n];
    for(int j = 0; j < n; j++){
      t[i][j] = 0;
    }
  }

  // start search on row/queen 0
  search(0); 

  if( nsols == 0) 
     cout << "No sol!" << endl;

  // deallocate arrays
  delete [] q;
  for(int i=0; i < n; i++){
    delete [] t[i];
  }
  delete [] t;
  return 0;
}

void addToThreats(int row, int col, int change)
{
  for(int j = row+1; j < n; j++){
    // go down column
    t[j][col] += change;
    // go down right diagonal
    if( col+(j-row) < n )
       t[j][col+(j-row)] += change;
    // go down left diagonal
    if( col-(j-row) >= 0)
       t[j][col-(j-row)] += change;
  }
}

bool search(int row)
{
  if(row == n){
    nsols++;
    printSolution(); // solved!
    return true;
  }
  else {
    for(q[row]=0; q[row]<n; q[row]++){
      // check that col: q[row] is safe
      if(t[row][q[row]] == 0){
	// if safe place and continue
	addToThreats(row, q[row], 1);

#ifdef DEBUG
	printEntry(row, q[row]);
#endif
	// Recurse to next
	bool status = search(row+1);

	if(status) {   return true; };
	
	// if returned, remove placement
	addToThreats(row, q[row], -1);
      } 
    } 
    // Backtrack to previous row
    return false;
  }
}

void printSolution()
{
  cout << "\n\nSolution " << nsols << ": " << endl;
  for(int i=0; i < n; i++){
    for(int j=0; j < n; j++){
      if(j == q[i]) cout << "Q";
      else cout << "*";
    }
    cout << endl;
  }
  
}

void printEntry(int r, int c)
{
  for(int i=0; i < r; i++){
    cout << "  ";
  }
  cout << "Checked r,c = " << r << "," << c << endl;
}
