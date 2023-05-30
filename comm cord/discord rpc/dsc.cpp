#include "dsc.h"
#include "Includes/discord_rpc.h"
#include "../files/xor.h"

void Discord::Initialize()
{
	DiscordEventHandlers Handle;
	memset(&Handle, 0, sizeof(Handle));
	Discord_Initialize(XorStr("1071492259633168534").c_str(), &Handle, 1, NULL);
}

void Discord::Update()
{
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.details = XorStr("made by x64 dbg").c_str();
	discordPresence.state = XorStr("In The Loader").c_str();
	discordPresence.startTimestamp = 0;
	discordPresence.largeImageKey = XorStr("Comm Cord Swoofer").c_str();

	discordPresence.partySize = 0;
	discordPresence.partyMax = 0;
	discordPresence.joinSecret = XorStr("https://discord.gg/commcord").c_str();
	Discord_UpdatePresence(&discordPresence);
}

void Discord::UpdateSpoofing()
{
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.details = XorStr("made by x64 dbg").c_str();
	discordPresence.state = XorStr("Spoofing!").c_str();
	discordPresence.startTimestamp = 0;
	discordPresence.largeImageKey = XorStr("Comm Cord Swoofer").c_str();

	discordPresence.partySize = 0;
	discordPresence.partyMax = 0;
	discordPresence.joinSecret = XorStr("https://discord.gg/commcord").c_str();
	Discord_UpdatePresence(&discordPresence);
}