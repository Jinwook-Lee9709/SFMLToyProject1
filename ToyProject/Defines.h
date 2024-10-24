#pragma once

enum class SceneIds
{
	None = -1,
	Dev1,
	Battle,
	Dev2,
	Count,
};

enum class Origins
{
	TL, TC, TR, 
	ML, MC, MR, 
	BL, BC, BR,
	Custom
};

enum class Monsters
{
	Wolf,
	Tree,
	Golem,
};

enum class Cards
{
	Bash,
	Defend,
	Inflame,
	Strike
};

enum class Turn
{
	CardSelect,
	MonsterSelect,
	DiscardCard,
	MonsterTurn,
	RestoreCard,
	DrawCard,
};