#pragma once
#include <utility>
#include <string.h>

namespace cLib
{
class String
{
public:
	String() 
	  :data_(new char[1]), len_(0)
	{
		*data_ = '\0';
	}
	String(char* str) 
	  :len_(strlen(str)), data_(new char[len_ + 1])
	{
		strcpy(data_, str);
	}
	String(const String& rhs) 
	  :len_(rhs.size()), data_(new char[len_ + 1])
	{
		strcpy(data_, rhs.c_str());
	}
	~String()
	{
		delete[] data_;
	}
	String& operator=(String rhs)
	{
		swap(rhs);
		return *this;
	}

	bool operator==(String rhs)
	{
		return !strcmp(data_, rhs.c_str());
	}
	size_t size() const
	{
		return len_;
	}

	void swap(String& rhs)
	{
		std::swap(data_, rhs.data_);
		std::swap(len_, rhs.len_);
	}
	
	const char* c_str() const
	{
		return data_;
	}

private:
	size_t len_;
	char* data_;
	
};

	
}
