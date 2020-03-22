#include <string>
#include<iostream>
#include <fstream>

// 文字cが数字かどうか
bool is_digit(char c) {
    return '0' <= c && c <= '9';
}

// code内の \(文字) 形式のものを、その文字の文字コードに置き換える
std::string replace_characters(std::string code) {
    std::string ret;
    for(int pos = 0; pos < code.size(); ++pos) {
        int char_code = 256;
        if(code[pos] == '\\' && pos+1 < code.size()) {
            char_code = code[pos+1];
            ++pos;
        }

        if(char_code == 256) {
            ret += code[pos];
        }
        else {
            ret += std::to_string(char_code);
        }
    }
    return ret;
}

// codeに含まれる数字を変換する
std::string replace_numbers(std::string code) {
    std::string ret;
    for(int pos = 0; pos < code.size(); ++pos) {
        int num = -1; //code[pos]に現れた数字を格納, 数字でなければ-1, numが0のときは一つ前の物を消す
        if(is_digit(code[pos])) {
            num = code[pos] - '0';
            while(pos + 1 < code.size() && is_digit(code[pos+1])){
                num *= 10;
                num += code[pos+1] - '0';
                ++pos;
            }
        }

        if(num >= 0 && ret.size() > 0) {
            char repeated_char = ret[ret.size() - 1];
            if(num == 0) {
                ret.erase(ret.end() - 1);
            }
            else {
                for(int i = 0; i < num - 1; ++i) {
                    ret += repeated_char;
                }
            }
        }
        else {
            ret += code[pos];
        }
    }
    return ret;
}

// replace_charactersを実行したあとにreplace_numbersを実行する
std::string generate_bf_code(std::string code) {
    return replace_numbers(replace_characters(code));
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        std::cerr << "引数にファイル名を入力してください" << std::endl;
        return 1;
    }
    std::string input_file_name = argv[1];
    std::string output_file_name = (argc >= 3 ? argv[2] : "a.bf");
    std::ifstream ifs(input_file_name);
    if(ifs.fail()) {
        std::cerr << input_file_name << "というファイルは存在しません" << std::endl;
        return 1;
    }
    
    std::string input, line;
    while(std::getline(ifs, line)) input += line + '\n';

    std::string output = generate_bf_code(input);
    std::ofstream ofs(output_file_name);
    ofs << output;

    return 0;
}