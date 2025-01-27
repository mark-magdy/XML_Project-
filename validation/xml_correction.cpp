#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <fstream>
#include "validate.hpp"
using namespace std;

 stack<string> s1_stack;
 stack<string> s2_stack;
 stack<int> s3_stack;
 stack<string> *s1=&s1_stack;
 stack<string> *s2=&s2_stack;
 stack<int> *s3=&s3_stack;

 extern vector<string> lines;


vector <string> lines_extraction(string filepath){
    vector <string> xml_lines;
    string line;
    fstream input_file;

    input_file.open(filepath, ios::in); //open file

	if (input_file.is_open()) { //check if file opened successfully
		while (getline(input_file, line)) { //while line is not empty lines extract
			if (!line.empty()) { // skip empty lines
				xml_lines.push_back(line);//push line in vector
			}
		}
	}

    input_file.close(); //close file

    return xml_lines;
}

vector <string> correct_xml(string xml_string){

    int error_line_number;
    string tag_missing;
    string type;

    validation check;
    check.check_valid(xml_string,s1,s2,s3);

    lines.push_back(" ");

    while(!s2_stack.empty() && !s3_stack.empty() && !s1_stack.empty()){
        error_line_number= s3_stack.top();
        s3_stack.pop();
        tag_missing=s2_stack.top();
        s2_stack.pop();
        type=s1_stack.top();
        s1_stack.pop();
        
            if (error_line_number >= 0 && error_line_number < lines.size()-1) {
                if(type=="Closing tag")
                lines[error_line_number-1] = "<"+tag_missing+">"+lines[error_line_number-1];
                else
                lines[error_line_number-1] = "</"+tag_missing+">"+lines[error_line_number-1];
             }else if (error_line_number==lines.size()-1)
             {  if(type=="Closing tag")
                lines[error_line_number] = "<"+tag_missing+">"+lines[error_line_number];
                else
                lines[error_line_number] = "</"+tag_missing+">"+lines[error_line_number];
             }
             

    }
    return lines;
}

void writeback_file(vector <string> xml_lines,string filepath){
    ofstream output_file(filepath);
    if(output_file.is_open()){
        for (int i = 0; i < xml_lines.size(); i++) {
        output_file << xml_lines[i] << "\n";
    }
    output_file.close();
    }
}



// int main(){
//     vector<string> corrected_xml_lines;
//     //string xml_string;
// string xmlData = 
// "<a>\nxml\n<a>\n<user>\n</user>\n<app>\n";
//     corrected_xml_lines = correct_xml(xmlData );
//     writeback_file(corrected_xml_lines, "sample_mynew.xml");

//     return 0;
// }
  
  //test main
//   int main(){

// string xmlData = 
// "<users>\n"
// "\t<user>\n"
// "\t\t<id>1</id>\n"
// "\t\t<name>Ahmed Ali</name>\n"
// "\t\t<posts>\n"
// "\t\t\t<post>\n"
// "\t\t\t\t<body>\n"
// "\t\t\t\t\tLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\n"
// "\t\t\t\t</body>\n"
// "\t\t\t\t<topics>\n"
// "\t\t\t\t\t<topic>\n"
// "\t\t\t\t\t\teconomy\n"
// "\t\t\t\t\t</topic>\n"
// "\t\t\t\t\t<topic>\n"
// "\t\t\t\t\t\tfinance\n"
// "\t\t\t\t\t</topic>\n"
// "\t\t\t\t</topics>\n"
// "\t\t\t</post>\n"
// "\t\t\t<post>\n"
// "\t\t\t\t<body>\n"
// "\t\t\t\t\tLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\n"
// "\t\t\t\t</body>\n"
// "\t\t\t\t<topics>\n"
// "\t\t\t\t\t<topic>\n"
// "\t\t\t\t\t\tsolar_energy\n"
// "\t\t\t\t\t</topic>\n"
// "\t\t\t\t</topics>\n"
// "\t\t<followers>\n"
// "\t\t\t<follower>\n"
// "\t\t\t\t<id>2</id>\n"
// "\t\t\t</follower>\n"
// "\t\t\t<follower>\n"
// "\t\t\t\t<id>3</id>\n"
// "\t\t\t</follower>\n"
// "\t\t</followers>\n"
// "\t</user>\n"
// "\t<user>\n"
// "\t\t<id>2</id>\n"
// "\t\t<name>Yasser Ahmed</name>\n"
// "\t\t<posts>\n"
// "\t\t\t<post>\n"
// "\t\t\t\t<body>\n"
// "\t\t\t\t\tLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\n"
// "\t\t\t\t</body>\n"
// "\t\t\t\t<topics>\n"
// "\t\t\t\t\t<topic>\n"
// "\t\t\t\t\t\teducation\n"
// "\t\t\t\t\t</topic>\n"
// "\t\t\t\t</topics>\n"
// "\t\t\t</post>\n"
// "\t\t</posts>\n"
// "\t\t<followers>\n"
// "\t\t\t<follower>\n"
// "\t\t\t\t<id>1</id>\n"
// "\t\t\t</follower>\n"
// "\t\t</followers>\n"
// "\t</user>\n"
// "\t\n"
// "\t\t<id>3</id>\n"
// "\t\t<name>Mohamed Sherif</name>\n"
// "\t\t<posts>\n"
// "\t\t\t<post>\n"
// "\t\t\t\t<body>\n"
// "\t\t\t\t\tLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\n"
// "\t\t\t\t</body>\n"
// "\t\t\t\t<topics>\n"
// "\t\t\t\t\t\n"
// "\t\t\t\t\t\tsports\n"
// "\t\t\t\t\t</topic>\n"
// "\t\t\t\t</topics>\n"
// "\t\t\t</post>\n"
// "\t\t</posts>\n"
// "\t\t<followers>\n"
// "\t\t\t<follower>\n"
// "\t\t\t\t<id>1</id>\n"
// "\t\t\t</follower>\n"
// "\t\t</followers>\n"
// "</users>";


//     validation check;
//     check.check_valid(xmlData,s1,s2,s3);
//     // Print the errors stored in the stacks
//     while (!s1_stack.empty()) {
//         cout << s1_stack.top() << endl;
//         s1_stack.pop();
//     }
//     while (!s2_stack.empty()) {
//         cout << s2_stack.top() << endl;
//         s2_stack.pop();
//     }
//     while (!s3_stack.empty()) {
//         cout << s3_stack.top() << endl;
//         s3_stack.pop();
//     }
//   }
