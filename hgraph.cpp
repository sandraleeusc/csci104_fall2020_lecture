#include <iostream>
#include <string>
#include <vector>
// You may add other necessary #include statements but not <algorithm>
#include <map>
#include <queue>
using namespace std;

// You MAY NOT change public member functions in any way
class HollywoodGraph {
public:
    /* There is no default constructor. Once the graph is created with n nodes,
       no nodes will be added or deleted. */
    HollywoodGraph(int n, std::vector<std::string> names); // constructor
    ~HollywoodGraph (); // destructor


    bool addConnection(std::string person1, std::string person2);
    /* adds a undirected edge between person1 and person2 and runs in O(log(n))
       Returns true if an edge is added and false if person1 and person2 are
       already connected. You may assume person1 and person2 are valid names
       provided in list of names in the constructor. */

    int countConnections(std::string person1);
    /* Given a person's name, returns a count to the number of people that
       person1 knows. This function must run in O(n) where n is the number
       of nodes or people in the graph. You may assume person1 is a valid name
       provided in the list of names in the constructor. */

    bool degreesOfSeparation(std::string person1, std::string person2, int k, int &calls);
    /* This function should return true if person 1 can contact person 2 by
       making at most k phone calls between people in the graph. If person 1
       can reach person 2, the number of calls needed should be returned in the
       integer calls. If it is not possible, this function should return the
       value false and the value in calls should not be modified. This should run
       in O(n+m) where n is the number of nodes and m the number of connections in the graph.
       You may assume person1 and person2 are valid names.  */

private:
    std::vector<std::vector<bool> > aMatrix;  // MUST be used as an n-by-n adjacency matrix
  
    // feel free to add private member variables or functions

   


};


int main()
{
    vector<string> stars = {"a", "b", "c", "d","e"};
    HollywoodGraph g(5, stars);
    g.addConnection("a","b");
    g.addConnection("c","b");
    g.addConnection("a", "c");
    g.addConnection("a", "e");
    cout << "d has " << g.countConnections("d") << " connections" << endl;
    cout << "a has "  << g.countConnections("a") << " connections " << endl;
    
    int calls = 0;
    int limit = 3;
    if (g.degreesOfSeparation("c","e", limit, calls)){
    cout << " c can reach e in " << calls << " calls" << endl;
    } else {
        cout << "c cannot reach e in " << limit << " calls" << endl;
    }
    return 0;
}


