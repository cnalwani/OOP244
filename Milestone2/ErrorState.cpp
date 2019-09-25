/***********************************
* Name: CHIRAG ALWANI	
* Student ID: 153444179
* Date : 2018/07/22
***********************************/
#include <iostream>
#include <cstring>
#include <string>
#include "ErrorState.h"

using namespace std;
namespace AMA
{
	ErrorState::ErrorState(const char* _errorMess)
	{
		if (_errorMess == nullptr)
		{
			errorMessage = nullptr;
		}
		else
		{
			errorMessage = new char[strlen(_errorMess) + 1];
			strcpy(errorMessage, _errorMess);
		}
	}
	ErrorState::~ErrorState()
	{
		delete[] errorMessage;
		errorMessage = nullptr;

	}
	void ErrorState::clear()
	{
		if (this->errorMessage != nullptr)
		{
			errorMessage = nullptr;
		}
	}
	bool ErrorState::isClear() const
	{
		if (errorMessage == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void ErrorState::message(const char* str)
	{
		if (str == nullptr)
		{
			errorMessage = nullptr;
		}
		else
		{
			delete[] errorMessage;
			errorMessage = new char[strlen(str) + 1];
			strcpy(errorMessage, str);
		}
	}
	const char* ErrorState::message() const
	{
		return errorMessage;
	}
	std::ostream& operator<<(std::ostream& os, const ErrorState& em)
	{
		if (!em.isClear())
		{
			os << em.message();
		}
		return os;
	}
}