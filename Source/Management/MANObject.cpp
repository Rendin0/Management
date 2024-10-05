// Fill out your copyright notice in the Description page of Project Settings.


#include "MANObject.h"

void MANObject::SetBoundActor(AActor* actor)
{
	boundActor = actor;
}

AActor* MANObject::GetBoundActor() const
{
	return boundActor;
}

void MANObject::ConvertString(const std::wstring& str, const wchar_t*& buf)
{
	std::wstring out{};

	for (const auto& i : str)
	{
		out += UTF8_TO_TCHAR(&i);
	}

	buf = out.c_str();
}
