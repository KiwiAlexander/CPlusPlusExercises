#include "SpriteList.h"

SpriteList::SpriteList()
{
	head = nullptr;
}
void SpriteList::addSprite(Sprite^ newSprite) // checks if head is empty else assigns the new Sprite to the next value in tail and moves the tail to that value
{
	if (head == nullptr)
	{
		head = newSprite;
	}
	else
	{
		tail->Next = newSprite;
	}
	tail = newSprite;
}
void SpriteList::deleteOneSprite(Sprite^ SpriteToDelete) // if the head is the Sprite to delete it will delete the head and move the head along or it will cylce through Next pointers checking if they are the Sprite to delete if so it makes the next nodes next pointer the connecting one
{
	Sprite^ nodeWalker;
	nodeWalker = head;

	if (head == SpriteToDelete)
	{
		if (head == tail)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			head = nodeWalker->Next;
		}
	}
	else
	{
		while (nodeWalker->Next != SpriteToDelete)
		{
			nodeWalker = nodeWalker->Next;
		}
		nodeWalker->Next = SpriteToDelete->Next;
		if (SpriteToDelete == tail)
		{
			tail = nodeWalker;
		}
	}
}
void SpriteList::deleteAllDeadSprites() // cylces through all pallets and checks alive and if not passes into deleteOneSprite method
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		if (nodeWalker->isAlive == false)
		{
			deleteOneSprite(nodeWalker);
		}
		nodeWalker = nodeWalker->Next;
	}
}
void SpriteList::moveSprites() // checks if pointer is empty if not cylces through all the Sprites while moving them
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		nodeWalker->Move();
		nodeWalker = nodeWalker->Next;
	}
}
void SpriteList::drawSprites() // checks if pointer is empty if not cylces through all the Sprites while drawing them
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{

		nodeWalker->Draw();
		nodeWalker = nodeWalker->Next;
	}
}
int SpriteList::countSprites() // checks if pointer is empty if not cylces through all the Sprites while counting them
{
	Sprite^ nodeWalker = head;
	int count = 0;
	while (nodeWalker != nullptr)
	{
		count = count + 1;
		nodeWalker = nodeWalker->Next;
	}
	return count;
}
void SpriteList::wanderSprites()
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		nodeWalker->Wander();
		nodeWalker = nodeWalker->Next;
	}
}
void SpriteList::updateSprites()
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		nodeWalker->UpdateFrame();
		nodeWalker = nodeWalker->Next;
	}
}
Sprite^ SpriteList::checkCollectionSprites(Sprite^ otherSprite)
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		bool collision = nodeWalker->CheckCollisionBox(otherSprite);
		if (collision == true)
		{
			return nodeWalker;
		}
		nodeWalker = nodeWalker->Next;
	}
	return nullptr;
}
