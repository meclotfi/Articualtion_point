#include <iostream>
#include "classes/Node.h"
#include "classes/UGraph.h"
using namespace std;
int main() {
    std::cout << "begin creating the graph"<< std::endl;
UGraph g({"A","B","D","A","A","F","H"},{"B","C","I","D","E","G","H"});
g.to_png();
g.add_Arc("H","F");
g.to_png();
    return 0;
}

