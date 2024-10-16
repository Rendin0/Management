#pragma once

#include "MANObject.h"

class MAN_API MANStorage : private MANObject
{
public:
	virtual ~MANStorage() = default;
	void Init(AActor* actor);

	// Called on resurece send to object
	virtual bool SendRequest(const wchar_t* const& resourceName, const int& resourceQuantity) = 0;

	// Called on resource receive from object
	virtual bool ReceiveRequest(const wchar_t* const& resourceName, const int& resourceQuantity) = 0;

	void GetInventory(wchar_t*& buf);

protected:


private:

};