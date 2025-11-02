#include <iostream>
#include <ostream>

void hamInChuoi(const char* v) 
{
    std::cout << "hàm in chuỗi: " << v << std::endl;
}

int main(int cg, char ** vg)
{

    // kiểu cơ bản
    int ci = 'l';
    char c = 'l';  // tương đương uint8_t, 1 byte 8bit 2^8 = 256, 0 <= c < 256
    uint8_t un8 = 108; // ASCII Table
    int8_t n8 = 0; // -128 to 127 , 128 + 127 = 255

    int n = 0; //64 bit 8 byte 64bit
    uint16_t n16; // 2^16 = 65536
    uint64_t n64;
    long nlong;

    float f = 1.0f; // 4 byte 0.99999 =1
    double d = 1.0; // 8 byte 

    std::cout << ci << std::endl;
    std::cout << c << std::endl;


    // kiểu tham khảo
    // std::string a = "con chó"; // OOP
    char* s = "abccccdd"; // ~ uint8_t* s
    uint8_t* r = &un8;
    
    std::cout << "địa chỉ: " << (size_t) r << std::endl;
    std::cout << "giá trị: " << *r << std::endl;
    std::cout << "giá trị số nguyên: " << (int)(*r) << std::endl;


    std::cout << "chuỗi: " << s << std::endl;
    std::cout << "chuỗi: " << (int) s[7] << std::endl; // d 100
    std::cout << "chuỗi: " << (int) s[8] << std::endl; // Null character '\0'

    for(int i =0; i < 100; i++)
    {
        std::cout << s[i] << std::endl;
    }
    


    // s[8] = 100;
    // s[20] = 0;
    // std::cout << "chuỗi: " << s << std::endl;

    // kiểu tự định nghĩa
    struct {
        int power;
        uint16_t speed;
    } player;

    // macro sizeof

    std::cout << "kích thước int: " << sizeof(int) << std::endl;
    std::cout << "kích thước: " << sizeof(player) << std::endl;

    hamInChuoi(s);

    // println(c);

    // if (a == "con heo") {
    //     std::cout << "ăn cám 😽" << std::endl;
    // }
    // else
    // {
    //     std::cout << "ko biết" << std::endl;
    // }

    // for(int i = 0; i <= 100; i=i+2) {
    //     std::cout << "Đếm tới số: " << i << std::endl;
    // }
    
    return 0;
}