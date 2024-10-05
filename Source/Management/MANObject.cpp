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

const wchar_t* MANObject::ConvertString(const std::wstring& str)
{
	std::wstring out{};

	for (const auto& i : str)
	{
		out += UTF8_TO_TCHAR(&i);
	}

	return out.c_str();
}
