// ==========================================================================
// Dedmonwakeen's Raid DPS/TPS Simulator.
// Send questions to natehieter@gmail.com
// ==========================================================================

#include "item_targetdata_initializer.hpp"

#include "item/item.hpp"
#include "player/sc_player.hpp"

item_targetdata_initializer_t::item_targetdata_initializer_t(unsigned iid, const std::vector<slot_e>& s) :
  item_id(iid), slots_(s)
{ }

item_targetdata_initializer_t::~item_targetdata_initializer_t() = default;

// Returns the special effect based on item id and slots to source from. Overridable if more
// esoteric functionality is needed

const special_effect_t* item_targetdata_initializer_t::find_effect(player_t * player) const
{
  // No need to check items on pets/enemies
  if (player->is_pet() || player->is_enemy() || player->type == HEALING_ENEMY)
  {
    return 0;
  }

  for (size_t i = 0; i < slots_.size(); ++i)
  {
    if (player->items[slots_[i]].parsed.data.id == item_id)
    {
      return player->items[slots_[i]].parsed.special_effects[0];
    }
  }

  return 0;
}
