#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdint>

//perform a 1-bit arithmetic shift right with variable shift amount
int32_t arithmeticShiftRight(int32_t value, uint32_t shift) {
    return value >> shift; //arithmetic shift preserves the sign bit
}

//perform a logical shift right with variable shift amount
uint32_t logicalShiftRight(uint32_t value, uint32_t shift) {
    return value >> shift; //logical shift for unsigned
}

//perform a logical shift left with variable shift amount
uint32_t logicalShiftLeft(uint32_t value, uint32_t shift) {
    return value << shift; //Logical shift left
}

uint32_t bitwiseNOT(uint32_t value) {
    return ~value;
}

//convert hex string to uint32_t
bool hexToUInt32(const std::string& hexStr, uint32_t& value) {
    try {
        value = static_cast<uint32_t>(std::stoul(hexStr, nullptr, 0));
    } catch (...) {
        return false;
    }
    return true;
}

//convert hex string to int32_t
bool hexToInt32(const std::string& hexStr, int32_t& value) {
    try {
        value = static_cast<int32_t>(std::stol(hexStr, nullptr, 0));
    } catch (...) {
        return false;
    }
    return true;
}

//format the output as 32-bit hexadecimal
std::string formatHex(uint32_t value) {
    std::stringstream ss;
    ss << "0x" << std::uppercase << std::setfill('0') << std::setw(8) << std::hex << value;
    return ss.str();
}

int main() {
    std::ifstream infile("Programming-Project-2.txt");
    if (!infile.is_open()) {
        std::cerr << "Error: Cannot open the input file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(infile, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string cmd;
        std::string op1Str, op2Str;

        ss >> cmd;
        if (!cmd.empty() && cmd.back() == 'S') {
            cmd = cmd.substr(0, cmd.size() - 1); //remove the S
        }

        ss >> op1Str;
        ss >> op2Str;

        uint32_t op1_u, op2_u, result_u;
        int32_t op1_s, result_s;

        if (cmd == "ADD") {
            if (!hexToUInt32(op1Str, op1_u) || !hexToUInt32(op2Str, op2_u)) {
                std::cerr << "Error: Invalid operands for ADD." << std::endl;
                continue;
            }
            result_u = op1_u + op2_u;
            std::cout << formatHex(result_u) << std::endl;
        }
        else if (cmd == "AND") {
            if (!hexToUInt32(op1Str, op1_u) || !hexToUInt32(op2Str, op2_u)) {
                std::cerr << "Error: Invalid operands for AND." << std::endl;
                continue;
            }
            result_u = op1_u & op2_u;
            std::cout << formatHex(result_u) << std::endl;
        }
        else if (cmd == "ASR") {
            if (!hexToInt32(op1Str, op1_s)) {
                std::cerr << "Error: Invalid operand for ASR." << std::endl;
                continue;
            }
            //convert shift amount from string to integer
            uint32_t shift = 1; // Default shift
            if (!op2Str.empty()) {
                try {
                    shift = std::stoul(op2Str, nullptr, 0);
                }
                catch (...) {
                    std::cerr << "Error: Invalid shift amount for ASR." << std::endl;
                    continue;
                }
            }
            result_s = arithmeticShiftRight(op1_s, shift);
            std::cout << formatHex(static_cast<uint32_t>(result_s)) << std::endl;
        }
        else if (cmd == "LSR") {
            if (!hexToUInt32(op1Str, op1_u)) {
                std::cerr << "Error: Invalid operand for LSR." << std::endl;
                continue;
            }
            uint32_t shift = 1; 
            if (!op2Str.empty()) {
                try {
                    shift = std::stoul(op2Str, nullptr, 0);
                }
                catch (...) {
                    std::cerr << "Error: Invalid shift amount for LSR." << std::endl;
                    continue;
                }
            }
            result_u = logicalShiftRight(op1_u, shift);
            std::cout << formatHex(result_u) << std::endl;
        }
        else if (cmd == "LSL") {
            if (!hexToUInt32(op1Str, op1_u)) {
                std::cerr << "Error: Invalid operand for LSL." << std::endl;
                continue;
            }
            uint32_t shift = 1;
            if (!op2Str.empty()) {
                try {
                    shift = std::stoul(op2Str, nullptr, 0);
                }
                catch (...) {
                    std::cerr << "Error: Invalid shift amount for LSL." << std::endl;
                    continue;
                }
            }
            result_u = logicalShiftLeft(op1_u, shift);
            std::cout << formatHex(result_u) << std::endl;
        }
        else if (cmd == "NOT") {
            if (!hexToUInt32(op1Str, op1_u)) {
                std::cerr << "Error: Invalid operand for NOT." << std::endl;
                continue;
            }
            result_u = bitwiseNOT(op1_u);
            std::cout << formatHex(result_u) << std::endl;
        }
        else if (cmd == "ORR") {
            if (!hexToUInt32(op1Str, op1_u) || !hexToUInt32(op2Str, op2_u)) {
                std::cerr << "Error: Invalid operands for ORR." << std::endl;
                continue;
            }
            result_u = op1_u | op2_u;
            std::cout << formatHex(result_u) << std::endl;
        }
        else if (cmd == "SUB") {
            if (!hexToUInt32(op1Str, op1_u) || !hexToUInt32(op2Str, op2_u)) {
                std::cerr << "Error: Invalid operands for SUB." << std::endl;
                continue;
            }
            result_u = op1_u - op2_u;
            std::cout << formatHex(result_u) << std::endl;
        }
        else if (cmd == "XOR") {
            if (!hexToUInt32(op1Str, op1_u) || !hexToUInt32(op2Str, op2_u)) {
                std::cerr << "Error: Invalid operands for XOR." << std::endl;
                continue;
            }
            result_u = op1_u ^ op2_u;
            std::cout << formatHex(result_u) << std::endl;
        }
        else {
            std::cerr << "Error: Unknown command '" << cmd << "'." << std::endl;
            continue;
        }
    }
    infile.close();
    return 0;
}
