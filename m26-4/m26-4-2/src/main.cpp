#include <iostream>
#include <string>
#include <vector>;

class Number
{
private:
	std::string m_name;
	std::string m_number;
public:
	std::string get_name()
	{
		return m_name;
	}
	void set_name(std::string name)
	{
		m_name = name;
	}

	std::string get_number()
	{
		return m_number;
	}

	void set_number(std::string number)
	{
		m_number = number;
	}

};

class Phone
{
private:
	std::vector<Number> contacts;

	Number* find_contact(std::string keyword)
	{
		for (auto& contact : contacts)
		{
			if (contact.get_name() == keyword || contact.get_number() == keyword)
				return &contact;
		}
		return NULL;
	}

	void add()
	{
		std::cout << "New contact" << std::endl;
		std::string name;
		std::cout << "Name: ";
		std::cin >> name;

		std::cout << "Number: ";
		std::string number;
		std::cin >> number;
		if (number.length() == 12 && number[0] == '+')
		{
			Number num;
			num.set_name(name);
			num.set_number(number);
			contacts.push_back(num);
			std::cout << "Contact saved!" << std::endl;
		}
		else
		{
			std::cout << "Invalid number format" << std::endl;
			return;
		}
	}

	void call()
	{
		std::cout << "Call" << std::endl;

		std::string input;
		std::cout << "Number or name: ";
		std::cin >> input;

		if (find_contact(input) != NULL)
			std::cout << "CALL " << find_contact(input)->get_number() << std::endl;
		else
			std::cout << "Contact not found!" << std::endl;
	}

	void sms()
	{
		std::cout << "SMS" << std::endl;

		std::string input;
		std::cout << "Number or name: ";
		std::cin >> input;

		Number* contact = find_contact(input);

		if (contact != NULL)
		{
			std::cout << "Sms to " << contact->get_number() << " (" << contact->get_name() << ")" << std::endl;
			input = "";
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Message: ";
			std::getline(std::cin, input);
			std::cout << "Message sent!" << std::endl;
		}
		else
			std::cout << "Contact not found!" << std::endl;
			


	}

public:
	void on()
	{
		while (true)
		{
			std::cout << "Enter command: add, call, sms, exit" << std::endl;
			std::cout << ">>> ";
			std::string input;
			std::cin >> input;

			if (input == "exit")
				break;
			else if (input == "add")
				add();
			else if (input == "call")
				call();
			else if (input == "sms")
				sms();
			else
				std::cout << "Incorrect command" << std::endl;
			std::cin.clear();
		}
	}
};

int main()
{
	Phone phone;
	phone.on();
	delete& phone;

	return 0;
}