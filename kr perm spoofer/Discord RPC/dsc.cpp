#include "dsc.h"
#include "../enc.h"
void Discord::Initialize()
{
	DiscordEventHandlers Handle;
	memset(&Handle, 0, sizeof(Handle));
	Discord_Initialize(E("1086389167996547133"), &Handle, 1, NULL);
}

void Discord::Update()
{
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.details = E("made by ud man");
	discordPresence.state = E("In The Loader");
	discordPresence.startTimestamp = 0;
	discordPresence.largeImageKey = E("Kr Swoofer");

	discordPresence.partySize = 0;
	discordPresence.partyMax = 0;
	discordPresence.joinSecret = E("https://discord.gg/krservice");
	Discord_UpdatePresence(&discordPresence);
}

void Discord::UpdateSpoofing()
{
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.details = E("made by ud man");
	discordPresence.state = E("Spoofing!");
	discordPresence.startTimestamp = 0;
	discordPresence.largeImageKey = E("Kr Swoofer");

	discordPresence.partySize = 0;
	discordPresence.partyMax = 0;
	discordPresence.joinSecret = E("https://discord.gg/krservice");
	Discord_UpdatePresence(&discordPresence);
}