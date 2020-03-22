#include <string>
#include <iostream>

// 文字cが数字かどうか
bool is_digit(char c) {
    return '0' <= c && c <= '9';
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

int main(int argc, char *argv[]) {
    std::string s = (argc >= 2 ? argv[1] : "");
    std::cout << replace_numbers(s) << std::endl;
    return 0;
}