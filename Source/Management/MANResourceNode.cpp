#include "MANResourceNode.h"


void MANResourceNode::Init(AActor* actor)
{
	SetBoundActor(actor);
}

//std::pair<double, double> MANResourceNode::GetPosition()
//{
//	std::pair<double, double> pos{};
//
//	//if (boundActor)
//	//	pos = Cast<AResourceNode>(boundActor)->GetPosition();
//
//	return pos;
//}
