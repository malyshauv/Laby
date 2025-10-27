#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
struct Info {
    string text;
    int count;
    int startLine;
};
vector<Info> findDuplicateGroups(const vector<string>& lines) {
    vector<Info> groups;
    if (lines.empty()) return groups;
    string line = lines[0];
    int currCount = 1;
    int currStart = 1;
    for (size_t i = 1; i <= lines.size(); i++) {
        if (i < lines.size() && lines[i] == line) {
            currCount++;
        } else {
            if (currCount > 1) {
                groups.push_back({line, currCount, currStart});
            }
            if (i < lines.size()) {
                line = lines[i];
                currCount = 1;
                currStart = i + 1;
            }
        }
    }
    return groups;
}
int main() {
    string inputFile, outputFile;
    cout << "input filename: ";
    cin >> inputFile;
    cout << "output filename: ";
    cin >> outputFile;
    ifstream in(inputFile);
    if (!in.is_open()) {
        cerr << "error opening input file" << endl;
        return 1;
    }
    vector<string> lines;
    string line;
    while (getline(in, line)) {
        lines.push_back(line);
    }
    in.close();
    vector<Info> groups = findDuplicateGroups(lines);
    ofstream out(outputFile);
    if (!out.is_open()) {
        cerr << "error creating output file" << endl;
        return 1;
    }
    if (groups.empty()) {
        out << "no duplicate groups found" << endl;
    } else {
        out << "duplicate groups found:" << endl;
        for (const auto& group : groups) {
            out << "\"" << group.text << "\" | "
                << group.count << " | "
                << group.startLine << endl;
        }
    }
    out.close();
    cout << groups.size() << " groups found" << endl;
    return 0;
}
