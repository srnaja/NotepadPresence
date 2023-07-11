#pragma once

#include <iostream>

#include "discord_register.h"
#include "discord_rpc.h"

class Discord {
public:
	Discord() { }
	~Discord() { }

	void Start();
	void Update();


private:
	DiscordRichPresence discordPresence;
	DiscordEventHandlers handlers;
};
