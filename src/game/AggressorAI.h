/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Ribon <http://www.dark-resurrection.de/wowsp/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef RIBON_AGGRESSORAI_H
#define RIBON_AGGRESSORAI_H

#include "CreatureAI.h"
#include "CreatureAIImpl.h"

class Creature;

class RIBON_DLL_DECL AggressorAI : public CreatureAI
{
    public:
        explicit AggressorAI(Creature *c) : CreatureAI(c) {}

        void UpdateAI(const uint32);
        static int Permissible(const Creature *);
};

typedef std::vector<uint32> SpellVct;

class RIBON_DLL_SPEC SpellAI : public CreatureAI
{
    public:
        explicit SpellAI(Creature *c) : CreatureAI(c) {}

        void InitializeAI();
        void Reset();
        void EnterCombat(Unit* who);
        void JustDied(Unit *killer);
        void UpdateAI(const uint32 diff);
        static int Permissible(const Creature *);
    protected:
        EventMap events;
        SpellVct spells;
};

class RIBON_DLL_SPEC SpellCasterAI : public SpellAI
{
    public:
        explicit SpellCasterAI(Creature *c) : SpellAI(c) {m_attackDist = MELEE_RANGE;}
        void InitializeAI();
        void AttackStart(Unit * victim){SpellAI::AttackStartCaster(victim, m_attackDist);}
        void UpdateAI(const uint32 diff);
        void EnterCombat(Unit *who);
    private:
        float m_attackDist;
};

#endif