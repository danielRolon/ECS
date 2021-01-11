#pragma once

enum class TypeEventArea
{
	NONE,
	INAREA,
	OUTAREA
};

struct AreaEvent
{
    int idEntity = -1;
    int idEntityCollide = -1;
    TypeEventArea typeEventArea = TypeEventArea::NONE;
};