#include "RPN.hpp"

RPN::RPN(char* argv)
{
	setArgument(argv);
}

RPN::~RPN() {}

std::stack<int>	RPN::st_pushBack(std::stack<int> *st)
{
	std::stack<int> val;

	while (st->size())
	{
		val.push(st->top());
		st->pop();
	}
	return (val);
}

static int	applySign(char sign, std::stack<int> &st)
{
	int	val = 0;

	switch (sign)
	{
		case 43:
			{
				val = st.top();
				st.pop();
				val += st.top();
				st.pop();
				break;
			}
		case 45:
			{
				val = st.top();
				st.pop();
				val -= st.top();
				st.pop();
				break;
			}
		case 47:
			{
				val = st.top();
				st.pop();
				val /= st.top();
				st.pop();
				break;
			}
		case 42:
			{
				val = st.top();
				st.pop();
				val *= st.top();
				st.pop();
				break;
			}
		default:
			break;
	}
	return (val);
}

void	RPN::calculateValue ( std::stack<int>& stack )
{
	std::stack<int>	values;
	while ((int)stack.size() > 0)
	{
		if (stack.top() < 10)
		{
			values.push(stack.top());
			values = st_pushBack(&values);
			stack.pop();
		}
		else if (values.size() > 1)
		{
			values.push(applySign(stack.top(), values));
			stack.pop();
		}
		else
			throw (std::logic_error("Error: Invalid format"));
	}
	std::cout << "--> " << values.top() << std::endl;
}

bool	RPN::checkArgument(std::string argv)
{
	if (!argv.find_first_not_of(" 0123456789+-/*"))
	{
		std::cerr << "Error: Invalid Characters in argument!\n";
		return (false);
	}
	else
	{
		for (int i = 0; argv[i]; i++)
		{
			if (i % 2 == 0)
			{
				if (argv[i] != ' ' 
					&& (isdigit(argv[i])
					|| argv[i == '-']
					|| argv[i == '+']
					|| argv[i == '/']
					|| argv[i == '*']))
					continue;
				else
				{
					std::cerr << "Error: Invalid Characters in argument!\n";
					return (false);
				}
			}
			else if (argv[i] != ' ')
			{
				std::cerr << "Error: Invalid Characters in argument!\n";
				return (false);
			}
		}
	}
	return (true);
}

void	RPN::setArgument(char *argv)
{
	try
	{
		if (checkArgument(argv))
		{
			std::stack<int>	args;
			for (int i = static_cast<int>(strlen(argv)) - 1; i > -1; i--)
			{
				if (argv[i] != ' ')
				{
					if (argv[i] >= '*' && argv[i] <= '/')
						args.push((int)argv[i]);
					else
						args.push(argv[i] - '0');
				}
			}
			calculateValue(args);
		}
	}
	catch( const std::exception &e ){
		std::cerr << e.what() << '\n';
	}
}

