#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <iterator>


std::unordered_map<std::string, std::string> token_map = {
    {"(", "LParenteses"},
    {"+", "SUM"},
    {")", "RParenteses"},
    {"-", "SUB"},
    {"{", "LChave"},
    {"*", "MULT"},
    {"}", "RChave"},
    {"/", "DIV"},
    {"[", "LColchete"},
    {"%", "RESTO"},
    {"]", "RColchete"},
    {"int", "INTDEF"},
    {"==", "EQ"},
    {"float", "FLOATDEF"},
    {"=", "Atribuicao"},
    {"&&", "AND"},
    {">=", "GEQ"},
    {"||", "OR"},
    {"<=", "LEQ"},
    {">", "GT"},
    {"<", "LT"},
    {"!=", "DIF"},
    {"!", "NEG"},
    {"char", "CHAR TYPE"},
    {",", "Virgula"},
    {"bool", "BOOL TYPE"},
    {";", "PVirgula"},
    {"return", "RETURN"},
    {"if", "IF"}
};

bool isInt(const std::string &word) {
    try {
        std::stoi(word);
        return true;
    } catch (const std::invalid_argument &) {
        return false;
    }
}

bool isFloat(const std::string &word) {
    try {
        std::stof(word);
        return true;
    } catch (const std::invalid_argument &) {
        return false;
    }
}

int main() {
    std::ifstream input_file("input.txt");
    std::ofstream output_file("output.txt");

    std::stringstream buffer;
    buffer << input_file.rdbuf();
    std::string content = buffer.str();

    std::istringstream iss(content);

    std::vector<std::string> words(
        (std::istream_iterator<std::string>(iss)),
        std::istream_iterator<std::string>()
    );

    std::vector<std::string> output_tokens;

    for (const auto &word : words) {
        if (token_map.find(word) != token_map.end()) {
            output_tokens.push_back(token_map[word]);
        } else if (isInt(word)) {
            output_tokens.push_back("NUM_INT");
        } else if (isFloat(word)) {
            output_tokens.push_back("NUM_FLOAT");
        } else {
            output_tokens.push_back("VAR");
        }
    }

    std::string output_string = "";
    for (const auto &token : output_tokens) {
        output_string += token + " ";
    }

    output_file << output_string << std::endl;

    std::cout << "Sucesso!" << std::endl;

    return 0;
}