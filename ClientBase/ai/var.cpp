﻿#include "var.h"
namespace script{	
	// 实现序列化
	bool Var::judgeNumber(const char *value)
	{
		if (*value == '-') value++;
		while (value && *value != '\0') 
		{
			if (*value == '.' || (*value >= '0' && *value <='9'))
                value++;
			else return false;
		}
		return true;
	}
	Var & Var::operator = (const Var &var)
	{
		this->value = var.value;
		this->name = var.name;
		this->type = var.type;
		return *this;
	}
	bool Var::operator < (const char *value)
	{
		return less(value);
	}
	bool Var::operator > (const char *value)
	{
		return great(value);
	}
	bool Var::operator <= (const char *value)
	{
		return lessequal(value);
	}
	bool Var::operator >= (const  char *value)
	{
		return greatequal(value);
	}
	bool Var::operator == (const char *value)
	{
		return equal(value);	
	}
	bool Var::operator != (const char *value)
	{
		return !equal(value);
	}
	Var & Var::operator = (const char *value)
	{
		set(value);
		return *this;
	}
	bool Var::isNumber()
	{
		if (!checkValid())
		{
			value="";
			return false;
		}
		return judgeNumber(value.c_str());
	}
	std::string Var::str()
	{
		if (checkValid()) return value;
		value="";
		return "";
	}
	bool Var::equal(const char *value)
	{
		if (!checkValid()) return false;
		return !strcmp(value,this->value.c_str());
	}
	void Var::add(const char *value)
	{
		checkValid();
		if (isNumber() && judgeNumber(value))
		{
			float d = atof(this->value.c_str());
			float s = atof(value);
			float r = d+s;
			char buf[25]={'\0'};
			gcvt(r,4,buf);
			this->value = buf;
		}
		else
		{
			this->value += value;
		}
	}
	void Var::minus(const char *value)
	{
		checkValid();
		if (isNumber() && judgeNumber(value))
		{
			float d = atof(this->value.c_str());
			float s = atof(value);
			float r = d - s;
			char buf[25]={'\0'};
			gcvt(r,4,buf);
			this->value = buf;
		}

	}
	void Var::div(const char *value)
	{
		checkValid();
		if (isNumber() && judgeNumber(value))
		{
			float d = atof(this->value.c_str());
			float s = atof(value);
			float r = 0;
			if (s) r = d / s;
			char buf[25]={'\0'};
			gcvt(r,4,buf);
			this->value = buf;
		}

	}
	void Var::mul(const char * value)
	{
		checkValid();
		if (isNumber() && judgeNumber(value))
		{
			float d = atof(this->value.c_str());
			float s = atof(value);
			float r = d * s;
			char buf[25]={'\0'};
			gcvt(r,4,buf);
			this->value = buf;
		}

	}
	bool Var::less(const char *value)
	{
		checkValid();
		if (isNumber() && judgeNumber(value))
		{
			float d = atof(this->value.c_str());
			float s = atof(value);
			return d < s;
		}
		return false;
	}
	bool Var::great(const char *value)
	{
		checkValid();
		if (isNumber() && judgeNumber(value))
		{
			float d = atof(this->value.c_str());
			float s = atof(value);
			return d > s;
		}
		return false;
	}
	bool Var::lessequal(const char *value)
	{
		checkValid();
		if (isNumber() && judgeNumber(value))
		{
			float d = atof(this->value.c_str());
			float s = atof(value);
			return d <= s;
		}
		return false;

	}
	bool Var::greatequal(const char *value)
	{
		checkValid();
		if (isNumber() && judgeNumber(value))
		{
			float d = atof(this->value.c_str());
			float s = atof(value);
			return d >= s;
		}
		return false;
	}
	void Var::set(const char *value)
	{
		checkValid();
		this->value = value;
	}
	Var::Var(const char*name,unsigned int value)
	{
		this->name = (name);
		char buf[25] = {'\0'};
		gcvt(value,4,buf);
		this->value = (buf);
		type = FOROVER;
	}
	Var::Var(const char *name,int value)
	{
		this->name = (name);
		char buf[25] = {'\0'};
		gcvt(value,4,buf);
		this->value = (buf);
		type = FOROVER;
	}
	Var::Var(const char *value)
	{
		this->value = (value);
	}
	Var::Var(){
		type = FOROVER;
	}
	void Var::init(unsigned char type)
	{
		this->type = type;
	}
	bool Var::checkValid()
	{
		return true;
	}
	double Var::number()
	{
		if (isNumber())
			return atof(this->value.c_str());
		return 0;
	}
};

