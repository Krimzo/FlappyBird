#include "player.h"


player::player()
{}

player::player(const std::string& name)
    : name(name)
{}

void player::phys_update(const float gravity, const float delta_t)
{
	velocity += gravity * delta_t;
	position += velocity * delta_t;
}

bool player::draw(const frame& frame, const size& frame_size) const
{
    if (const uint64_t index = (size_t) position * frame_size.width + frame_size.width / 4; position >= 0 && position < (float) frame_size.height && frame.data[index] != '#') {
        ((char*) frame.data.data())[index] = '@';
        return true;
    }
    return false;
}
