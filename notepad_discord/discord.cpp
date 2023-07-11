#include "discord.h"

void Error(int errorCode, const char* message) {
    
}

void Ready(const DiscordUser* request) {
}

void Discord::Start() {
    memset(&handlers, 0x0, sizeof(handlers));

    handlers.ready = Ready;
    handlers.errored = Error;

    Discord_Initialize("1128299947415060510", &handlers, 1, NULL);
}

void Discord::Update() {
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.state = "Programador";
    discordPresence.details = "Competitive";
    discordPresence.largeImageKey = "notepad_plus_plus_1_";
    discordPresence.smallImageText = "Rogue - Level 100";
    discordPresence.partyId = "ae488379-351d-4a4f-ad32-2b9b01c91657";
    discordPresence.joinSecret = "MTI4NzM0OjFpMmhuZToxMjMxMjM= ";
    Discord_UpdatePresence(&discordPresence);
}