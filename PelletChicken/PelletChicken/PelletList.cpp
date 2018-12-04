#include "PelletList.h"

PelletList::PelletList()
{
	head = nullptr;
}
void PelletList::addPellet(Pellet^ newPellet) // checks if head is empty else assigns the new pellet to the next value in tail and moves the tail to that value
{
	if (head == nullptr)
	{
		head = newPellet;
	}
	else
	{
		tail->Next = newPellet;
	}
	tail = newPellet;
}
void PelletList::deleteOnePellet(Pellet^ pelletToDelete) // if the head is the pellet to delete it will delete the head and move the head along or it will cylce through Next pointers checking if they are the pellet to delete if so it makes the next nodes next pointer the connecting one
{
	Pellet^ nodeWalker;
	nodeWalker = head;

	if (head == pelletToDelete)
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
		while (nodeWalker->Next != pelletToDelete)
		{
			nodeWalker = nodeWalker->Next;
		}
		nodeWalker->Next = pelletToDelete->Next;
		if (pelletToDelete == tail)
		{
			tail = nodeWalker;
		}
	}
}
void PelletList::deleteAllDeadPellets() // cylces through all pallets and checks alive and if not passes into deleteOnePellet method
{
	Pellet^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		if (nodeWalker->isAlive == false)
		{
			deleteOnePellet(nodeWalker);
		}
		nodeWalker = nodeWalker->Next;
	}
}
void PelletList::movePellets() // checks if pointer is empty if not cylces through all the pellets while moving them
{
	Pellet^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		nodeWalker->move();
		nodeWalker = nodeWalker->Next;
	}
}
void PelletList::drawPellets() // checks if pointer is empty if not cylces through all the pellets while drawing them
{
	Pellet^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{

		nodeWalker->draw();
		nodeWalker = nodeWalker->Next;
	}
}
int PelletList::countPellets() // checks if pointer is empty if not cylces through all the pellets while counting them
{
	Pellet^ nodeWalker = head;
	int count = 0;
	while (nodeWalker != nullptr)
	{
		count = count + 1;
		nodeWalker = nodeWalker->Next;
	}
	return count;
}
