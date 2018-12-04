#include "SpriteList.h"


//=====================================================================================
SpriteList::SpriteList(void)
{
	head = nullptr;
	tail = nullptr;
}

//=====================================================================================
void SpriteList::addSprite(SimpleSprite^ newSimpleSprite)
{
  if (head == nullptr) // this is the first node in the list
  {
    head = newSimpleSprite;
    tail = newSimpleSprite;
  }
  else  //add this node to the end of the list
  {
    tail->Next = newSimpleSprite;
    tail = newSimpleSprite;
  }
}
//=====================================================================================
void SpriteList::cycleSprites(SimpleSprite^ target)
{
	SimpleSprite^ nodeWalker;

	nodeWalker = head;

	while (nodeWalker != nullptr)
	{
		nodeWalker->orient(target);	// sprites that orient need to override the base class method
		nodeWalker->move();
		
		bool hitEdge = nodeWalker->ranIntoWorldEdge();
		if (hitEdge)
			nodeWalker->dealWithEdgeCollision();

		nodeWalker->updateFrame();
		nodeWalker->draw();

		nodeWalker = nodeWalker->Next;
	}
}

