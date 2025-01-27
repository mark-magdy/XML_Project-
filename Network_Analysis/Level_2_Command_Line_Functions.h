#ifndef LEVEL_2_COMMAND_LINE_FUNCTIONS_H
#define LEVEL_2_COMMAND_LINE_FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
//#include <utility>
//#include <memory>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <unordered_set>

#include <fstream>
#include "UsersGraph.h"
#include "postsSearch.h"

using namespace std; 

void draw_graph(string xml ,string outputFile);
pair<long, string> get_most_active(string xml);
pair<long, string> get_most_influencer(string xml);
vector<long> get_mutual(string xml, const vector<long>& IDs);
vector<long> get_suggest(string xml, long ID);
vector <string> search_by_word (string xml, string word);
vector <string> search_by_topic (string xml, string topic);

#endif //LEVEL_2_COMMAND_LINE_FUNCTIONS_H
