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

#ifndef __SCRIPT_CALLS_H
#define __SCRIPT_CALLS_H

#include "Common.h"
#include "ObjectMgr.h"

class Creature;
class CreatureAI;
class GameObject;
class Item;
class Player;
class Quest;
class SpellCastTargets;
class Map;
class InstanceData;

bool LoadScriptingModule(char const* libName = "");
void UnloadScriptingModule();

//On Event Handlers
typedef void(RIBON_IMPORT * scriptCallOnLogin) (Player *pPlayer);
typedef void(RIBON_IMPORT * scriptCallOnLogout) (Player *pPlayer);
typedef void(RIBON_IMPORT * scriptCallOnPVPKill) (Player *killer, Player *killed);

typedef void(RIBON_IMPORT * scriptCallScriptsInit) (char const*);
typedef void(RIBON_IMPORT * scriptCallScriptsFree) ();
typedef char const* (RIBON_IMPORT * scriptCallScriptsVersion) ();

typedef bool(RIBON_IMPORT * scriptCallGossipHello) (Player *player, Creature *_Creature );
typedef bool(RIBON_IMPORT * scriptCallQuestAccept) (Player *player, Creature *_Creature, Quest const *);
typedef bool(RIBON_IMPORT * scriptCallGossipSelect)(Player *player, Creature *_Creature, uint32 sender, uint32 action);
typedef bool(RIBON_IMPORT * scriptCallGossipSelectWithCode)( Player *player, Creature *_Creature, uint32 sender, uint32 action, const char* sCode );
typedef bool(RIBON_IMPORT * scriptCallGOSelect)(Player *player, GameObject *_GO, uint32 sender, uint32 action);
typedef bool(RIBON_IMPORT * scriptCallGOSelectWithCode)( Player *player, GameObject *_GO, uint32 sender, uint32 action, const char* sCode );
typedef bool(RIBON_IMPORT * scriptCallQuestSelect)( Player *player, Creature *_Creature, Quest const* );
typedef bool(RIBON_IMPORT * scriptCallQuestComplete)(Player *player, Creature *_Creature, Quest const*);
typedef uint32(RIBON_IMPORT * scriptCallNPCDialogStatus)( Player *player, Creature *_Creature);
typedef uint32(RIBON_IMPORT * scriptCallGODialogStatus)( Player *player, GameObject * _GO);
typedef bool(RIBON_IMPORT * scriptCallChooseReward)( Player *player, Creature *_Creature, Quest const*, uint32 opt );
typedef bool(RIBON_IMPORT * scriptCallItemHello)( Player *player, Item *, Quest const*);
typedef bool(RIBON_IMPORT * scriptCallGOHello)( Player *player, GameObject * );
typedef bool(RIBON_IMPORT * scriptCallAreaTrigger)( Player *player, AreaTriggerEntry const* );
typedef bool(RIBON_IMPORT * scriptCallItemQuestAccept)(Player *player, Item *, Quest const*);
typedef bool(RIBON_IMPORT * scriptCallGOQuestAccept)(Player *player, GameObject *, Quest const*);
typedef bool(RIBON_IMPORT * scriptCallGOChooseReward)(Player *player, GameObject *, Quest const*, uint32 opt );
typedef bool(RIBON_IMPORT * scriptCallItemUse) (Player *player, Item *_Item, SpellCastTargets const& targets);
typedef bool(RIBON_IMPORT * scriptCallItemExpire) (Player *player, ItemPrototype const *_ItemProto);
typedef bool(RIBON_IMPORT * scriptCallEffectDummyGameObj) (Unit *caster, uint32 spellId, uint32 effIndex, GameObject *gameObjTarget);
typedef bool(RIBON_IMPORT * scriptCallEffectDummyCreature) (Unit *caster, uint32 spellId, uint32 effIndex, Creature *crTarget);
typedef bool(RIBON_IMPORT * scriptCallEffectDummyItem) (Unit *caster, uint32 spellId, uint32 effIndex, Item *itemTarget);
typedef CreatureAI* (RIBON_IMPORT * scriptCallGetAI) ( Creature *_Creature );
typedef InstanceData* (RIBON_IMPORT * scriptCallCreateInstanceData) (Map *map);

typedef struct
{
    scriptCallScriptsInit ScriptsInit;
    scriptCallScriptsFree ScriptsFree;
    scriptCallScriptsVersion ScriptsVersion;

    scriptCallOnLogin OnLogin;
    scriptCallOnLogout OnLogout;
    scriptCallOnPVPKill OnPVPKill;

    scriptCallGossipHello GossipHello;
    scriptCallGOChooseReward GOChooseReward;
    scriptCallQuestAccept QuestAccept;
    scriptCallGossipSelect GossipSelect;
    scriptCallGossipSelectWithCode GossipSelectWithCode;
    scriptCallGOSelect GOSelect;
    scriptCallGOSelectWithCode GOSelectWithCode;
    scriptCallQuestSelect QuestSelect;
    scriptCallQuestComplete QuestComplete;
    scriptCallNPCDialogStatus NPCDialogStatus;
    scriptCallGODialogStatus GODialogStatus;
    scriptCallChooseReward ChooseReward;
    scriptCallItemHello ItemHello;
    scriptCallGOHello GOHello;
    scriptCallAreaTrigger scriptAreaTrigger;
    scriptCallItemQuestAccept ItemQuestAccept;
    scriptCallGOQuestAccept GOQuestAccept;
    scriptCallItemUse ItemUse;
    scriptCallItemExpire ItemExpire;
    scriptCallEffectDummyGameObj  EffectDummyGameObj;
    scriptCallEffectDummyCreature EffectDummyCreature;
    scriptCallEffectDummyItem     EffectDummyItem;
    scriptCallGetAI GetAI;
    scriptCallCreateInstanceData CreateInstanceData;

    RIBON_LIBRARY_HANDLE hScriptsLib;
}_ScriptSet,*ScriptsSet;

extern ScriptsSet Script;
#endif

