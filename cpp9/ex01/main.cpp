#include <iostream>
#include <stack>
#include <string>
#include <sstream>
namespace operation {

    enum op {
        add,
        multiply,
        substract,
        divide,
        invalid,
    };
}

enum operation::op operation_from_string(std::string s)
{
    if (s.compare("+") == 0)
        return (operation::add);
    if (s.compare("/") == 0)
        return (operation::divide);
    if (s.compare("*") == 0)
        return (operation::multiply);
    if (s.compare("-") == 0)
        return (operation::substract);
    return (operation::invalid);
}

int string_to_int(std::string s, int &number) {
    int n;    
    std::istringstream stream(s);
    if (stream >> n && stream.eof()) {
        number = n;
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
	try {
    argc--;
    argv++;
    if (argc <= 0) {
        std::cerr << "No argument provided" << std::endl;
        return 1;
    }
    std::stack<int> rpn_stack;
    std::stringstream words(*argv);
    std::string arg;
    while (std::getline(words, arg, ' '))
    {
        int number = 0;
        if (string_to_int(arg, number)) {
            rpn_stack.push(number);
        }
        else
        {
            if (rpn_stack.size() < 2) {
                std::cerr << "Error" << std::endl;
                return 1;
            }
            int right = rpn_stack.top(); 
            rpn_stack.pop();
            int left = rpn_stack.top();
            rpn_stack.pop();
            switch (operation_from_string(arg))
            {
            case operation::add:
                rpn_stack.push(left + right);
                break;
            case operation::substract:
                rpn_stack.push(left - right);
                break;
            case operation::multiply:
                rpn_stack.push(left * right);
                break;
            case operation::divide:
				if (right == 0) {
                	std::cerr << "Error: Division by 0" << std::endl;
					return 1;
				}
				rpn_stack.push(left / right);
                break;
            case operation::invalid:
                std::cerr << "Error" << std::endl;
                return 1;
            }
        }
    }
    if (rpn_stack.size() != 1) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::cout << rpn_stack.top() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}
