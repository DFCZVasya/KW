#include "stack.cpp"
#include <string>


int get_element_priority(char element)
{
    switch (element) {
        case '(' :
            return 1;
        case ')' :
            return 2;
        case '=' :
            return 3;
        case '+' :
        case '-' :
            return 4;
        case '*' :
        case '/' :
            return 5;
        case '^' :
            return 6;
        default:
            return -1;
    }
}

std::string result_string(std::string input_string, Stack<char> operators)
{
	std::string output_str = "", number = "";

	for (int i = 0; i < input_string.length(); i++)
	{
		while(input_string[i] >= '0' && input_string[i] <= '9')
		{
			number += input_string[i];
			i++;
		}

		operators.print_stack();
		if (number.length() != 0)
		{
			output_str += number;
			output_str += ' ';
			number = "";
		}
		else
		{
			if (operators.isEmpty())
			{
				operators.push(input_string[i]);
			}
			else
			{
				if (get_element_priority(operators.top()) >= get_element_priority(input_string[i]))
				{
					if (operators.top() != ')' && operators.top() != '(')
					{
						output_str += operators.pop();
						output_str += ' ';
					}
					operators.push(input_string[i]);
				}
				else
				{
					operators.push(input_string[i]);
				}
			}
		}

		if (i == input_string.length()-1)
		{
			while (!operators.isEmpty())
			{
				if (operators.top() != ')' && operators.top() != '(')
				{
					output_str += operators.pop();
					output_str += ' ';
				}
			}
		}
		
	}
	return output_str;
}

int main()

{
	std::string s;
	std::getline(std::cin, s);
	Stack<char> operators;
	for (int i = 0; i < s.length(); i++)
	{
		operators.push(s[i]);
		operators.print_stack();
		operators.pop();
	}
	//operators.print_stack();
	//std::cout << result_string(s, operators) << std::endl;


	system("pause");
	return 0;
}
