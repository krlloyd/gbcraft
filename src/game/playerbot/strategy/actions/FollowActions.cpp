#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "FollowActions.h"
#include "../../PlayerbotAIConfig.h"
#include "../values/Formations.h"

using namespace ai;

bool FollowAction::Execute(Event event)
{
    Formation* formation = AI_VALUE(Formation*, "formation");
    string target = formation->GetTargetName();
    if (!target.empty())
    {
        return Follow(AI_VALUE(Unit*, target));
    }
    else
    {
        WorldLocation loc = formation->GetLocation();
        if (loc == WorldLocation::Null)
            return false;

        return MoveTo(loc.GetMapId(), loc.x, loc.y, loc.z);
    }
}

bool FollowAction::isUseful()
{
    Formation* formation = AI_VALUE(Formation*, "formation");
    float distance = 0;
    string target = formation->GetTargetName();

    if (!target.empty())
    {
        distance = AI_VALUE2(float, "distance", target);
    }
    else
    {
        WorldLocation loc = formation->GetLocation();
        if (loc == WorldLocation::Null || bot->GetMapId() != loc.GetMapId())
            return false;

        distance = bot->GetDistance(loc);
    }

    return distance > formation->GetMaxDistance() &&
            !AI_VALUE(bool, "can loot");
}
