#include "stack.cpp"
#include <string>


int get_element_priority(char element)
{
	switch (element) {
	case '(':
		return 1;
	case ')':
		return 2;
	case '=':
		return 3;
	case '+':
	case '-':
		return 4;
	case '*':
	case '/':
		return 5;
	case '^':
		return 6;
	default:
		return -1;
	}
}

float simple_calculating(float left_number, float right_number, char operation)
{
	switch (operation)
	{
	case '+': return left_number + right_number;
	case '-': return left_number - right_number;
	case '*': return left_number * right_number;
	case '/': if (right_number != 0) return left_number / right_number; else throw "Division by zero";
	default:
		throw "Unexpected operation";
	}
}

float calculate(std::string result_string)
{
	//function for calculating
	//return the result of expression

	std::string element = "";
	Stack<float> numbers;
	
	for (int i = 0; i < result_string.length(); i++)//for every element of the result string
	{
		while (result_string[i] != ' ')
		{
			element += result_string[i];
			i++;
		}
		if (element[0] >= '0' && element[0] <= '9')
		{
			numbers.push(std::stof(element));
			//numbers.print_stack();
		}
		else
		{
			float right_n = numbers.pop();
			float left_n = numbers.pop();
			char oper = element[0];
			numbers.push(simple_calculating(left_n, right_n, oper));
		}
		element = "";
	}
	return numbers.pop();
}

std::string result_string(std::string input_string)   
{
	//conversion from infix to postfix with spaces between the elements
	//returns string in postfix format for next step(calculating)

	std::string output_str = "", number = "";
	Stack<char> operators;

	for (int i = 0; i < input_string.length(); i++)//for every element of the input string
	{
		while(input_string[i] >= '0' && input_string[i] <= '9') //catches numbers for result string here
		{
			number += input_string[i];
			i++;
		}
		if (number.length() != 0)
		{
			output_str += number;
			output_str += ' ';
			number = "";
			i--;
		}
		else //cathes operators
		{
			if (operators.isEmpty())
			{
				operators.push(input_string[i]);
			}
			else
			{
				if (input_string[i] == ')')
				{
					while (operators.top() != '(')
					{
						output_str += operators.pop();
						output_str += ' ';
					}
					operators.pop();
				}
				else 
				{
					if ((get_element_priority(operators.top()) >= get_element_priority(input_string[i])) && (input_string[i] != '('))
					{
						
						output_str += operators.pop();
						output_str += ' ';
						operators.push(input_string[i]);
					}
					else
					{
						operators.push(input_string[i]);
					}
				}
			}
		}

		if (i == input_string.length()-1)//if some operators left in stack, we put them in the result string
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
	std::getline(std::cin, s);//gets the string
	s = result_string(s);
	std::cout << s << std::endl;
	std::cout << calculate(s) << std::endl;

	system("pause");
	return 0;
}