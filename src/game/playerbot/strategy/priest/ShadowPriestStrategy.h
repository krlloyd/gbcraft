#pragma once

#include "HealPriestStrategy.h"

namespace ai
{
    class ShadowPriestStrategy : public GenericPriestStrategy
    {
    public:
        ShadowPriestStrategy(PlayerbotAI* ai);

    public:
        virtual NextAction** getDefaultActions();
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "shadow"; }
        virtual StrategyType GetType() { return STRATEGY_TYPE_DPS; }
    };
}