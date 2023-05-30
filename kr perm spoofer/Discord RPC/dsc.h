#pragma once
#include <Windows.h>
#include "Includes/discord_register.h"
#include "Includes/discord_rpc.h"

class Discord {
public:
	void Initialize();
	void Update();
	void UpdateSpoofing();
};