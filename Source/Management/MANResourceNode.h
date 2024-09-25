#pragma once

#include "MANObject.h"
#include <utility>

class MAN_API MANResourceNode final : public MANObject
{
public:
	MANResourceNode() = default;
	
	void Init(AActor* actor);

	//std::pair<double, double> GetPosition();
protected:


private:
	

};