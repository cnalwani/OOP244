/************************************
* Name: CHIRAG ALWANI
* Student ID: 153444179
* Date : 2018/07/22
***********************************/
#ifndef NAMESPACE_ERRORSTATE_H_
#define NAMESPACE_ERRORSTATE_H_

#include <iostream>

namespace AMA
{
	class ErrorState {

		 char* errorMessage;
	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& em) = delete;
		ErrorState& operator=(const ErrorState& em) = delete;
		virtual ~ErrorState();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message()const;
	};
	std::ostream& operator<<(std::ostream& os, const ErrorState& em);
}


#endif // !NAMESPACE_ERRORSTATE_H
