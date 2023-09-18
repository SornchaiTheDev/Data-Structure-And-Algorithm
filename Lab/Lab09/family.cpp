#include <iostream>
#include <vector>
using namespace std;

vector<int> descendantCount;

int calculateDescendantCount(const vector<vector<int> >& children, int node) {
    int count = 0;
    for (int child : children[node]) {
        count += 1 + calculateDescendantCount(children, child);
    }
    descendantCount[node] = count;
    return count;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int> > children(n);

    for (int i = 1; i < n; i++) {
        int parent;
        cin >> parent;
        children[parent - 1].push_back(i);
    }
    
    descendantCount.resize(n);
    calculateDescendantCount(children, 0);
    
    for (int i = 0; i < n; i++) {
        cout << descendantCount[i] << " ";
    }
    
    cout << endl;

    return 0;
}
