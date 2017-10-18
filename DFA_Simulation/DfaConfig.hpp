#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>

/* 
 * File:   DfaConfig.hpp
 * Author: mfloresn90
 *
 * Created on August 23, 2017, 9:39 PM
 */
using namespace std;

class DfaConfig {
private:
    string delimiter;
    string dfaName;

public:

    void setDfaName(string name) {
        dfaName = name;
    }

    int getDfaQCardinality() {
        int n = 0;
        int line_no = 0;
        string line;
        ifstream data_read(dfaName, ifstream::in);
        while (getline(data_read, line)) {
            if (line_no == 0) {
                n = atoi(splitLine(line).c_str());
            }
            line_no++;
        }
        return n;
    }

    int getDfaFCardinality() {
        int n = 0;
        int line_no = 0;
        string line;
        ifstream data_read(dfaName, ifstream::in);
        while (getline(data_read, line)) {
            if (line_no == 1) {
                n = atoi(splitLine(line).c_str());
            }
            line_no++;
        }
        return n;
    }

    int* getDfaF(int m) {
        int* result = new int[m];
        int n = 0;
        int line_no = 0;
        string line;
        size_t pos = 0;
        string token;
        delimiter = ", ";
        int counter = 0;
        ifstream data_read(dfaName, ifstream::in);
        while (getline(data_read, line)) {
            if (line_no == 2) {
                while ((pos = line.find(delimiter)) != string::npos) {
                    token = line.substr(0, pos);
                    result[counter] = atoi(token.c_str());
                    line.erase(0, pos + delimiter.length());
                    counter++;
                }
                result[counter] = atoi(line.c_str());
            }
            line_no++;
        }
        return result;
    }

    int* getDfaSaCardinality() {
        int* result = new int[2];
        int n = 0;
        int line_no = 0;
        string line;
        size_t pos = 0;
        string token;
        delimiter = ", ";
        int counter = 0;
        ifstream data_read(dfaName, ifstream::in);
        while (getline(data_read, line)) {
            if (line_no == 3) {
                while ((pos = line.find(delimiter)) != string::npos) {
                    token = line.substr(0, pos);
                    result[counter] = atoi(token.c_str());
                    line.erase(0, pos + delimiter.length());
                    counter++;
                }
                result[counter] = atoi(line.c_str());
            }
            line_no++;
        }
        return result;
    }

    int* getDfaVDeltaA(int total) {
        int* result = new int[total];
        int n = 0;
        int line_no = 0;
        string line;
        size_t pos = 0;
        string token;
        delimiter = ", ";
        int counter = 0;
        ifstream data_read(dfaName, ifstream::in);
        while (getline(data_read, line)) {
            if (line_no == 4) {
                while ((pos = line.find(delimiter)) != string::npos) {
                    token = line.substr(0, pos);
                    result[counter] = atoi(token.c_str());
                    line.erase(0, pos + delimiter.length());
                    counter++;
                }
                result[counter] = atoi(line.c_str());
            }
            line_no++;
        }
        return result;
    }

    int** getDfaDeltaA(int rows, int cols, int vector) {
        int** result = new int*[rows];
        for (int x = 0; x < rows; x++)
            result[x] = new int[cols];
        int* saVect = getDfaVDeltaA(vector);
        int counter = 0;
        for (int y = 0; y < vector; y += 2) {
            result[counter][0] = saVect[y];
            result[counter][1] = saVect[y + 1];
            counter++;
        }
        return result;
    }
    
    string getDfaRegEx() {
        string result;
        int line_no = 0;
        string line;
        ifstream data_read(dfaName, ifstream::in);
        while (getline(data_read, line)) {
            if (line_no == 5) {
                result = line;
            }
            line_no++;
        }
        return result;
    }

    /*int getDfaInfo(string str) {
        string line;
        ifstream data_read(str, ifstream::in);
        while (getline(data_read, line)) {
            cout << "Line -> " << line << endl;
            splitLine(line);
        }
        return 0;
    }*/

    string splitLine(string str) {
        size_t pos = 0;
        string token;
        delimiter = ", ";
        while ((pos = str.find(delimiter)) != string::npos) {
            token = str.substr(0, pos);
            str.erase(0, pos + delimiter.length());
        }
        return str;
    }

};