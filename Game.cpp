#include "Game.h"
#include "memory.h"
#include "offsets.h"

extern Memory apex;

bool Entity::isPlayer()
{
	uint64_t entName;
	apex.Read<uint64_t>(ptr + OFFSET_NAME, entName);

	if (entName) == 125780153691248 {
		return true;
	}
	else
	{
		return false;
	}
}

bool Entity::isItem()
{
	int EntItemID = 0;
	apex.Read<int>(ptr + OFFSET_ITEM_ID, EntItemID);
	if (EntItemID > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Entity::enableGlow(float R, float G, float B)
{
	apex.Write<int>(ptr + OFFSET_GLOW_ENABLE, 1);
	apex.Write<int>(ptr + OFFSET_GLOW_THROUGH_WALLS, 2);
	apex.Write<GlowMode>(ptr + GLOW_TYPE, { 101,102,46,96 });
	apex.Write<float>(ptr + GLOW_COLOR_R, R);
	apex.Write<float>(ptr + GLOW_COLOR_G, G);
	apex.Write<float>(ptr + GLOW_COLOR_B, B);
}

bool Entity::isGlowing()
{
	return false;
}

bool Entity::isGlowing()
{
	int glowState;
	apex.Read<int>(ptr + OFFSET_GLOW_ENABLE, glowState);
	if (glowState == 7)
	{
		return true;
	}
	else
	{

}

int Item::getItemID()
{
	int EntItemID = 0;
	apex.Read<int>(ptr + OFFSET_ITEM_ID, EntItemID);
	return EntItemID;
}

void Item::enableGlow(float R, float G, float B)
{
	apex.Write<int>(ptr + OFFSET_GLOW_ENABLE, 1);
	apex.Write<int>(ptr + OFFSET_GLOW_THROUGH_WALLS, 2);
	apex.Write<GlowMode>(ptr + GLOW_TYPE, { 101,102,46,96 });
	apex.Write<float>(ptr + GLOW_COLOR_R, R);
	apex.Write<float>(ptr + GLOW_COLOR_G, G);
	apex.Write<float>(ptr + GLOW_COLOR_B, B);
}

bool Item::isGlowing()
{
	int glowState;
	apex.Read<int>(ptr + OFFSET_GLOW_ENABLE, glowState);
	if (glowState == 7)
	{
		return true;
	}
	else
	{
		return false;
	}
}


Item ptrToItem(uintptr_t ptr)
{
	Item item = Item();
	item.ptr = ptr;
	return item;
}

Entity ptrToEntity(uintptr_t ptr)
{
	Entity ent = Entity();
	ent.ptr = ptr;
	return ent;
}
