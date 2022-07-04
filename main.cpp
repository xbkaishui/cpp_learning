#include <iostream>
#include <Eigen/Dense>

#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>


using namespace std;
using namespace Eigen;

void test_matrix();


std::string join(std::vector<string> const &strings, std::string delim) {
    std::stringstream ss;
    std::copy(strings.begin(), strings.end(),
              std::ostream_iterator<std::string>(ss, delim.c_str()));
    return ss.str();
}

// for string delimiter
vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;
    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }
    auto last = s.substr(pos_start);
    if(!last.empty()){
        res.push_back(last);
    }
    return res;
}

void test_vector_serial() {
    std::cout << "in vector serial" << std::endl;
    auto file_path = "/tmp/vec";
    std::ofstream dataFile;
    dataFile.open(file_path, std::ios::out | std::ios::app);
    std::cout << "write data file " << file_path << std::endl;
    auto data_vec = std::vector<int>();
    for (int i = 0; i < 1000; i++) {
        data_vec.emplace_back(i);
    }

    auto data_vec_str = std::vector<string>();
    for (int i = 0; i < data_vec.size(); i++) {
        data_vec_str.emplace_back(std::to_string(data_vec[i]));
    }
    auto delimiter = ",";
    auto s = join(data_vec_str, delimiter);
//    dataFile << s << '\n';
//    dataFile.close();

    std::vector<int> read_data_vec;
    std::ifstream file_in(file_path);
    if (!file_in) {/*error*/}
    std::string line;
    std::getline(file_in, line);
    std::cout << line << std::endl;
    if (!line.empty()) {
        vector<string> data = split(line, delimiter);
        std::cout << "data size " << data.size() << std::endl;
    }
}

void hello() {
    std::cout << "Hello, World!" << std::endl;
}

int main() {
//    test_matrix();
//    hello();
    test_vector_serial();
    return 0;
}

void test_matrix() {
    Matrix<float, 1, 5> matrix;
    matrix[0] = 0.02;
    matrix[1] = 0.03;
    matrix[2] = 0.04;
    matrix[3] = 0.05;
    matrix[4] = 0.06;
    cout << matrix << endl;
    auto size = matrix.size();
    cout << "size " << size << endl;
    auto pointer = matrix.data();
    cout << *pointer << endl;
    cout << matrix.sum() << endl;
}
