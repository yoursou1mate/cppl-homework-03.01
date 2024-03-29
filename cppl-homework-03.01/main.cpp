//
//  main.cpp
//  cppl-homework-03.01
//
//  Created by a1ex on 2/6/24.
//

#include <iostream>
#include <vector>

class CheckError : public std::domain_error
{
private:
    std::string error_message;
 public:
    CheckError(char *error_m): std::domain_error(error_m) {};
   
     const char* getError();
};


class smart_array {
private:
    int* arr;
    unsigned size;
    unsigned arr_length = 0;
public:
    smart_array (int size): arr(new int[size]), size(size)
    {
        std::cout << "Constructor worked" << std::endl;
    }
    
    auto add_element (int new_element)
    {
        if (arr_length < size) {
            arr[arr_length++] = new_element;
            
            }
            else if (arr_length >= size)
            {
                throw CheckError ("Array size error. No spacce left in array");
            };
//            std::cout << new_element << std::endl;
    };
    
    int get_element (int index)
        {
        if(index < size && index >= 0)
        {
            return arr[index];
        }
        else
        {
            throw CheckError ("Element index error. Wrong index");
        }
        };
};

int main(int argc, const char * argv[]) {
    
 try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);

        std::cout << arr.get_element(4) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
   
    
//    try
//    {
//        smart_array arr(5);
//        arr.add_element(1);
//        arr.add_element(4);
//        arr.add_element(155);
//
//        smart_array new_array(2);
//        new_array.add_element(44);
//        new_array.add_element(34);
//
//        arr = new_array;
//
//    }
//    catch (const std::exception& ex)
//    {
//    std::cout << ex.what() << std::endl;
//    }
    
    return 0;
}
